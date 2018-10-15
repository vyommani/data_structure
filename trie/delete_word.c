#include<stdio.h>
#include<stdlib.h>
#include "trie.h"

Trie createTrie(){
	Trie trie = createNewTrieNode(' ');
    addWord(trie, "bear");
    addWord(trie, "bell");
    addWord(trie, "bid");
    addWord(trie, "bull");
    addWord(trie, "buy");
    addWord(trie, "buyer");
    addWord(trie, "stock");
    addWord(trie, "stop");
    return trie;
}

int main(void){
    Trie trie = createTrie();
    printf("\nSearching for word 'buy' :%s\n",             search(trie,"buy") == 1 ? "true" :"false");
    printf("\nDeleting the word 'buy': %s",                delete(trie,"buy") == 1 ? "true" :"false");
    printf("\nSearching 'buy' after deleting it: =%s\n",   search(trie,"buy") == 1 ? "true" : "false");

    printf("\nSearching for word 'buyer' :%s\n",           search(trie,"buyer") == 1 ? "true" : "false");

    printf("\nSearching for word 'stop' :%s\n",            search(trie,"stop") == 1 ? "true" :"false");
    printf("\nDeleting the word 'stop': %s",               delete(trie,"stop") == 1 ? "true" :"false");
    printf("\nSearching 'stop' after deleting it: =%s\n",  search(trie,"stop") == 1 ? "true" : "false");
    
    printf("\n Searching for word 'stock' :%s\n",          search(trie,"stock") == 1 ? "true" :"false");
    printf("\n Searching for word 'stack' :%s\n",          search(trie,"stack") == 1 ? "true" :"false");
            
    return 0;
}
