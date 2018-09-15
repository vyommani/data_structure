#include<stdio.h>
#include "tree.h"

Tree createTree(int tree[], int length){
	Tree bstTree=NULL;
	for(int i=0;i< length; i++){
		bstTree=insert(bstTree,tree[i]);
	}
	return bstTree;
}

/*
 * This will create a following BST 
 *                        23
 *                       / \
 *                      /   \
 *                     /     \
 *                    16      24
 *                    /\      /\
 *                   /  \    /   \
 *                  14  17       25
 *                  /\             \
 *                 /  \             \
 *                12  15            26
*/

int main(void){
	int arr[]={23,16,24,14,17,25,12,15,26};
    Tree tree = createTree(arr,sizeof(arr)/sizeof(arr[0]));
    printf("\nOriginal tree:");
    inorder(tree);
    
    printf("\nLonest sequence path: ");
    longestSeqPath(tree);
    return 0;  
}
