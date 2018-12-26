#include<stdio.h>
#include<stdlib.h>

/* There is an N by M matrix of 0&1.0 represents an empty space while 1 represents a wall you cannot walk through.
 * Given N and M matrix, write a function to count the number of ways of starting at the top-left corner and getting
 * to the bottom-right corner. 
 * You can only move right or down.
 * valid moves (x,y) --> (x+1, y) || (x,y) --> (x,y+1)
 */
 static int m,n;
 
long numberOfways(int arr[][5], int x,int y){
	if(x == m && y == n)
		return 1;
	else if(arr[x][y] == 1) // if value is one then it means it is wall and you can not cross.
		return 0;
	else if(x == m)
		return numberOfways(arr, x, y + 1);
	else if( y == n)
		return numberOfways(arr, x + 1, y);
	else
		return numberOfways(arr, x + 1, y) + numberOfways(arr, x , y + 1);
}

int main(){
	m=5;
	n=4;
	int arr[][5] = {
            {0, 0, 1, 1, 1},
            {1, 0, 1, 1, 1},
            {0, 0, 0, 1, 1},
            {0, 1, 0, 1, 1},
            {0, 1, 0, 1, 1},
            {1, 1, 0, 0, 0}
            };
    printf("Number of ways %ld\n",numberOfways(arr,0,0));
	
	int arr1[][5] = {
            {0, 0, 1, 1, 1},
            {1, 0, 1, 1, 1},
            {0, 0, 0, 1, 1},
            {0, 1, 0, 1, 1},
            {0, 1, 0, 1, 1},
            {1, 1, 1, 0, 0}
            };
    printf("Number of ways %ld\n",numberOfways(arr1,0,0));
	
	int arr2[][5] = {
            {0, 0, 1, 1, 1},
            {1, 0, 0, 1, 1},
            {0, 0, 0, 1, 1},
            {0, 1, 0, 1, 1},
            {0, 1, 0, 1, 1},
            {1, 1, 0, 0, 0}
            };
    printf("Number of ways %ld\n",numberOfways(arr2,0,0));
	
	int arr3[][5] = {
            {0, 0, 1, 1, 0},
            {1, 0, 1, 1, 0},
            {0, 0, 0, 1, 0},
            {0, 1, 0, 1, 0},
            {0, 1, 0, 1, 0},
            {1, 1, 0, 0, 0}
            };
    printf("Number of ways %ld\n",numberOfways(arr3,0,0));
	
	return 0;
}
