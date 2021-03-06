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
 *                12  15   20  23 25 31
 *                                   / \
 * 									/   \
 * 								   27    38
 *                                  \    /
 *                                  28  37
*/

int main(void){
	int arr[]={18,16,24,14,17,22,26,12,15,20,23,25,31,38,27,28,37};
    Tree tree = createTree(arr,sizeof(arr)/sizeof(arr[0]));
    printAllDeepestNodes(tree);
    printf("\n");
    return 0;
}
