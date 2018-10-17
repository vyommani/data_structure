#include "TernarySearchTree.h"

Tree createTST(){
	Tree tst=NULL;
	tst = insert(tst,"i", 2);
	tst = insert(tst,"just", 3);
	tst = insert(tst,"met", 4);
	tst = insert(tst,"this", 32);
	tst = insert(tst,"is", 31);
	tst = insert(tst,"crazy",29);
	tst = insert(tst,"call", 1);
	tst = insert(tst,"me", 11);
	tst = insert(tst,"maybe",13);
	tst = insert(tst,"back",14);
	tst = insert(tst,"tomuch",21);
	tst = insert(tst,"car",10);
	tst = insert(tst,"maruti", 28);
	return tst;
}

int main(void){
   Tree tst=createTST();
   printf("Getting the value of 'maybe' =%d\n", get(tst,"maybe"));
   printf("Getting the value of 'is' =%d\n", get(tst,"is"));
   printf("Resetting the value of 'maybe' to 23\n");
   tst = insert(tst,"maybe", 23);
   printf("Getting the value of 'maybe' after resetting =%d\n", get(tst,"maybe"));
   return 0;
}
