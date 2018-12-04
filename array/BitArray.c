#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "BitArray.h"

Array createBitArray(int size){
	if(size <=0){
		return 0;
	}
	Array arr= malloc(sizeof(struct BitArray));
	if(size % 8 == 0){
		arr->array= malloc(size / 8);
		memset(arr->array, 0, size / 8);
	}else{
		arr->array= malloc(size / 8 + 1);
		memset(arr->array, 0, size / 8 + 1);
	}
	arr->size = size;
	return arr;
}

int set0(Array arr, int index, int val) {
	int element = index / 8;
    int offset = index % 8;
    if (val == 1) {
        arr->array[element] |= (1 << offset);
    } else {
        arr->array[element] &= ~(1 << offset);
    }
    return 1; // bit set successfully.
}

int set(Array arr, int index, int val) {
	if (index < 0)
		return -1;
    if (index > arr->size)
		return -1;
    if (val < 0 || val > 1)
		return -1;
    return set0(arr, index, val);
}

int get0(Array arr, int index) {
    int element = index / 8;
    int offset = index % 8;
    return (arr->array[element] & (1 << offset));
}

int get(Array arr, int index) {
    if (index < 0)
		return -1;
    if (index > arr->size)
		return -1;
    return get0(arr, index);
}

int isSet(Array arr, int index) {
    return get(arr, index) == 1;
}

void clearBit(Array arr, int index) {
    set(arr, index, 0);
}
