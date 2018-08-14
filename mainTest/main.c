#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "libs.h"

#define DEBUG_MODE

#define MAX_DATA 16

unsigned int data = 1;


typedef struct __node
{
    struct __node* left;
    struct __node* right;
    int value;

} TNode;

typedef struct _tree
{
    int weight;
    int height;
    TNode* root;
} Tree;

void init_tree(TNode * T)
{
    T->left = NULL;
    T->right = NULL;
    T->value = data++;
}

void fill_tree(TNode * T)
{
    if(data < MAX_DATA)
    {
        TNode* L = (TNode*)malloc(sizeof(TNode));
        TNode* R = (TNode*)malloc(sizeof(TNode));
        L->value = data++;
        R->value = data++;
        L->right = NULL;
        R->right = NULL;
        L->left = NULL;
        R->left = NULL;
        T->left = L;
        T->right = R;
        fill_tree(L);
        fill_tree(R);
    }
}

void print_tree(TNode* T)
{
    if(T != NULL)
    {
        printf("%d\t", T->value);
        print_tree(T->left);
        print_tree(T->right);
    }
}

void print_tree_organized(TNode* T)
{
    static int index = 0;
    index++;
    if(T != NULL)
    {
        printf("idx %d\n", index);
        printf("%d\t", T->value);
        print_tree_organized(T->left);
        print_tree_organized(T->right);
    }
}

void main()
{
    TNode tree;
    init_tree(&tree);
    fill_tree(&tree);
    print_tree(&tree);
    printf("\n");
    print_tree_organized(&tree);
    printf("\n");
}

