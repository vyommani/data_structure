#define ALPHABET 256

typedef struct trie* Trie;

/*
 * At every node, we access an array element (one of 256), test for null,
 * and take a branch. Unfortunately, search tries have exorbitant space
 * requirements. Nodes with 26-way branching typically occupy 232 bytes,
 * and 256-way nodes consume couple of kilobyte(2072).
 * 
 */

struct trie
{
    char ch;
    Trie childs[ALPHABET];
    Trie parent;
    short isCompleteWord;
    short isChilds;
};

void addWord(Trie, char*);
int search(Trie, char*);
int delete(Trie, char*);
void printAllWords(Trie, char*);
Trie createNewTrieNode(char);
