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
    Tree copy_tree = copy(tree);
    
    printf("\n Is both trees are copy of each other = %d\n",isIdentical(tree,copy_tree)); // This should return true.
    // this will equivalent to original tree so this should return false.
    Tree mirror_tree = createMirror(copy_tree);
    printf("\n Is both trees are copy of each other = %d\n",isIdentical(tree,mirror_tree)); // this should return false.
    return 0;
}
