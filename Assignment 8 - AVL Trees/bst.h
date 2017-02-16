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
  unsigned int height;
};

typedef struct _node node;

struct _tree{
  node * root;
};

typedef struct _tree tree;


tree* createBST();
void insertnode(tree * t, element e);
node* recinsert(node* n, element e);
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
unsigned int height(node *n);
void recalcheight(node * n);
int max(int a, int b);
node* RotateRight(node * n);
node* RotateLeft(node * n);
node * rebalance(node * root);
node * removelargestnode(node * root, node**largest);

#endif