#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "calc.h"

int main(int argc, char ** argv){
   
    int temp;
	char command[100];
	
	while(scanf("%s", command)> 0)
	{
	        if(strcmp(command, "clear") == 0)
	        {
	            clear();
	        }
	        else {
	        scanf("%d", &temp);
	        
	        if(strcmp(command, "add") == 0)
                {
                    add(temp);
                 }
            else if(strcmp(command, "subtract") == 0)
                {
                   subtract(temp);
                 }
            else if(strcmp(command, "divide") == 0)
                {
                    divide(temp);
                 }
            else if(strcmp(command, "multiply") == 0)
                {
                     multiply(temp);
                 }
            else if(strcmp(command, "mod") == 0)
                {
                     mod(temp);
                 }
	        }
	}
	return 0;
}