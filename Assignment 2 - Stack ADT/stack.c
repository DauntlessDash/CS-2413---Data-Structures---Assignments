#include "stack.h"
#include "stdheader.h"

stack newstack(){
    stack s = (stack)malloc(sizeof(stack_type));
    s->head=NULL;
    return s;
}

void deletestack(stack s){
    node temp;
    while(s->head){
        temp = s->head;
        s->head = s->head->next;
        free(temp);
    }
    free(s);
}

element pop(stack s){
    node temp = s->head->next;
    element e = s->head->e;
    free(s->head);
    s->head=temp;
    return e;
}

void push(stack s, element e)
{
    node n = (node)malloc(sizeof(node_type));
    n->e=e;
    n->next = s->head;
    s->head = n;
}

isEmpty(stack s){
    if(s->head==NULL)
    { return 1;}
    return 0;
}

element peek(stack s)
{
   element e = s->head->e;
   return e;
}

void display(stack s)
{
    printf("Display\n");
    node temp;
    temp=s->head;
    while(temp->next!=NULL)
    {
    printf("%d \n",temp->e);
    temp=temp->next;
    }
    printf("%d \n",temp->e);
    
}


