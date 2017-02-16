#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <wchar.h>
#include "bst.h"


tree* createBST(){
    tree*t = (tree*)malloc(sizeof(tree));
    t->root=NULL;
    return t;
}

void insertnode(tree * t, node * n){
    if(t->root==NULL){
        t->root=n;
    }
    else{
        recinsert(t->root, n);
    }
}

node* recinsert(node* root, node *n){
    
    if(root == NULL){
        
        return n;
        
    }
    else if(root->e == n->e){
        n->left = root;
        n->right = root->right;
        root->right=NULL;
        return n;
        
    }
    else if(root->e > n->e){
       
        root->left = recinsert(root->left, n);

        
    }
    else{
        
        root->right = recinsert(root->right, n);
        
        
    }
   return root;
}

void removenode(tree * t, element e){
    if(t->root==NULL){
        return;
    }
    if(t->root->e == e){
        if(t->root->left == NULL){
            t->root=t->root->right;
        }
        else if(t->root->right == NULL){
            t->root=t->root->left;
        }
        else{
            node* temp = t->root->right;
            t->root=t->root->left;
            t->root=recinsert(t->root, temp);
        }
    }
    else{
        recremove(t->root, e);
    }
}

node* recremove(node* root, element e){
    if (root == NULL) return root;
    
    if (e < root->e)
        root->left = recremove(root->left, e);
 
    else if (e > root->e)
        root->right = recremove(root->right, e);
 
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
 
        node* temp = minVal(root->right);
 
        root->e = temp->e;
 
        root->right = recremove(root->right, temp->e);
    }
    return root;
}

node * minVal(node* node)
{
    struct _node* temp = node;
    
 
    while (temp->left != NULL)
        temp = temp->left;
 
    return temp;
}

node* createnode(element e){
    node*n = (node*)malloc(sizeof(node));
    n->e=e;
    n->left=NULL;
    n->right=NULL;
}

void postorder(tree *t){
    recpostorder(t->root);
}

void recpostorder(node* n){
    if(n==NULL){
        return;
    }
    else{
        recpostorder(n->left);
        recpostorder(n->right);
        printf("%d ", n->e);
    }
}

void preorder(tree *t){
    recpreorder(t->root);
}

void recpreorder(node* n){
    if(n==NULL){
        return;
    }
    else{
        printf("%d ", n->e);
        recpreorder(n->left);
        recpreorder(n->right);
        
    }
}

void inorder(tree *t){
    recinorder(t->root);
}

void recinorder(node* n){
    if(n==NULL){
        return;
    }
    else{
        recinorder(n->left);
        printf("%d ", n->e);
        recinorder(n->right);
        
    }
}

int calculate(tree *t){
    return reccalculate(t->root);
}

int reccalculate(node* n){
    int a;
    int b;
    int c;
    if(n==NULL){
        return 0;
    }
    else if(n->left == NULL && n->right == NULL){
        return n->e;
    }
    else{
        a = reccalculate(n->left);
        b = reccalculate(n->right);
        c=n->e;
        return c*(a-b);
        
    }
}

void clear(tree *t){
    recclear(t->root);
    t->root=NULL;
    return;
}

void recclear(node *n){
    if(n==NULL){
        return;
    }
    if(n->left != NULL){
        recclear(n->left);
    }
    if(n->right != NULL){
        recclear(n->right);
    }
    free(n);
    return;
}