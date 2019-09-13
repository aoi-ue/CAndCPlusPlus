/*---------------------------------------------------------------

Student: Daniel Lim
Filename: Calculator.c
Email: daniel.l@digipen.edu
Date: 10th Sep 2019
Description: A basic calculator for integers written in C. 
-----------------------------------------------------------------*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>





int isNumber(char ch)
{
	//checks whether character is a number
	
	
	if(ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6'
			|| ch == '7' || ch == '8' || ch == '9' || ch == '0' )
			
	{
				
		return 1;
				
	}
			
	else
			
	{
		return 0;
		
	}
	
	
}

int num_of_integers(char* str )
{

	//gets number of integers in string
	
	

	int i = 0;
	
	int j = 0;

	while (*(str + i) != '\0' && *(str + i) != '+' && *(str + i) != '-' 
			&& *(str + i) != '*' && *(str + i) != '/' )
	{
		
			
		
		if(*(str + i) == '1' || *(str + i) == '2' || *(str + i) == '3' || *(str + i) == '4' || *(str + i) == '5' || *(str + i) == '6'
			|| *(str + i) == '7' || *(str + i) == '8' || *(str + i) == '9' || *(str + i) == '0' )
		{
			
			++j;
			
			
		}
		
		else
		{
			
			printf("invalid_string_error_type_1 return 0 \n");
			
			return 0;
		}
			
		
		++i;
							

	}

	return j;
	
}


int power(int x, int n)
{
	
	//returns power of integer
	
	
	int result = 1.0;

	for (int i = 1; i <= n; ++i)
	{
		result = result*x;
	}
	
	

	return result;
	
	
}


int extract_number(char *ptr)
{
	
	//takes a string and extracts number

	int current = 0;

	int final_value = 0;

	int position = num_of_integers(ptr)-1;

	

	while (*(ptr) && *(ptr) != '\0' && *(ptr) != '+' && *(ptr) != '-' 
	&& *(ptr) != '*' && *(ptr) != '/'  )
	
	{
		if (*ptr == '0')
		{
			current = 0;
		}

		else if (*ptr == '1')
		{
			current = 1;
		}

		else if (*ptr == '2')
		{
			current = 2;
		}

		else if (*ptr == '3')
		{
			current = 3;
		}

		else if (*ptr == '4')
		{
			current = 4;
		}

		else if (*ptr == '5')
		{
			current = 5;
		}

		else if (*ptr == '6')
		{
			current = 6;
		}

		else if (*ptr == '7')
		{
			current = 7;
		}

		else if (*ptr == '8')
		{
			current = 8;
		}

		else if (*ptr == '9')
		{
			current = 9;
		}
		
		else
		{
			printf("invalid_string_error_type_2 return 0 \n ");
			
			return 0;
			
			
		}

		final_value = final_value + current * power(10, position);
		
		//cout << final_value << endl;


		ptr++;
		position--;
		

	}

	return final_value;

}


int calculator (char* ptr)
{

	//implements calculator function.
		
		int i = 0;
		
		int pair[2];
		
		pair[0] = 0;
		
		pair[1] = 0;
		
		char sign = '0';
		
		
		if(isNumber(*(ptr+i)) == 1)
			
		{
			
			pair[0] = extract_number(ptr + i);
			
			i = i + num_of_integers(ptr + i);
			
			sign = *(ptr + i);
			
			++i;
			
		}
		
		else
		{
			printf("invalid_string_error_type_3 return 0 \n  \n");
			
			return 0;
			
		}
		
		while ( *(ptr + i) != '\0' && i < strlen(ptr))
			
		{	
			
			if(isNumber(*(ptr+i)) == 1)
			{
				
				pair[1] = extract_number(ptr + i);
			
			}
			
			else
			{
				printf("invalid_string_error_type_4 return 0 \n");
			
				return 0;
				
			}
		
		
			if(sign == '+')
			{
				
				pair[0] = pair[0] + pair[1];
		
			}
		
			else if (sign == '-')
			{
				pair[0] = pair[0] - pair[1];
			
			}
		
			else if (sign == '*')
			{
				pair[0] = pair[0] * pair[1];
			
			}
		
			else if (sign == '/')
			{
				pair[0] = pair[0] / pair[1];
			
			}
		
			else
			{
				printf("invalid_string_error_type_5 return 0 \n");
			
				return 0;
			
			}
			
			i = i + num_of_integers(ptr + i);
			
			sign = *(ptr + i);
			
			++i;
			
		}
		
		return pair[0];
		

}




int main(int argc, char *argv[])
{
	
	
	
	if(argc != 2 )
	{
		
		printf("error, more than one argument or no argument");
		
		return (0);
		
	}
	
	int a = calculator(argv[1]);
	
	
	
	printf("%d", a);
	
	
	

	return (0);



}