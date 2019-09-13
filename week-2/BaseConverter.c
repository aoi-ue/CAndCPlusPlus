/******************************************************************************
filename BaseConverter.c
author Lian Yuhan
email yuhan.lian@digipen.edu
date created 13 Sep 2019
Brief Description: Converts to data format as requested in C
******************************************************************************/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h>

int main(int argc, char *argv[]) {
    char* selected; 
    int input = atoi(argv[2]); 

    if (argc !=3) printf("Invalid usage: BaseConverter.exe <Mode:string> input <IntegerValue:int>\n");

    if (argc == 3) {
        selected = argv[1]; 

        // for dtob 
        if (strcmp(selected, "-dtob") == 0){    
            int binaryNumber = 0, remainder, i = 1, step = 1;  

            while (input!=0) {
                remainder = input%2;
                input /= 2;
                step++;
                binaryNumber += remainder*i;
                i *= 10;
            }
            printf ("%d",binaryNumber);
        }

        // for btod
        else if (strcmp(selected, "-btod") == 0){
            int decimalNumber = 0, i = 0, remainder;
            while (input!=0)
            {
                remainder = input%10;
                input /= 10;
                decimalNumber += remainder*pow(2,i);
                ++i;
            }
            printf("%d", decimalNumber);
        }   

        // for dtoh
        else if (strcmp(selected, "-dtoh") == 0){
            int i = 1, j, temp;
            char hexadecimalNumber[100];

            while(input!=0){
                temp = input % 16;
            //To convert integer into character
            if (temp < 10) {
                temp = temp + 48;
            }
            else {
                temp = temp + 55;
            }

            hexadecimalNumber[i++]= temp;
            input = input / 16;
            }   
            for(j = i -1 ;j > 0;j--) {
                printf("%c",hexadecimalNumber[j]);
            }
        }

        // for htod
        else if (strcmp(selected, "-htod") == 0){
            int decimalNumber = 0, i = 0, remainder;
            while(input > 0)
            {
                remainder = input % 10;
                decimalNumber += remainder * pow(16, i);
                input /= 10;
                i++;
            }  
            printf("%d", decimalNumber);     
        }  

        // for htob (h -> d -> b)
        else if (strcmp(selected, "-htob") == 0){
            int decimalNumber = 0, i = 0, remainder;
            int binaryNumber = 0, remainder2, j = 1, step = 1; 
            while(input > 0)
            {
                remainder = input % 10;
                decimalNumber += remainder * pow(16, i);
                input /= 10;
                i++;
            }
             
            while (decimalNumber!=0) {
                remainder2 = decimalNumber%2;
                decimalNumber /= 2;
                step++;
                binaryNumber += remainder2*j;
                j *= 10;
            }
            printf ("%d\n",binaryNumber);
        }       
             
        // for btoh
        else if (strcmp(selected, "-btoh") == 0){
            int decimalNumber = 0, i = 0, remainder;
            int k = 1, j, temp;
            char hexadecimalNumber[100];
            while (input!=0)
            {
                remainder = input%10;
                input /= 10;
                decimalNumber += remainder*pow(2,i);
                ++i;
            }

            while(decimalNumber!=0){
                temp = decimalNumber % 16;
            //To convert integer into character
            if (temp < 10) {
                temp = temp + 48;
            }
            else {
                temp = temp + 55;
            }
            hexadecimalNumber[k++]= temp;
            decimalNumber = decimalNumber / 16;
            }   
            for(j = i -1 ;j> 0;j--) {
                printf("%c",hexadecimalNumber[j]);
            }                       
        }       

        else {
            printf("please include correctly");
        }
    }    
    return 0; 
}