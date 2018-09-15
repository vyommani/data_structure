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
    tree = deleteNode(tree,17);
    printf("\nTree after deleting 17: ");
    inorder(tree);
    
    
    tree = deleteNode(tree,14);
    printf("\nTree after deleting 14: ");
    inorder(tree);
    
    tree = deleteNode(tree,22);
    printf("\nTree after deleting 22: ");
    inorder(tree);
    
    tree = deleteNode(tree,19);
    printf("\nTree after deleting 19: ");
    inorder(tree);
    
    return 0;
}
