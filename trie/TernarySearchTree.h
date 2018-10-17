#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ternary_search_tree* Tree;

struct ternary_search_tree{
    char ch;
    int value;
    Tree left, middle, right;
};
Tree insert(Tree, char*, int);
int get(Tree, char*);
