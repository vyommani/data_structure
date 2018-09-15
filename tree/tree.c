#include<stdio.h>
#include<stdlib.h>
#include "tree.h"

/* this will create a new node set the data and set left and right   
	both sub tree to null. 
*/

struct BSTree* newNode(int data){
    struct BSTree* node= (struct BSTree*)malloc(sizeof(struct BSTree*));
    node->data=data;
    node->left=node->right=NULL;
    return node;
}

/*
this will insert a node into tree. This is recursive version of insert.
*/
struct BSTree* insert(struct BSTree* node, int data){
    if(node == NULL)
		return(newNode(data));
    else{
        if(data <=node->data)
			node->left = insert(node->left, data);
		else
			node->right = insert(node->right, data);
		return node;
    }
}

/*
this will insert a node into tree. This is iterative version of insert.
*/

struct BSTree* insert_iterative(struct BSTree* root, int data){
	if(root == NULL)
		return newNode(data);
	else{
		struct BSTree* parent;
		while(root !=NULL)
		{
			parent=root;
			if(data <= root->data)
				root=root->left;
			else
				root=root->right;
		}
		if(data <= parent->data)
			parent->left = newNode(data);
		else
			parent->right = newNode(data);
	}
}
/*
 * This will search a item in tree, it returns 0(false) if item not found 
 * or returns 1(true) if item found in tree. 
 * 
 * This is recursive version of function
 */
int lookup(struct BSTree* node, int item){
    if(node == NULL)
		return 0;
    else
    {
		if(node->data == item)
			return 1;
		else
		{
			if(item < node->data)
				return lookup(node->left, item);
			else
				return lookup(node->right, item);
		}
    }
}

/*
 * This will search a item in tree, it returns 0(false) if item not found 
 * or returns 1(true) if item found in tree. 
 * 
 * This is iterative version of function
 */

int lookup_iterative(struct BSTree* node, int item){
    struct BSTree* temp=node;
    if(temp==NULL)
		return 0;
    else
    {
		if(temp->data==item)
			return 1;
		else
		{
			while(temp != NULL){
				if(item == temp->data)
					return 1;
				else if(item < temp->data)
					temp=temp->left;
				else
					temp=temp->right;
			}
			return 0;
		}
    }
}

/*
 * This will return the size of tree. 
 * This is recursive version of function
 */

int size(struct BSTree* node){
     if(node == NULL)
		return 0;
     else
		return (1 + size(node->left) + size(node->right));
}

/*
 * This will return the hight of tree. 
 * This is recursive version of function
 */

int height(struct BSTree* node){
    if(node == NULL)
		return -1;
    else
        return (1 + max(height(node->left), height(node->right)));
}

/*
 * This function will delete the entire tree.
 */
void deleteTree(struct BSTree* node){
    if(node == NULL)
		return;
    else{
        deleteTree(node->left);
		deleteTree(node->right);
		free(node);
    }
}

/*
 * this function will return 1(true), if tree has a path whoes sum is `sum` 
 * or return 0(false) otherwise. 
 */
int hasPathSum(struct BSTree* node, int sum){
    if(node == NULL)
		return (sum == 0);
    else
		return hasPathSum(node->left, sum - node->data) || hasPathSum(node->right, sum - node->data);
}

/*
 * This function will return the max node of tree, it will return -1 is tree is null.
 * This is recursive version of maxValue.
 */
int maxValue(struct BSTree* node){
    if(node == NULL)
		return -1;
    else if(node-> right != NULL)
		return maxValue(node->right);
    else
		return node->data;
}

/*
 * This function will return the max node of tree, it will return -1 is tree is null.
 * This is iterative version of maxValue.
 */

int maxValue_iterative(struct BSTree* node){
    if(node == NULL)
		return -1;
    while(node->right != NULL)
		node=node->right;
    return node->data;
}

/*
 * This function will return the min node of tree, it will return -1 is tree is null.
 * This is recursive version of minValue.
 */

int minValue(struct BSTree* node){
    if(node == NULL)
		return -1;
    else if(node->left != NULL)
		return minValue(node->left);
    else
		return node->data;
}

/*
 * This function will return the min node of tree, it will return -1 is tree is null.
 * This is iterative version of minValue.
 */

int minValue_iterative(struct BSTree* node){
    if(node == NULL)
		return -1;
    while(node->left != NULL)
        node=node->left;
    return node->data;
}

/*
 * This function will print the inorder traversal.
*/

void inorder(struct BSTree* node){
    if(node == NULL)
        return;
    inorder(node->left);
    printf("%d ",node->data);
    inorder(node->right);
}

/*
 * This function will print the preorder traversal.
 */

void preorder(struct BSTree* node){
    if(node == NULL)
        return;
    printf("%d ",node->data);
    preorder(node->left);
    preorder(node->right);
}

/*
 * This function will print the postorder traversal.
 */

void postorder(struct BSTree* node){
    if(node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ",node->data);
}

void printArray(int arr[], int len){
    for(int i=0;i<len;i++)
		printf("%d ",arr[i]);
    printf("\n");
}

void printPaths0(struct BSTree* node, int arr[], int count){
    if(node == NULL)
		return;
    else{
        arr[count++] = node->data;
		if(node->left == NULL && node->right == NULL)
			printArray(arr, count);
		else{
			printPaths0(node->left, arr, count);
			printPaths0(node->right, arr, count);
		}
    }
}

/*
 * This will print all the paths for tree. This function will first calculate 
 * the height of tree to get the max path.
*/
void printPaths(struct BSTree* node){
    int h=height(node);
    int* arr=(int *) malloc(sizeof(int)*h);
    printPaths0(node,arr,0);
    free(arr);
}

void mirror(struct BSTree* node){
    if(node == NULL)
		return;
    else{
		struct BSTree* temp;
		temp=node->left;
		node->left=node->right;
		node->right=temp;
		mirror(node->left);
		mirror(node->right);
		
    }
}

/*
 * This function will create a mirror image of tree. It will return null
 * if the tree is null.
 */
Tree createMirror(struct BSTree* root){
	if(root == NULL)
		return root;
	else{
		struct BSTree* newRoot = newNode(root->data);
		newRoot->left = createMirror(root->right);
		newRoot->right = createMirror(root->left);
		return newRoot;
	}
}

/*
 * This function will return 1(true) if tree1 and tree2 are mirror to eachother
 *  or return 0(false) otherwise.
 */
int isMirror(struct BSTree* tree1, struct BSTree* tree2){
	if(!tree1 && !tree2)
	    return 1;
	else if(!tree1 || !tree2)
	    return 0;
	else if(tree1->data == tree2->data)
	    return isMirror(tree1->left, tree2->right) && isMirror(tree1->right, tree2->left);
	else
	    return 0;
}

/*
 * this function will return 1(true) if tree is summetric or 0(false) otherwise.
 */
int isSymmetric(struct BSTree* root){
    return isMirror(root,root);
}

/*
 * This function will return the copy of original tree.
 */
struct BSTree* copy(struct BSTree* node){
    struct BSTree* tree;
    if(node == NULL)
		return NULL;
    else{
		tree = (struct BSTree*)malloc(sizeof(struct BSTree*));
		tree->data=node->data;
		tree->left=copy(node->left);
		tree->right=copy(node->right);
		return tree;
    }
}

struct BSTree* LCA0(struct BSTree* root, struct BSTree* node1, struct BSTree* node2){
    if(!root)
		return NULL;
    else if(node1 == root || node2 == root)
		return root;
    else{
		struct BSTree* left=LCA0(root->left,node1,node2);
		struct BSTree* right=LCA0(root->right,node1,node2);
		if(left  != NULL && right != NULL) // If both are not null return the root
			return root;
		if(left == NULL && right == NULL) // if both are null return null
			return NULL;
		return left ? left : right; // return which is not null
    }
}

/*
 * This function will return the lowest common ancestor on two node in binary tree. 
 */

int LCA(Tree root, int first, int second){
	Tree node=LCA0(root, newNode(first), newNode(second));
	return (node != NULL ? node->data : -1);
}

/*
 *  This function will return 1(true) if both the trees are identical and
 *  return 0(false) if otherwise.
 */
int isIdentical(struct BSTree* tree1,struct BSTree* tree2){
    if(tree1 == NULL && tree2 == NULL)
		return 1;
    else{
		if(tree1 != NULL && tree2!= NULL)
			return( tree1->data == tree2->data 
			&& isIdentical(tree1->left, tree2->left) 
			&& isIdentical(tree1->right, tree2->right));
		else
			return 0;
    }
}

struct BSTree* deleteNode(struct BSTree* node, int element){
    if(node == NULL)
		return node;
    else{
        if(element < node->data)
			node->left = deleteNode(node->left, element);
		else if(element > node->data)
			node->right = deleteNode(node->right, element);
		else{
			if(!node->left && !node->right){ // both left and right subtree are null
				free(node);
				node=NULL;
			}
			else if(!node->left){// left subtree is null
				struct BSTree* temp=node;
				node=node->right;
				free(temp);
			}
			else if(!node->right){//right subtree is null
				struct BSTree* temp=node;
				node=node->left;
				free(node);
			}
			else{// if both subtree are not null then, find the min node from right subtree replace the root and delete the min node.
				int tempValue=minValue(node->right);
				node->data = tempValue;
				node->right = deleteNode(node->right, tempValue);
			}
		}
    }
    return node;
}

int isBST0(struct BSTree* node, int min, int max){
    if(node == NULL)
		return 1;
    else{
        if(node->data < min || node->data > max)
			return 0;
		else
			return isBST0(node->left, min, node->data) && isBST0(node->right,node->data, max);
    }
}

int isBST(struct BSTree* node){
    return isBST0(node, minValue(node), maxValue(node));
}
/*
 * This function will convert a tree to double tree(
 * To create Double tree of the given tree, create a new duplicate for
 * each node, and insert the duplicate as the left child of the original node. )
 */
void doubleTree(struct BSTree* node){
    if(node == NULL)
		return;
    else{
        doubleTree(node->left);
		doubleTree(node->right);
		struct BSTree* oldLeft=node->left;
		node->left=newNode(node->data);
		node->left->left=oldLeft;
    }
}
/*
 * This function will tell if a givin tree is balance or not. This function
 *  is not efficient because it calculate the height of left and right subtree 
 * for each node.
 */
int isBalanced0(struct BSTree* root){
    if(!root)
		return 1;
    else{
        int leftHeight = height(root->left);
		int rightHeight = height(root->right);
		return abs(leftHeight - rightHeight) <= 1 && isBalanced0(root->left) && isBalanced0(root->right);
    }
}

int checkBalance(struct BSTree* root){
    if(!root)
		return 0;
    int leftHeight = checkBalance(root->left);
    if(leftHeight == -1)
		return -1;
    int rightHeight = checkBalance(root->right);
    if(rightHeight == -1)
		return -1;
    if(abs(leftHeight - rightHeight) > 1)
		return -1;
    return (1 + max(leftHeight,rightHeight));
}

/*
 * This function will return 1(true) if tree is balance 0(false) otherwise.
 */
int isBalanced(struct BSTree* root){
    return checkBalance(root)!= -1 ? 1 : 0;
}

int longestSeqPath0(struct BSTree* root, int arr[], int index){
    if(root == NULL)
		return index;
    else{
		if(index == -1)
			arr[++index] = root->data;
		else if(arr[index] == root->data - 1) // it has to be sequential
			arr[++index] = root->data;
		else
			arr[index=0]= root->data;  // reset the index and put the new item
			
		int leftSeq = longestSeqPath0(root->left,arr,index);
		int rightSeq = longestSeqPath0(root->right,arr,index); 
		return max(leftSeq,rightSeq);
	}
}

void longestSeqPath(struct BSTree* root){
    int* arr = (int *)malloc(height(root));
    int pathLength = longestSeqPath0(root,arr,-1);
    printf("\nLongest Sequence Path Length=%d\n",pathLength+1);
    printArray(arr,pathLength+1);
}
/*
 * This function will print all leaf nodes.
*/
void printLeafNodes(struct BSTree* root){
	if(root == NULL)
	    return;
	else{
	    if(root-> left == NULL && root->right == NULL)
			printf("%d ",root->data);
	    else{
			printLeafNodes(root->left);
			printLeafNodes(root->right);
	    }
	}
}

struct BSTree* deleteAllLeafNodes(struct BSTree* root){
    if(root == NULL)
		return root;
    else{
		if(root->left == NULL && root->right == NULL){
			free(root);
			root = NULL;
		}else{
			root->left = deleteAllLeafNodes(root->left);
			root->right = deleteAllLeafNodes(root->right);
		}
    }
    return root;
}

void printParameter(struct BSTree* root,int lr){
    if(root == NULL)
		return;
    else{
        if(lr == 0){
	    printf("%d ",root->data);
	    printParameter(root->left, -1);
	    printParameter(root->right, 1);
	}
	if(lr == -1){
	    printf("%d ",root->data);
	    printParameter(root->left, -1);
	}
	if(lr == 1){
	    printf("%d ",root->data);
	    printParameter(root->right, 1);
	}
    }
}

int isUniValTree(struct BSTree* root){
    if(root == NULL)
		return 1;
    else{
		if(root->left != NULL && root->right != NULL)
			return (root->data == root->left->data 
			&& root->data == root->right->data 
			&& isUniValTree(root->left) 
			&& isUniValTree(root->right));
		else if(root->left != NULL)
			return (root->data == root->left->data && isUniValTree(root->left));
		else if(root->right != NULL)
			return (root->data == root->right->data && isUniValTree(root->right));
		else
			return 1; // it is terminal node.
    }
}

int countUniValTree(struct BSTree* root){
    if(root == NULL)
	return 0;
    /*if(root->left == NULL && root->right == NULL)
        return 1;
    */
    int leftCount = countUniValTree(root->left);
    int rightCount = countUniValTree(root->right);

    if(root->left != NULL && root->right != NULL){
        if(root->data == root->right->data && root->data == root->left->data)
	    return 1 + leftCount + rightCount;
	else
	    return leftCount + rightCount;
    }
    else if(root->left != NULL){
        if(root->data == root->left->data)
	    return 1 + leftCount;
	else
	    return leftCount;
    }
    else if(root->right != NULL){
        if(root->data == root->right->data)
	    return 1 + rightCount;
	else
	    return rightCount;
    }
    else
	return 1;
}
