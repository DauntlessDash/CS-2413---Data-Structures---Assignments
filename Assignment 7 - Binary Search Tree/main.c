#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <wchar.h>
#include "bst.h"

int main(int argc, char ** argv){
   int k=0;
   int n;
   char command[100];
   tree* t = createBST();
   node* input;

   
   while(k==0){
	 scanf("%s", command);
	        if(strcmp(command, "insert") == 0)
	            {
	               scanf("%d",  &n);
	               input=createnode(n);
	               insertnode(t, input);
                 }
	        else if(strcmp(command, "remove") == 0)
                {
                    if(t->root == NULL){
                        printf("Tree Is Empty \n");
                    }
                   
                    else{
                    scanf("%d",  &n);
                    removenode(t, n);
                    }
                 }
                 
            else if(strcmp(command, "postorder") == 0)
                {
                    if(t->root == NULL){
                        printf("Tree Is Empty \n");
                    }
                    else{
	                    postorder(t);
	                    printf("\n");
                    }
                 }
            else if(strcmp(command, "preorder") == 0)
                {
                   if(t->root == NULL){
                        printf("Tree Is Empty \n");
                    }
                    else{
	                    preorder(t);
	                    printf("\n");
                    }
                 }
            else if(strcmp(command, "inorder") == 0)
                {
                   if(t->root == NULL){
                        printf("Tree Is Empty \n");
                    }
                    else{
	                    inorder(t);
	                    printf("\n");
                    }
                 }
            else if(strcmp(command, "calculate") == 0)
                {
                  if(t->root == NULL){
                        printf("Tree Is Empty \n");
                    }
                    else{
	                    n=calculate(t);
	                    printf("%d\n", n);
                    }
                 }
            else if(strcmp(command, "clear") == 0)
                {
                   clear(t);
                 }
     }
	return 0;
}