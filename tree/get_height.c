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
 *                        18
 *                       / \
 *                      /   \
 *                     /     \
 *                    16      24
 *                    /\      /\
 *                   /  \    /  \
 *                  14  17  22   26
 *                  /\      /\    /\
 *                 /  \    /  \  /  \
 *                12  15   20  23 25 28
 *                          \         \
 *                           \         \
 *                           21         30
*/

int main(void){
	int arr[]={18,16,24,14,17,22,26,12,15,20,23,25,28,21,30};
    Tree tree = createTree(arr,sizeof(arr)/sizeof(arr[0]));
    
    printf("\nInorder traversal:");
    inorder(tree);
    
    printf("\nHeight of tree is = %d\n", height(tree));
    
    return 0;
}
