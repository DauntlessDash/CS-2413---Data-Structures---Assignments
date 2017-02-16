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
element removenode(stack s){
    if(s->head==s->tail){
        element e = s->head->e;
        s->head=NULL;
        return e;
    }
    node temp = s->head->prev;
    element e = s->head->e;
    free(s->head);
    s->head=temp;
    s->head->next=NULL;
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

int listsize(stack s)
{
    int n=0;
    //printf("current: font: %d back: %d \n",s->head->e, s->tail->e);
    
    if(s->head==NULL)
    {
        return 0;
    }
    else if(s->head==s->tail)
    {
        return 1;
    }
    else
    {
        node temp;
        temp=s->head;
        while(temp->prev != NULL)
        {
            n++;
            temp=temp->prev;
        }
        return n+1;
    }
    
}

void sortedmerge(stack a, stack b, stack s)
{
  node temp;
 
  while(b->head!=NULL && a->head!=NULL){
      if(a->head->e < b->head->e)
      {
          temp=a->head;
          a->head=a->head->prev;
          if(s->head==NULL)
          {
              s->head=temp;
              s->tail=temp;
          }
          else{
              s->tail->prev = temp;
              temp->next = s->tail;
              s->tail = temp;
              s->tail->prev = NULL;
          }
      }
      else if(b->head->e < a->head->e)
      {
          temp=b->head;
          b->head=b->head->prev;
          if(s->head==NULL)
          {
              s->head=temp;
              s->tail=temp;
          }
          else{
              s->tail->prev = temp;
              temp->next = s->tail;
              s->tail = temp;
              s->tail->prev = NULL;
          }
        }
        else if(b->head->e == a->head->e)
        {
          temp=b->head;
          b->head=b->head->prev;
          if(s->head==NULL)
          {
              s->head=temp;
              s->tail=temp;
          }
          else{
              s->tail->prev = temp;
              temp->next = s->tail;
              s->tail = temp;
              s->tail->prev = NULL;
          }
          temp=a->head;
          a->head=a->head->prev;
          if(s->head==NULL)
          {
              s->head=temp;
              s->tail=temp;
          }
          else{
              s->tail->prev = temp;
              temp->next = s->tail;
              s->tail = temp;
              s->tail->prev = NULL;
          }
        }
  }
  if(b->head==NULL && b->head!=NULL){
      temp=a->head;
          a->head=a->head->prev;
          if(s->head==NULL)
          {
              s->head=temp;
              s->tail=temp;
          }
          else{
              s->tail->prev = temp;
              temp->next = s->tail;
              s->tail = temp;
              s->tail->prev = NULL;
          }
      
  }
  if(a->head==NULL && b->head != NULL){
      temp=b->head;
          b->head=b->head->prev;
          if(s->head==NULL)
          {
              s->head=temp;
              s->tail=temp;
          }
          else{
              s->tail->prev = temp;
              temp->next = s->tail;
              s->tail = temp;
              s->tail->prev = NULL;
          }
      
  }
}

void mergesort(stack s)
{
    int size=listsize(s);    
    printf("Merge Sort, Size Of List: %d\n", size);
    int i;
    stack a;
    stack b;
    node temp;
    a=createQueue();
    b=createQueue();
    
    
    if(s->head==s->tail || s->head==NULL)
    {
        return;
    }
    
   
    temp = s->head;
    for(i=0; i<((size-1)/2); i++)
    {
        temp=temp->prev;
    }
    temp=temp->prev;
    
    a->head=s->head;
    b->head = temp;
    b->tail = s->tail;
    a->tail = temp->next;
    a->tail->prev=NULL;
    a->head->next=NULL;
    b->tail->prev=NULL;
    b->head->next=NULL;
    s->head=NULL;
    s->tail=NULL;
    
    //printf("A: font: %d back: %d \n",a->head->e, a->tail->e);
    //printf("B: font: %d back: %d \n",b->head->e, b->tail->e);
    
    mergesort(a);
    mergesort(b);
   
   int num;
    
    while(a->head!=NULL){
         num=removenode(a);
         add(s, num);
     }
    while(b->head!=NULL){
        num=removenode(b);
        add(s, num);
    }
    destroyQueue(a);
    destroyQueue(b);
    printf("DONE: Merge Sort, Size Of List: %d \n", size);
    
}

void quicksort(stack s)
{
     int size=listsize(s);  
     printf("Quick Sort, Size Of List: %d\n", size);
     if(s->head==s->tail){
         return;
     }
     node temp;
     int num;
     int pivot;
     stack a = createQueue();
     stack b = createQueue();
     pivot = removenode(s);
     printf("Picked Pivot: %d\n", pivot);
     while(s->head!=NULL)
     {
         if(s->head->e<=pivot){
         num=removenode(s);
        // printf("Removed: %d\n", num);
         add(a,num);
         // printf("Added %d to a\n", num);
         }
         else if (s->head->e>=pivot)
         {
             num=removenode(s);
             //printf("Removed: %d\n", num);
             add(b,num);
            // printf("Added %d to b\n", num);
         }
     }
     quicksort(a);
     quicksort(b);
     
     while(a->head!=NULL){
         num=removenode(a);
         add(s, num);
     }
     add(s, pivot);
    while(b->head!=NULL){
        num=removenode(b);
        add(s, num);
    }
    destroyQueue(a);
    destroyQueue(b);
     printf("DONE: Quick Sort, Size Of List: %d \n", size);
     
     
}


