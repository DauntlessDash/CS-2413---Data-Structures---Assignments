#ifndef ____Map_H____
#define ____Map_H____

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <wchar.h>
#include "bst.h"

typedef int element;

struct _node{
  struct _node * left;
  struct _node * right;
  element e;
};

typedef struct _node node;

struct _tree{
  node * root;
};

typedef struct _tree tree;


tree* createBST();
void insertnode(tree * t, node * n);
node* recinsert(node* root, node *n);
void removenode(tree * t, element e);
node* recremove(node* root, element e);
node * minVal(node* node);
node* createnode(element e);
void deletenode(node * n);
void postorder(tree *t);
void recpostorder(node* n);
void preorder(tree *t);
void recpreorder(node* n);
void inorder(tree *t);
void recinorder(node* n);
int calculate(tree *t);
int reccalculate(node* n);
void clear(tree *t);
void recclear(node *n);


#endif