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
    Tree mirror_tree = createMirror(tree);
    printf("\n Is both trees are mirror to each other = %d\n",isMirror(tree,mirror_tree)); // This should return true.
    // this will equivalent to original tree so this should return false.
    Tree original_tree = createMirror(mirror_tree);
    printf("\n Is both trees are mirror to each other = %d\n",isMirror(tree,original_tree)); // this should return false.
    return 0;
}
