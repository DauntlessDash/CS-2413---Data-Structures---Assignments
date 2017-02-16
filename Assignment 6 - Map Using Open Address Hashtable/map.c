#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <wchar.h>
#include "map.h"


unsigned long hash(unsigned int prime, unsigned char * c, unsigned int length, unsigned long table_size){
  unsigned long a =0;
  unsigned int i = 0;
  
  for(i=0; i<length; i++){
    a=prime * a + c[i];
  }
  return a % table_size;
}

map* createMap(){
    int i=0;
    map*m = (map*)malloc(sizeof(map));
    m->prime = (int*)malloc(sizeof(int)*9);
    m->prime[0]=2;
    m->prime[1]=3;
    m->prime[2]=5;
    m->prime[3]=7;
    m->prime[4]=13;
    m->prime[5]=29;
    m->prime[6]=59;
    m->prime[7]=113;
    m->prime[8]=223;
    m->i=2;
    m->array = (oaEntry*)malloc(sizeof(oaEntry)*m->prime[m->i]);
    memset(m->array, 0, m->prime[m->i]);
    for(i=0; i<m->prime[2];i++)
    {
        m->array[i].state=1;
    }
    m->po=0;
}
value * lookup(map *m, key k){
    long index = lookup2(m,k);
    if(index == -1)
    {
        printf("Entry for Key:%s Not Found\n", (char*) &k);
        return NULL;
    }
    else{
        printf("Entry for Key:%s Found At Index:%ld\n", (char*) &k, index);
        return &(m->array[index].e.v);
    }
}

long lookup2(map * m, key k){
    int start = hash(m->prime[m->i-1],
                        (unsigned char*)&k, sizeof(key),
                        m->prime[m->i]);
    
    int offset = 1+hash(m->prime[m->i-2],
                            (unsigned char*)&k, sizeof(key),
                        m->prime[m->i]);
    int index = start;
    if(offset==0){
        offset = 1;
    }
   
    while(m->array[index].state !=1){
        printf("** Looking For Key:%s At Index:%d OFFSET:%d\n", (char*) &k, index, offset);
        if (m->array[index].state==2){
            if(sameKey(& k, & m->array[index].e.k))
            {
                return index;
            }}
            index = index + offset % m->prime[m->i];
    }
    return -1;
}

void define(map *m, key k, value v){
    int index = lookup2(m, k);
    
    if(index > -1){
        m->array[index].e.v = v;
        printf("Updating Entry For Key:%s At Index:%d\n", (char*) &k, index);
        return;
    }
    
    int start = hash(m->prime[m->i-1], (unsigned char*)& k, sizeof(key),
                        m->prime[m->i]);
    
    int offset = hash(m->prime[m->i-2], (unsigned char*)& k, sizeof(key),
                        m->prime[m->i]);
                        
    index = start;
                        
    while(m->array[index].state != 1){
        if(m->array[index].state == 3){
            m->array[index].e.k = k;
            m->array[index].e.v = v;
            m->array[index].state = 2;
            printf("Creating Entry For Key:%s At PO Index:%d\n", (char*) &k, index);
            return;
        }
        index = index + offset % m->prime[m->i];
    }
        m->array[index].e.k = k;
        m->array[index].e.v = v;
        m->array[index].state = 2;
        printf("Creating Entry For Key:%s At NO Index:%d\n", (char*) &k, index);
        m->po++;
        if(m->po > m->prime[m->i]/2){
           resize(m);
        }
       
}

void resize(map * m){
    int i = 0;
    oaEntry * old = m->array;
    unsigned long oldSize = m->prime[m->i];
    m->i++;
    m->po = 0;
    printf("RESIZING: FROM:%d TO:%d\n", m->prime[m->i-1],m->prime[m->i]);
    m->array = (oaEntry*)malloc(sizeof(oaEntry)*m->prime[m->i]);
    for(i=0; i<m->prime[2];i++)
    {
        m->array[i].state=1;
    }
    for(i = 0; i< oldSize; i++)
    {
        if(old[i].state == 2){
          define(m, old[i].e.k, old[i].e.v);  
        }
    }
    free(old);
    printf("DONE RESIZING\n");
}

void clearToken(key * k){
    int i =0;
    while(i<101){
        k->text[i]='\0';
        i++;
    }
}

int sameKey(key* k1, key* k2){
    if(strcmp(k1->text, k2->text)){
        return 0;
    }
    else{
        return 1;
    }
}

void Delete(map * m, key k){
    unsigned long index = lookup2(m,k);
    if(index == -1){
        printf("Entry for Key:%s Not Found\n", (char*) &k);
    }
    else{
        m->array[index].state = 3;
        printf("Deleting Entry for Key:%s At Index:%ld\n", (char*) &k, index);
    }
}