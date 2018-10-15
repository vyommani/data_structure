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
 *                        18               |           18
 *                       / \               |           /\
 *                      /   \              |          /  \
 *                     /     \             |         /    \
 *                    16      24           |        24     16
 *                    /\      /\           |        / \    / \
 *                   /  \    /   \         |       /   \  /   \
 *                  14  17  22   26        |      26   22 17   14
 *                  /\      /\    /\       |      /\   /\       /\
 *                 /  \    /  \  /  \      |     /  \ /  \     /  \
 *                12  15   20  23 25 28    |    28  25 23 20  15  12
*/

int main(void){
	int arr[]={18,16,24,14,17,22,26,12,15,20,23,25,28};
    Tree tree = createTree(arr,sizeof(arr)/sizeof(arr[0]));
    printf("\nOriginal tree:");
    inorder(tree);
    Tree mirror_tree = createMirror(tree);
    printf("\nExpected  Mirror   tree:28 26 25 24 23 22 20 18 17 16 15 14 12");
    printf("\nGenerated Mirror   tree:");
    inorder(mirror_tree);
    return 0;
}
