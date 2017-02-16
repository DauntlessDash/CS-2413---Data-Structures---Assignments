#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <wchar.h>
#include "queue.h"

int main(int argc, char ** argv){
   
    int temp, temptwo;
    int n;
	char command[100];
	stack a;
	a = createQueue();
	
	while(scanf("%s", command)> 0)
	{
	        if(strcmp(command, "enqueue") == 0)
	            {
	                scanf("%d %d", &temp, &temptwo);
	                
                    enqueue(a, temp);
                    printf("Enqueued %d \n", temp);
                    while(temp != temptwo)
                    {
                        temp++;
                        enqueue(a, temp);
                        printf("Enqueued %d \n", temp);
                    }
                 }
	        else if(strcmp(command, "dequeue") == 0)
                {
                    scanf("%d", &temp);
                    n = 0;
                    while(n != temp){
                        
                        if(isEmpty(a))
                        {
                           printf("Queue Is Empty\n");
                        
                        }
                        else
                        {  
                            temptwo=dequeue(a);
                            printf("Dequeued %d \n", temptwo);
                        }
                        n++;
                    }
                 }
            else if(strcmp(command, "peek") == 0)
                {
                    if(isEmpty(a))
                    {
                        printf("Queue Is Empty\n");
                        
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
                        printf("Queue Is Empty\n");
                        
                    }
                    else
                    {
                        display(a);
                    }
                 }
	        
	}
	destroyQueue(a);
	return 0;
}