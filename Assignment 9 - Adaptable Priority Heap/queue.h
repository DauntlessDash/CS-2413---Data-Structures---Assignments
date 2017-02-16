#ifndef ____Linked_List_H____
#define ____Linked_List_H____

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <wchar.h>


struct _element{
  char first[50];
  char last[50];
};

typedef struct _element element;

struct _Handle{
  int index;
  
};

typedef struct _Handle handle;


struct _Entry{
  element e;
  int p;
  handle *h;
  
};

typedef struct _Entry entry;

struct _Que{
  entry * array;
  int size;
  int entries;
  int nextlevel;
  
};

typedef struct _Que que;

que* createQueue();
handle* enqueue(que* q, element el, int priority);
void update(que * q, handle * h, int priority);
int isEmpty(que * q);
element dequeue(que * q);
void swap(que * q, int parent, int child);
void upheap(que * q, int index);
void downheap(que * q, int index);
int compare(int left, int right);
void resize(que * q);


#endif