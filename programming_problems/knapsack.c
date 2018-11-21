#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max(x,y) ((x)>(y)?(x):(y))

static int** arr;
static int values[]  = {-1, 7,9,5,12,14,6,12}; // first item is dummy
static int weights[] = {-1, 3,4,2,6, 7, 3, 5}; // first item is dummy

int Value(int item, int capacity){
    if(item ==0 || capacity == 0)
	return 0;
    else{
        if(weights[item] > capacity){ //item can not fit into knapsack
	    return Value(item-1, capacity);
	}else{
	    // choose the max(either select the item or don't select the item
	    return max( values[item] + Value(item - 1, capacity - weights[item]), Value(item-1, capacity));
	}
    }
}

int Value_DP(int item, int capacity){
    if(item ==0 || capacity == 0)
	return 0;
    else{
	if(arr[item][capacity] != -1)
	    return arr[item][capacity];
	else{
	    int result;
            if(weights[item] > capacity){ //item can not fit into knapsack
	        result = Value(item-1, capacity);
	    }else{
	    // choose the max(either select the item or don't select the item
	        result = max( values[item] + Value(item - 1, capacity - weights[item]), Value(item-1, capacity));
	    }
            arr[item][capacity] = result;
            return result;	    
        }
    }
}

int main(void){

    int size = 15;
    int r = sizeof(values) / sizeof(values[0]);

    arr =  malloc(sizeof(int *) * r);
    
    for(int i=0;i < r; i++)
        arr[i]=malloc(sizeof(int) * (size + 1));
    
    for(int i=0;i < r; i++)
        for(int j=0;j < (size + 1); j++)
	    arr[i][j]=-1;
    
    printf("\n Max value =%d\n", Value(7,15));
    printf("\n Max value using DP =%d\n", Value_DP(7,15));
    return 0;
}

