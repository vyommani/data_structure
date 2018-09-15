#include<stdio.h>
#include<stdlib.h>
/*
Given a array of integers, return whether it can be partitioned into two subarrays  whose sums are the same.

For example, given the array {15, 5, 20, 10, 35, 15, 10}, it would return true,

since we can split it up into {15, 5, 10, 15, 10} and {20, 35}, which both add up to 55.*/

int comprator(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int partitionArray(int arr[], int length){
    int start = 1, end = length -1;
    int first=arr[0],second = arr[end];
    if(arr == NULL || length == 1)
	return 0;
    else if( length == 2)
	return arr[0] == arr[1];
    while(start < end){	
	if(first+arr[start] < second){
	    first+=arr[start++];
	}else{
	    second+=arr[end--];
	}
    }
    return (first == second);
}

int main(void){
    int arr[] ={15, 5, 20, 10, 35, 15, 10};
    qsort(arr,sizeof(arr)/sizeof(arr[0]),sizeof(int), comprator);
    printf("\nCan array be partitioned into to subarray of equal sum=%d\n",partitionArray(arr,sizeof(arr)/sizeof(arr[0])));
    return 0;
}
