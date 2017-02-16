#include "stdheader.h"
#include "stack.h"

int main(int argc, char ** argv){
   
    int temp;
	char command[100];
	stack a;
	a = newstack();
	
	while(scanf("%s", command)> 0)
	{
	        if(strcmp(command, "push") == 0)
	            {
	                scanf("%d", &temp);
                    push(a, temp);
                    printf("Pushed %d \n", temp);
                 }
	        else if(strcmp(command, "pop") == 0)
                {
                    if(isEmpty(a))
                    {
                        printf("Stack is Empty\n");
                        
                    }
                    else
                    {
                        temp = pop(a);
                        printf("Popped %d \n", temp);
                    }
                 }
            else if(strcmp(command, "peek") == 0)
                {
                    if(isEmpty(a))
                    {
                        printf("Stack is Empty\n");
                        
                    }
                    else
                    {
                        temp = peek(a);
                        printf("Peeked %d \n", temp);
                    }
                 }
            else if(strcmp(command, "display") == 0)
                {
                    if(isEmpty(a))
                    {
                        printf("Stack is Empty\n");
                        
                    }
                    else
                    {
                        display(a);
                    }
                 }
	        
	}
	deletestack(a);
	return 0;
}