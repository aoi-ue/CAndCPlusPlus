#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <math.h> 

// open file, read selected file, convert, create text file 
char* openFile(char* fileName)  {
    int i = 0; 
    FILE* inputFile = NULL; 
	int fileLength = 0;

   if((inputFile = fopen(fileName,"r")) == NULL)
   {
      printf("Error!");   
      exit(1);             
   } 
   
    printf("file exists, printing new file..\n");
    fseek(inputFile, 0, SEEK_END); /* Goes to the end */
    fileLength = ftell(inputFile); /* Gives us the current position in file*/
    fseek(inputFile, 0, SEEK_SET); /* Goes to the start */

    char* plainText = malloc(sizeof(char) * fileLength + 1); 
    printf("Length of the file is %d bytes\n", fileLength);

    do
    {   
        plainText[i] = fgetc(inputFile); 
        i++; 
    }
    
    while(!feof(inputFile)); 

    i--; 

    plainText[i] = '\0'; 

    fclose(inputFile);
    return plainText; 
}


char* encrypt(char* input) {
    int sides; 
    int i = 0; 
    int len = strlen(input); 

    for (sides = 1; (sides * sides) < len; sides++); 

    char* ct = (char*) malloc(sizeof(char*) * (sides *sides) + 1); 

    for (i ; i < len; i++ ) {
        ct[(i%sides)*sides + i/sides] = input[i]; 
    }

    for (int j = 0; j < (sides*sides)-len; j++) {
        ct[(i%sides)*sides + i/sides] = input[len - 1]; 
        i++; 
    }
    return ct; 
}

void writeFile(char* input, char* fileName) {
    FILE *fp;
    int i = 0; 

    fp = fopen(fileName, "w");

    printf("%d", strlen(input));

    for (int i = 0; i < strlen(input); ++i) { 
        fputc(input[i], fp); 
    }

    fclose(fp); 
}
  

int main(int argc, char* argv[]) {

	if (argc != 4) {
        printf("Usage: %s <-Mode:string> <InputFilePath:string> <OutputFilePath:string>", argv[0]); 
        return 0; 
    } 

    char* inputText; 
    inputText = openFile(argv[2]); 

    char* encryptCipherText; 
    encryptCipherText = encrypt(inputText);

    writeFile(encryptCipherText, argv[3]); 

    free(encryptCipherText);

}





// int PrintArray(char *input, int gridsizesq) {
//     int i,j,row,col;
//     int gsize = sqrt(gridsizesq);
//     char grid[4][4];
//     char temp;
//     int index = 0;

//     while(temp != '\0')
//     {
//         temp = input[index];
//         grid[index][4] = temp;
//         ++index;
//     }

//     for (i = 0; i < row; i++) {
//         for (j = 0; j < col; j++) {
//             printf("%c ", grid[i][j]);
//         }
//         printf("%c ", grid[j][i]);
//         printf("\n");
//     }
//     return 0;
// }