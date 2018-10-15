#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "trie.h"

Trie createNewTrieNode(char ch){
    Trie node = malloc(sizeof(struct trie));
    node->ch = ch;
    memset(node->childs, 0, sizeof(node->childs));
    node->isCompleteWord = 0;
    node->parent = NULL;
    node->isChilds = 0;
    return node;
}

void addWord0(Trie root, char* word, short index){
	if(*(word + index) == 0){
		root->isCompleteWord = 1;
		return;
	}
	if(root->childs[*(word + index)] == 0){
		Trie node = createNewTrieNode(*(word + index));
		node->parent = root;
		root->childs[*(word + index)] = node;
		root->isChilds = root->isChilds + 1; 
	}
	addWord0(root->childs[*(word + index)], word, index + 1);
}

void addWord(Trie root, char* word){
    if(word == NULL)
		return; // do nothing
	else
		addWord0(root, word, 0);
}

Trie search0(Trie root, char* key, short index){
	if(root == NULL)
		return NULL;
	else if(index == strlen(key))
		if(root->isCompleteWord)
			return root;
		else
			return NULL;
	else
		return search0(root->childs[*(key + index)], key, index +1);
}

int search(Trie root, char* key){
	Trie node = search0(root,key,0);
	if(node == NULL)
		return 0;
	else
		return 1;
}

void deleteNodeFromTrie(Trie nodeToDelete){
	Trie parent = nodeToDelete->parent;
	Trie node = parent->childs[nodeToDelete->ch];
	parent->isChilds = parent->isChilds -1;
	parent->childs[nodeToDelete->ch] = 0; // set null
	free(node); // free the node
}
int delete0(Trie nodeToDelete){
	Trie parent = nodeToDelete->parent;
	deleteNodeFromTrie(nodeToDelete);
	if(parent != NULL && parent-> isChilds == 0)
		return delete0(parent);
	else
		return 1;
}

int delete(Trie root, char* key){
	Trie nodeToDelete = search0(root,key,0);
	if(nodeToDelete == NULL)
		return 0;
	if(!nodeToDelete->isCompleteWord)
		return 0;
	if(nodeToDelete->isChilds){
		nodeToDelete->isCompleteWord = 0;
		return 1;
	}
	return delete0(nodeToDelete);	
}

char* appendChar(char* prefix, char ch){
	int length = strlen(prefix);
	char* newPrefix = malloc(length + 2);
	strcpy(newPrefix, prefix); 
	newPrefix[length] = ch;
	newPrefix[length + 1] = 0;
	return newPrefix;
}

void printAllWords0(Trie root, char* prefix){
	if(root->isCompleteWord)
		printf("%s ",prefix);
	else{
		for(int i = 0; i < ALPHABET; i++){
			Trie node = root->childs[i];
			if(node != 0){
				char* newPrefix = appendChar(prefix, node->ch);
				printAllWords0(node,newPrefix);
			}
		}
	}
}

void printAllWords(Trie root, char* prefix){
	Trie temp = root;
	int i = 0;
	while(*(prefix + i) != 0){
		if(temp->childs[*(prefix + i)] != 0)
			temp=temp->childs[*(prefix + i)];
		else
			return;
		i++;
	}
	printAllWords0(temp, prefix);
	printf("\n");
}
