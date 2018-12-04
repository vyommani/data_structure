#include<stdio.h>
#include "BitArray.h"

int main(void){
	
    Array array = createBitArray(129);
    
    if(set(array,7,1)!= -1){
		printf("\n setting the 7th bit of array\n");
	}else{
		printf("\n we have error in setting the bit\n");
	}
	
	if(get(array,7)){
		printf("\n 7th bit got set\n");
	}
	
	if(set(array,127,1)!= -1){
		printf("\n setting the 127th bit of array\n");
	}else{
		printf("\n we have error in setting 127 the bit\n");
	}
	
	if(get(array,127)){
		printf("\n 127th bit got set\n");
	}
	
	if(set(array,56,1)!= -1){
		printf("\n setting the 56th bit of array\n");
	}else{
		printf("\n we have error in setting 56 the bit\n");
	}
	
	if(get(array,56)){
		printf("\n 56th bit got set\n");
	}
	
	if(set(array,100,1)!= -1){
		printf("\n setting the 100th bit of array\n");
	}else{
		printf("\n we have error in setting 100 the bit\n");
	}
	
	if(get(array,100)){
		printf("\n 100th bit got set\n");
	}
	
	if(!get(array,99)){
		printf("\n 99th bit not set\n");
	}
	
    if(!get(array,0)){
		printf("\n 0th bit not set\n");
	}
    return 0;
}
