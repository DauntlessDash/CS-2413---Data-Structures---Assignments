#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <wchar.h>
#include "map.h"

int main(int argc, char ** argv){
   int k=0;
   int n;
   char command[100];
   entry input;
   map* m = createMap();
   value* z;
   
   while(k==0){
    clearToken(& (input.k));
	 scanf("%s", command);
	        if(strcmp(command, "Define") == 0)
	            {
	               scanf("%s %s",  input.k.text, input.v.text);
	               printf("Define Key:%s Value:%s\n", input.k.text, input.v.text);
	               define(m, input.k, input.v);
	               
                 }
	        else if(strcmp(command, "Delete") == 0)
                {
                   scanf("%s",  input.k.text);
	               printf("Delete Key:%s\n", input.k.text);
	               Delete(m, input.k);
                 }
                 
            else if(strcmp(command, "Lookup") == 0)
                {
                    scanf("%s",  input.k.text);
                    printf("Lookup Key:%s\n", input.k.text);
                    z=lookup(m, input.k);
                    if(z==NULL){
                        printf("No Value Found For Key:%s\n", input.k.text);}
                    else{
                        ("Found Value:%s\n", z->text);

                    }
                 }
                 
     }
	return 0;
}