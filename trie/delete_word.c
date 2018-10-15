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
    printf("\n Is buy  present=%s\n", search(trie,"buy") == 1?"yes":"no");
    delete(trie,"buy");
    printf("\n Is buy  present=%s\n", search(trie,"buy") == 1?"yes":"no");
    printf("\n Is buyer  present=%s\n", search(trie,"buyer") == 1?"yes":"no");
    delete(trie,"stop");
    printf("\n Is stop  present=%s\n", search(trie,"stop") == 1?"yes":"no");
    return 0;
}
