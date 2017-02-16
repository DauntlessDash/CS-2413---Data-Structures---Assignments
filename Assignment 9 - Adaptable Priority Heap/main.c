#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <wchar.h>
#include "queue.h"

int main(int argc, char ** argv){
   
    element temp;
    int priority;
    int pos; //position used for accessing handles
	char command[100];
	que *q = createQueue();
	handle * handles[101];
	int handnum = 0;
	
	while(scanf("%s", command)> 0)
	{
	        if(strcmp(command, "enqueue") == 0)
	            {
	                scanf("%s %s %d", temp.first, temp.last, &priority);
	                printf("Enqueue of %s %s with priority %d \n", temp.first, temp.last, priority);
	                handnum++;
                    handles[handnum]=enqueue(q, temp, priority);
                    
                   
                 }
	       else if(strcmp(command, "update") == 0)
                {
                    scanf("%d %d", &pos, &priority);
                    printf("Updating %d with priority %d \n", pos, priority);
                    update(q, handles[pos], priority);
                    
                 }
            else if(strcmp(command, "dequeue") == 0)
                {
                    if(isEmpty(q) == 1){
                        printf("Queue Is Empty");
                    }
                    else{
                         printf("Dequeue \n");
                         temp = dequeue(q);
                         printf("Dequeue of %s %s \n", temp.first, temp.last);
                    }
                 }
	        
	}
	return 0;
}