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

void insertnode(tree * t, element e){
    t->root=recinsert(t->root, e);
}

node* recinsert(node* n, element e){
    
    if(n==NULL){
        n = (node*)malloc(sizeof(node));
        n->e=e;
        n->left=NULL;
        n->right=NULL;
        n->height=1;
        return n;
    }
    if(e>n->e){
        n->right = recinsert(n->right, e);
    }
    else{
        n->left = recinsert(n->left, e);
    }
    recalcheight(n);
    return rebalance(n);
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
            int temp = t->root->right->e;
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
    
    if (e < root->e){
        root->left = recremove(root->left, e);
        return rebalance(root);
    } else if(e>root->e){
        root -> right = recremove(root->right, e);
        return rebalance(root);
    }
    else{
        node * newroot;
        if(root->left == NULL){
            newroot = root->right;
            root->right = NULL;
            free(root);
            recalcheight(newroot);
            return newroot;
        }
        else if(root->right == NULL){
            newroot = root->left;
            root->left=NULL;
            free(root);
            recalcheight(newroot);
            return newroot;
        }
        else{
            node *leftsubtree = removelargestnode(root->left, &newroot);
            newroot->right = root->right;
            newroot->left = leftsubtree;
            root->left = root->right = NULL;
            free(root);
            recalcheight(newroot);
            return rebalance(newroot);
        }
    }
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

unsigned int height(node *n){
    if(n==NULL){
        return 0;
    }
    return n->height;
}

void recalcheight(node * n){
    if(n!=NULL){
        n->height=(max(height(n->left), height(n->right))+1);
    }
}

int max(int a, int b){
    if(a>b){
        return a;
    }
    else if(b>a){
        return b;
    }
    else if(b==a){
        return a;
    }
}

node* RotateRight(node * n){
    if(n==NULL){
        return NULL;
    }
    if(n->left==NULL && n->right == NULL){
        printf("RotateRight NULL %d NULL\n", n->e);
    }
    else if(n->left==NULL){
        printf("RotateRight NULL %d %d\n", n->e, n->right->e);
    }
    else if(n->right==NULL){
        printf("RotateRight %d %d NULL\n", n->left->e, n->e);
    }
    else{
        printf("RotateRight %d %d %d\n", n->left->e, n->e, n->right->e);
    }
    if(n->left == NULL){
        return n;
    }
    node *nL = n->left;
    n->left = nL->right;
    nL->right = n;
    recalcheight(nL);
    return nL;
}

node* RotateLeft(node * n){
    if(n==NULL){
        return NULL;
    }
    if(n->left==NULL && n->right == NULL){
        printf("RotateLeft NULL %d NULL\n", n->e);
    }
    else if(n->left==NULL){
        printf("RotateLeft NULL %d %d\n", n->e, n->right->e);
    }
    else if(n->right==NULL){
        printf("RotateLeft %d %d NULL\n", n->left->e, n->e);
    }
    else{
        printf("RotateLeft %d %d %d\n", n->left->e, n->e, n->right->e);
    }
    if(n->right == NULL){
        return n;
    }
    node *nR = n->right;
    n->right = nR->left;
    nR->left = n;
    recalcheight(nR);
    return nR;
}

node * rebalance(node * root){
    if(root == NULL){
        return root;
    } 
    int diff = height(root->left)-height(root->right);
    if(diff >= -1 && diff <=1){
        return root;
    }
    if(diff<0){
        if(height(root->right->left) > height(root->right->right)){
            root->right = RotateRight(root->right);}
            return RotateLeft(root);
    }else{
        if(height(root->left->right)>height(root->left->left)){
            root->left = RotateLeft(root->left);}
        return RotateRight(root);
    }
}

node * removelargestnode(node * root, node**largest){
    if(root==NULL){
        *largest = NULL;
        return root;
    }
    if(root->right != NULL){
        root->right=removelargestnode(root->right, largest);
        return rebalance(root);
    } else{
        node * left = root->left;
        root->left = NULL;
        root->height = 1;
        *largest = root;
        return left;
    }
}
    
