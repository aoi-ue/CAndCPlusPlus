/******************************************************************************
filename funcptr.c
author Howard Sin
email howard.sin@digipen.edu
date created 11 June 2019
Brief Description: A simple demo for function pointers & programmable remotes
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef void (*ButtonFunc)(void);

void Quit()
{
	printf("Quit\n");
	exit(0);
}

void DoNothing()
{
	printf("Doing Nothing...\n");
}

void OpenNetflix()
{
	printf("Opening Netflix\n");
}

void GoToChannel5()
{
	printf("Going to Channel 5\n");
}

void GoToChannel8()
{
	printf("Going to Channel 8\n");
}

ButtonFunc GetFunctionByIndex(int i)
{
	switch(i)
	{
	case 0:
		return Quit;
	case 1:
		return OpenNetflix;
	case 2:
		return GoToChannel5;
	case 3:
		return GoToChannel8;
	default:
		return DoNothing;
	}
}

const int NUM_BUTTONS = 3;

int main(int argc, char* argv[])
{
	int i = 0;
	int inputBuffer = 0;
	void (*buttonFunc[NUM_BUTTONS])(void);
	printf("Setting up your programmable remote:\n");
	while (i < NUM_BUTTONS)
	{
		printf("What do you want button %d to do?:", i);
		scanf("%d", &inputBuffer);
		buttonFunc[i] = GetFunctionByIndex(inputBuffer);
		++i;
	}
	
	while(1)
	{
		printf("Which button to press? ");
		scanf("%d", &inputBuffer);
		if (inputBuffer >= NUM_BUTTONS)
			break;
		
		(*buttonFunc[inputBuffer])();
	}
	
	printf("Bye bye!");
	return 0;
}