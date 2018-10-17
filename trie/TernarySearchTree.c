#include "TernarySearchTree.h"

Tree createNewNode(char ch){
    Tree node = malloc(sizeof(struct ternary_search_tree));
    node->ch = ch;
    node->left = NULL;
    node->middle = NULL;
    node->right = NULL;
    return node;
}

Tree insert0(Tree root, char* key, int value, short index){
   char ch = *(key + index);    
   if(root == NULL)
       root= createNewNode(ch);
   if(*(key + index) < root->ch)
       root->left = insert0(root->left, key, value, index);
   else if(*(key + index) > root->ch)
       root->right = insert0(root->right, key, value, index);
   else if(index < strlen(key)  )
       root->middle = insert0(root->middle, key, value, index + 1);
   else
       root->value = value; //This will update the existing value.
   return root;
}

Tree insert(Tree root, char* key, int value){
    return insert0(root, key, value, 0);
}

Tree get0(Tree root, char* key, short index){
    char ch = *(key + index);
    if(ch < root->ch)
		return get0(root->left, key,index);
    else if( ch > root->ch)
		return get0(root->right, key, index);
    else if( index < strlen(key))
		return get0(root->middle, key, index + 1);
    else
		return root;
}

int get(Tree root, char* key){
    if(root == NULL)
		return -1;
    else if( key == NULL || strlen(key) == 0)
		return -1;
    else{
		Tree node = get0(root, key, 0);
		return node->value;
    }
}
