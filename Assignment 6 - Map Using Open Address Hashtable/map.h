#ifndef ____Map_H____
#define ____Map_H____

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <wchar.h>
#include "map.h"

struct _token{
  char text[101];
};

typedef struct _token key;
typedef struct _token value;

struct _entry{
  key k;
  value v;
};

typedef struct _entry entry;

struct  _OA_entry{
  int state;
  entry e;
};

typedef struct _OA_entry oaEntry;

struct _oa_hashtable{
  int * prime;
  oaEntry * array;
  int i;
  int po;
};

typedef struct _oa_hashtable map;


unsigned long hash(unsigned int prime, unsigned char * c, unsigned int length, unsigned long table_size);
map* createMap();
value * lookup(map *m, key k);
long lookup2(map * m, key k);
void define(map *m, key k, value v);
void resize(map * m);
void clearToken(key * k);
int sameKey(key* k1, key* k2);
void Delete(map * m, key k);


#endif