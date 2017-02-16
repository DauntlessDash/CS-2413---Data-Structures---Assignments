#ifndef ____Linked_List_H____
#define ____Linked_List_H____

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <wchar.h>


//Structures

//element is content of a node.
typedef int element;

//node is 1 link in a linked list. 
struct _node{
  element e;
  struct _node* next;
  struct _node* prev;
};

typedef struct _node node_type;
typedef struct _node* node;

//linked list is a series of links tracked by the head or start of the list. 
struct _linked_list{
  node head;
  node tail;
};

typedef struct _linked_list stack_type;
typedef struct _linked_list* stack;

stack createQueue();
void destroyQueue(stack);
int isEmpty(stack);
element dequeue(stack);
void enqueue(stack, element);
element peek(stack);
void display(stack);


#endif