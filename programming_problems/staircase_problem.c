#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static int* arr;

// you can climb upto either 1 or 2 steps at a time 
int countNumOfWays(int n){
    if(n == 0 || n == 1)
		return 1;
    else
		return countNumOfWays(n-1) + countNumOfWays(n-2);
}

// you can climb upto either 1 or 2 steps at a time 
int countNumOfWays_top_down(int n){
    if(n == 0 || n ==1)
		return 1;
    else{
		if(arr[n] != -1)
			return arr[n];
		else{
			int nw = countNumOfWays_top_down(n-1) + countNumOfWays_top_down(n-2);
			arr[n] = nw;
			return nw;
		}
    }
}

// you can climb upto either 1 or 2 steps at a time 
int countNumOfWays_bottom_up(int n){
	if(n ==0 || n ==1)
		return 1;
	else{
		int num1=1, num2=1, num3;
		for(int i = 2; i<= n ; i++){
			num3 = num1 + num2;
			num1=num2;
			num2= num3;
		}
		return num2;
	}
}

// you can climb upto either 1,3,5 steps at a time.
int countNumOfWays__1_3_5(int n){
    if(n == 0  || n ==1)
		return 1;
    else if(n >=5)
		return countNumOfWays__1_3_5(n-5) + countNumOfWays__1_3_5(n-3) + countNumOfWays__1_3_5(n-1);
    else if(n >=3)
		return countNumOfWays__1_3_5(n-3) + countNumOfWays__1_3_5(n-1);
    else
		return countNumOfWays__1_3_5(n-1);
}


int* createArray(int size){
	int* arr = (int*) malloc(sizeof(int) * (size + 1));
    memset(arr,-1,sizeof(arr) *(size + 1));
    return arr;
}

int main(void){
    // total number of steps to count
    int n=4;
    printf("\nNumber of ways(1,2 steps) you can climb 4 step is =%d\n", countNumOfWays(n));
    printf("\nNumber of ways(1,2 steps) you can climb 6 step is =%d\n", countNumOfWays(6));
    printf("\nNumber of ways(1,2 steps) you can climb 4 step is =%d\n", countNumOfWays_bottom_up(n));
    printf("\nNumber of ways(1,2 steps) you can climb 6 step is =%d\n", countNumOfWays_bottom_up(6));
	n=4;
	arr = createArray(n);
    printf("\nNumber of ways(1,2 steps) you can climb 4 step is =%d\n", countNumOfWays_top_down(n));
    n=6;
	arr = createArray(n);
    printf("\nNumber of ways(1,2 steps) you can climb 6 step is =%d\n", countNumOfWays_top_down(n));
    
    return 0;
}
