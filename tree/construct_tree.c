#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Tree{
    char data;
    struct Tree* left;
    struct Tree* right;
};

typedef struct Tree* Tree;
/*
 * This function will create a new node.
 */
Tree newNode(char data){
    Tree tree = malloc(sizeof(Tree));
    tree->data = data;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

/*
 * This function will create a new string of length of 'length + 1' and 
 * copy the contents from src.
 */
char* myCopy(char *src, int length){
    char* result =  malloc(length+1);
    int i=0;
    while(length > 0){
        result[i++] = *src;
		src++;
		length--;
    }
    result[i] = 0;
    return result;
}
/*
 * This function will find the index of ch into src and return it index.
 * If ch is not found this function will return -1.
 */
int indexOf(char* src, char ch){
    int index=0;
    while( *src != ch || *src != '\0'){
        index++;
		src++;
    }
    if(*src == ch)
		return index;
	else
		return -1;
}

/*
 * This function will construct the tree, from given preorder and inorder if
 * there are  no duplicate element in tree.
 *
 */
Tree buildTree(char* inOrder, char* preOrder){
    if(*inOrder == '\0')
		return NULL;
    else{
		char root = preOrder[0];
		Tree tree = newNode(root);
		int rootIndex = (int)(strchr(inOrder, root) - inOrder);
		char* leftInOrder = myCopy(inOrder, rootIndex);
		char* rightInOrder = myCopy(inOrder + rootIndex + 1, strlen(inOrder) - rootIndex + 1);
		char* leftPreOrder = myCopy(preOrder + 1, rootIndex);
		char* rightPreOrder = myCopy(preOrder + rootIndex + 1, strlen(preOrder) - rootIndex);
		tree->left = buildTree(leftInOrder, leftPreOrder);
		tree ->right = buildTree(rightInOrder, rightPreOrder);
		free(leftInOrder);
		free(rightInOrder);
		free(leftPreOrder);
		free(rightPreOrder);
		return tree;	
    }
}

void printInOrder(Tree tree){
    if(tree == NULL)
		return;
    printInOrder(tree->left);
    printf("%c",tree->data);
    printInOrder(tree->right);
}

int main(void){
     char* inOrder  = "FSNQWBAKMLZG";
     char* preOrder = "ABFQNSWGKLMZ";
     printf("Given inorder\n%s",inOrder);
     Tree tree = buildTree(inOrder,preOrder);
     printf("\n");
     printInOrder(tree);
     printf("\n");
     return 1;
}
