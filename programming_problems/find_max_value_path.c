#include<stdio.h>
#define max(x,y) ((x)>(y)?(x):(y))

/*
 *
 * Write a function that, given a matrix of size N*M describing the number of
 * coins lying on each square of a N*M-sized grid, returns the maximal number of
 * coins the machine can collect while moving from the square (0, 0) to the
 * square (N, M) in the manner specified above.
 *
 * valid moves (x,y) --> (x+1, y) || (x,y) --> (x,y+1)
 *
 * @author vyom tewari
 */

int getMaxCoinsCollected(int arr[][5], int x, int y) {
	if (x == 0 && y ==  0) {
		return arr[x][y];
    } else if (x == 0) {
		return arr[0][y] + getMaxCoinsCollected(arr, x, y -1);
    } else if (y == 0) {
		return arr[x][0] + getMaxCoinsCollected(arr, x -1, y);
    } else {
        return arr[x][y] + max(getMaxCoinsCollected(arr, x - 1, y), getMaxCoinsCollected(arr, x, y - 1));
    }
}

int main(){
	int arr[][5] = {
            {0, 0, 0, 0, 10},
            {0, 0, 0, 0, 10},
            {0, 0, 0, 10, 0},
            {0, 0, 10, 0, 0},
            {0, 10, 0, 0, 0},
            {10, 0, 0, 0, 10}
            };
    printf("\nMax collected coins is %d\n", getMaxCoinsCollected(arr,5,4));
    
    int arr1[][5] = {
            {2, 5, 10, 0, 10},
            {5, 5, 1, 10, 10},
            {5, 1, 1, 10, 0},
            {2, 1, 10, 5, 2},
            {1, 10, 0, 2, 5},
            {10, 1, 1, 5, 5}
            };
    printf("\nMax collected coins is %d\n", getMaxCoinsCollected(arr1,5,4));
    
    int arr2[][5] = {
            {5, 5, 5, 5, 5},
            {1, 1, 1, 1, 5},
            {1, 1, 2, 1, 5},
            {1, 5, 1, 2, 5},
            {2, 2, 2, 2, 5},
            {1, 1, 1, 2, 5}
            };
    printf("\nMax collected coins is %d\n", getMaxCoinsCollected(arr2,5,4));
    
    return 0;
}
