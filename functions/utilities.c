#include <stdlib.h>
#include <stdio.h>
#include "utilities.h"


/*Checks the length of the input string						*/
/*Returns the number of characters minus the null terminator*/
int string_length(char *input)
{
	int count = 0;
	while(input[count] != '\0'){
		count++;								/*Keep incrementing counter until \0*/
	}
	
	return count;
}