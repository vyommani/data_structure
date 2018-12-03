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
 *                   /  \    /   \
 *                  14  17  22   26
 *                  /\      /\    /\
 *                 /  \    /  \  /  \
 *                12  15   20  23 25 28
*/

int main(void){
	int arr[]={18,16,24,14,17,22,26,12,15,20,23,25,28};
    Tree tree = createTree(arr,sizeof(arr)/sizeof(arr[0]));
    
    printf("\nOriginal tree:");
    inorder(tree);
    
    printf("\n Inorder Predecessor of 12 is  = %d\n", inorderPredecessor(tree,12));
    printf("\n Inorder Predecessor of 15 is  = %d\n", inorderPredecessor(tree,15));
    printf("\n Inorder Predecessor of 22 is  = %d\n", inorderPredecessor(tree,22));
    printf("\n Inorder Predecessor of 26 is  = %d\n", inorderPredecessor(tree,26));
    printf("\n Inorder Predecessor of 17 is  = %d\n", inorderPredecessor(tree,17));
    return 0;
}
