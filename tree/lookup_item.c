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
    
    printf("\nInorder traversal:");
    inorder(tree);
    
    int item = 26;
    // This will use the recursive version of function.
    if(lookup(tree, item))
		printf("\n Item %d present is tree\n",item);
	else
		printf("\n Item %d not present is tree\n",item);
    
    item = 223;
    if(lookup(tree, item))
		printf("\n Item %d present is tree\n",item);
	else
		printf("\n Item %d not present is tree\n",item);
    
    //This will use iterative version of function
    item = 22;
    if(lookup_iterative(tree, item))
		printf("\n Item %d present is tree\n",item);
	else
		printf("\n Item %d not present is tree\n",item);
    item = 99;
    if(lookup_iterative(tree, item))
		printf("\n Item %d present is tree\n",item);
	else
		printf("\n Item %d not present is tree\n",item);
    
    return 0;
}
