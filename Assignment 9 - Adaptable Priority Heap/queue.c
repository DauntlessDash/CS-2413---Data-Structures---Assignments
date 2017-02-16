#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <wchar.h>


que* createQueue(){
     que*q = (que*)malloc(sizeof(que));
     q->array = (entry*)malloc(sizeof(entry)*2);
     q->size=2;
     q->entries=0;
     q->nextlevel=2;
}

handle* enqueue(que* q, element el, int priority){
    if(q->entries+1>q->size-1){
        resize(q);
    }
    q->array[(q->entries+1)].e=el;
    //printf("Enqueue is %s %s", q->array[(q->entries+1)].e.first, q->array[(q->entries+1)].e.last);
    q->array[(q->entries+1)].p=priority;
    (q->entries)++;
    handle*h = (handle*)malloc(sizeof(handle));
    q->array[(q->entries)].h=h;
    h->index=(q->entries);
    upheap(q, (q->entries));
    return h;
    
}

void update(que * q, handle * h, int priority){
  // printf("Before %s %s is %d \n", q->array[(q->entries+1)].e.first, q->array[(q->entries+1)].e.last,  q->array[(q->entries+1)].p);
    q->array[(h->index)].p=priority;
    if(compare(q->array[h->index].p,q->array[h->index/2].p)== 1){
            upheap(q, (h->index));
        }
    else{
        downheap(q, (h->index));
    }
}

int isEmpty(que * q){
    if(q->entries==0){
        return 1;
    }
    else{
        return 0;
    }
}

element dequeue(que * q){
    element temp;
    temp = q->array[1].e;
    q->array[1].e=q->array[q->entries].e;
    q->entries=(q->entries)-1;
    downheap(q, 1);
    return temp;
}

void swap(que * q, int parent, int child){
    entry temp;
    temp.e = q->array[parent].e;
    temp.p = q->array[parent].p;
    temp.h = q->array[parent].h;
    q->array[parent].e=q->array[child].e;
    q->array[parent].p=q->array[child].p;
    q->array[parent].h=q->array[child].h;
    q->array[child].e=temp.e;
    q->array[child].p=temp.p;
    q->array[child].h=temp.h;
    q->array[child].h->index=child;
    q->array[parent].h->index=parent;
    printf("Swapping index %d and %d\n", child, parent);
}

void upheap(que * q, int index){
    if(index<1) return;
    if(index == 1) return;
    if(index > 1){
        if(compare(q->array[index].p,q->array[index/2].p)== 1){
            swap(q, index, (index/2));
            upheap(q, (index/2));
        }
    }
}

void downheap(que * q, int index){
    if(index<1) return;
    if((index*2)>q->entries) return;
    if(index*2+1 > q->entries){
        if(compare(q->array[index].p,q->array[index*2].p) == -1){
            swap(q, index, index*2);
            downheap(q, index*2);
        }
        return;
    }
    else if(compare(q->array[index*2].p,q->array[index*2+1].p) != -1){
        if(compare(q->array[index].p,q->array[index*2].p) == -1){
            swap(q, index, index*2);
            downheap(q, index*2);
        }
        return;
    }
    else if(compare(q->array[index*2].p,q->array[index*2+1].p) == -1){
        if(compare(q->array[index].p,q->array[index*2+1].p) == -1){
            swap(q, index, index*2+1);
            downheap(q, index*2+1);
        }
        return;
    }
}

int compare(int left, int right){
if(left < right) return -1;
if(left > right) return 1;
return 0;
}

void resize(que * q){
    entry * temp = (entry*)malloc(sizeof(entry)*(q->size+q->nextlevel));
    
    int i = 1;
    while(i<=q->entries){
        temp[i]=q->array[i];
        i++;
    }
    q->array=temp;
    q->size = q->size+q->nextlevel;
    q->nextlevel = q->nextlevel*2;
    printf("Resized Array To %d\n", q->size);
}