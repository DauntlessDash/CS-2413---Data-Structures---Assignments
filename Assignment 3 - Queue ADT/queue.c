#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <wchar.h>


stack createQueue(){
    stack s = (stack)malloc(sizeof(stack_type));
    s->head=NULL;
    s->tail=NULL;
    return s;
}

void destroyQueue(stack s){
    node temp;
    while(s->head){
        temp = s->head;
        s->head = s->head->next;
        free(temp);
    }
    free(s);
}

void enqueue(stack s, element e)
{
    node n = (node)malloc(sizeof(node_type));
    if(s->tail == NULL || s->head == NULL){
      s->tail = n;
      s->head = n;
       n->e=e;
       return;
    }
    n->e=e;
    (s->tail)->next = n;
    n->prev = s->tail;
    s->tail = n;
}

isEmpty(stack s){
    if(s->head==NULL)
    { return 1;}
    return 0;
}
element dequeue(stack s){
    node temp = s->head->next;
    element e = s->head->e;
    free(s->head);
    s->head=temp;
    return e;
}

element peek(stack s)
{
   element e = s->head->e;
   return e;
}

void display(stack s)
{
    printf("Display In Reverse\n");
    if(s->head == s->tail){
        printf("%d \n",s->head->e);
        return;
    }
    node temp;
    temp=s->tail;
    while(temp->prev!=s->head)
    {
    printf("%d \n",temp->e);
    temp=temp->prev;
    }
    printf("%d \n",temp->e);
    printf("%d \n",s->head->e);
    
}


