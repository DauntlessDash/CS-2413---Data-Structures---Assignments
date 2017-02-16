#include "dll.h"
#include "sort.h"
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

void add(stack s, element e)
{
    node n = (node)malloc(sizeof(node_type));
    if(s->tail == NULL || s->head == NULL){
      s->tail = n;
      s->head = n;
       n->e=e;
       return;
    }
    else{
    n->e=e;
    s->tail->prev = n;
    n->next = s->tail;
    s->tail = n;
    s->tail->prev = NULL;
    return;
    }
}

void addfront(stack s, element e)
{
    node n = (node)malloc(sizeof(node_type));
    if(s->tail == NULL || s->head == NULL){
      s->tail = n;
      s->head = n;
       n->e=e;
       return;
    }
    else{
    n->e=e;
    s->head->next = n;
    n->prev = s->head;
    s->head = n;
    return;
    }
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
    if(s->head == s->tail){
        printf("%d ",s->head->e);
        return;
    }
    node temp;
    temp=s->head;
    while(temp->prev!=s->tail)
    {
    printf("%d ",temp->e);
    temp=temp->prev;
    }
    printf("%d ",temp->e);
    printf("%d ",s->tail->e); 
    return;
    
}

void bubblesort(stack s)
{
    int new_pass=1;
    int a, b;
    if(s->head == NULL)
    {
        return;
    }
    while (new_pass!=0){
        new_pass=0;
        node temp = s->head;
        while(temp->prev!=NULL){
            if(temp->e > temp->prev->e)
            {
                printf("Swapping %d %d", temp->e, temp->prev->e);
                element tempe = temp->e;
                temp->e = temp->prev->e;
                temp->prev->e = tempe;
                new_pass = 1;
            }
            temp=temp->prev;
        }
    }
}

void sortedadd(stack s, element a)
{
    int b,c;

    if (s->head == NULL)
    {
        printf("Inserting %d On Empty List", a);
        add(s, a);
        return;
    }
    else if (s->head->e >= a)
    {
        printf("Inserting %d At Front of List", a);
        addfront(s, a);
        return;
    }
    else
    {
        node current;
        current = s->head;
        if(current->prev==NULL)
            {
                printf("Inserting %d At Back of List", a);
                add(s, a);
                return;
            }
        while (current->prev->e < a)
        {
            if(current->prev==NULL)
            {
                printf("Inserting %d At Back of List", a);
                add(s, a);
                return;
            }
            current = current->prev;
        }
        node n = (node)malloc(sizeof(node_type));
        printf("Inserting %d Between %d And %d", a, current->e, current->prev->e);
        n->e=a;
        n->next = current;
        n->prev = current->prev;
        current->prev = n;
        current->prev->next = n;
        
    }
    return;
}

void insertionsort(stack s)
{
    stack b;
    node temp;
    b = createQueue();
    while(s->head != NULL)
    {
    temp = s->head;
    printf("Removed %d", s->head->e);
    s->head=s->head->prev;
    sortedadd(b, temp->e);
    }
    display(b);
    destroyQueue(b);
    return;
}

int compare(element a, element b)
{
    if(a<b)
    {
        return -1;
    }
    else if(a>b)
    {
        return 1;
    }
}

