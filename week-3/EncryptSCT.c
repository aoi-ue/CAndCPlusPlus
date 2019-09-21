/******************************************************************************
filename EncryptSCT.c
author Lian Yuhan
email yuhan.lian@digipen.edu
date created 20 Sep 2019
Brief Description: A code to decrypt a text file and output another file
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// open file, read selected file, convert, create text file
char *openFile(char *fileName)
{
	int i = 0;
	FILE *inputFile = NULL;
	int fileLength = 0;

	if ((inputFile = fopen(fileName, "r")) == NULL)
	{
		printf("Error!");
		exit(1);
	}

	fseek(inputFile, 0, SEEK_END); /* Goes to the end */
	fileLength = ftell(inputFile); /* Gives us the current position in file*/
	fseek(inputFile, 0, SEEK_SET); /* Goes to the start */

	char *plainText = malloc(sizeof(char) * fileLength + 1);

	do
	{
		plainText[i] = fgetc(inputFile);
		i++;
	}

	while (!feof(inputFile));

	i--;

	plainText[i] = '\0';

	fclose(inputFile);
	return plainText;
}

char *encrypt(char *input)
{
	int sides;
	int i, j;
	int len = strlen(input);

	for (sides = 1; (sides * sides) < len; sides++);

	char *ct = (char *)malloc(sizeof(char *) * (sides * sides) + 1);

	for (i = 0; i < len; i++)
	{
		ct[(i % sides) * sides + i / sides] = input[i];
	}

	for (j = 0; j < (sides * sides) - len; j++)
	{
		ct[(i % sides) * sides + i / sides] = input[len - 1];
		i++;
	}
	return ct;
}

void writeFile(char *input, char *fileName)
{
	FILE *fp;
	int i;
	int len = strlen(input);

	fp = fopen(fileName, "w");

	for (i = 0; i < len; ++i)
	{
		fputc(input[i], fp);
	}

	fclose(fp);
}

int main(int argc, char *argv[])
{

	if (argc != 4)
	{
		printf("Usage: %s <-Mode:string> <InputFilePath:string> <OutputFilePath:string>", argv[0]);
		return 0;
	}

	char *inputText;
	inputText = openFile(argv[2]);

	char *encryptCipherText;
	encryptCipherText = encrypt(inputText);

	writeFile(encryptCipherText, argv[3]);

	free(encryptCipherText);
}
