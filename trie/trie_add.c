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
    addWord(trie, "sell");
    addWord(trie, "stock");
    addWord(trie, "stop");
    addWord(trie, "vyom");
    return trie;
}

int main(void){
    Trie trie = createTrie();
    printf("\n Is bear  present=%s\n", search(trie,"bear") == 1?"yes":"no");
    printf("\n Is bell  present=%s\n", search(trie,"bell") == 1?"yes":"no");
    printf("\n Is bell1 present=%s\n", search(trie,"bell1") == 1?"yes":"no");
    printf("\n Is random_word present=%s\n", search(trie,"random_word")== 1?"yes":"no");
    return 0;
}
