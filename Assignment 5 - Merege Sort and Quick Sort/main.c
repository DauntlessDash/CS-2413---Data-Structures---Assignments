#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <wchar.h>
#include "dll.h"
#include "sort.h"

int main(int argc, char ** argv){
   
    int num, i, temp;
    int k = 0;
    int input[100];
    int n;
	char command[100];
	stack a;

	while(k==0){
	 a = createQueue();
     scanf("%d", &num);
     if(num>0){
     i = 0;
     while(i!=num)
     {
         scanf("%d", &input[i]);
         i++;
     }
      i=0;
      while(i!=num)
     {
         add(a, input[i]);
         i++;
     }
     display(a);
     i=0;
	 scanf("%s", command);
	        if(strcmp(command, "mergesort") == 0)
	            {
	                mergesort(a);
	                display(a);
                 }
	        else if(strcmp(command, "quicksort") == 0)
                {
                    quicksort(a);
                    display(a);
                 }
                 
     }
     else{
         scanf("%s", command);
	        if(strcmp(command, "mergesort") == 0)
	            {
	                mergesort(a);
	               
                 }
	        else if(strcmp(command, "quicksort") == 0)
                {
                    quicksort(a);
                    
                 }
     }
	destroyQueue(a);
	}
	return 0;
}