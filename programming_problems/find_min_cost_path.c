#include<stdio.h>
#define min(x,y) ((x)>(y)?(y):(x))

/*
 *
 * Given a mxn matrix where each cell has a cost associated with it,
 * Write a function that find the minimum cost to reach the last cell(n,m)
 * from cell(0,0) in the manner specified below. You can only move one unit right or one unit down.
 * 
 *  (x,y) --> (x+1, y) || (x,y) --> (x,y+1)
 *
 *  cost(m,n) = cost[m][n] + min(cost to reach cell(m, n-1), cost to reach cell(m-1, n))
 * 
 * @author vyom tewari
 */

int findOptimalPath(int arr[][5], int x, int y) {
	if (x == 0 && y ==  0) {
		return arr[x][y];
    } else if (x == 0) {
		return arr[0][y] + findOptimalPath(arr, x, y -1);
    } else if (y == 0) {
		return arr[x][0] + findOptimalPath(arr, x -1, y);
    } else {
        return arr[x][y] + min(findOptimalPath(arr, x - 1, y), findOptimalPath(arr, x, y - 1));
    }
}

int main(){
	int arr[][5] = {
		{ 4, 7, 8, 6, 4 },
		{ 6, 7, 3, 9, 2 },
		{ 3, 8, 1, 2, 4 },
		{ 7, 1, 7, 3, 7 },
		{ 2, 9, 8, 9, 3 }
      };
    printf("\nMinimam cost is %d\n", findOptimalPath(arr,4,4));
    
	int arr1[][5] = {
		{ 1, 1, 1, 1, 1 },
		{ 6, 7, 3, 9, 1 },
		{ 3, 8, 1, 2, 1 },
		{ 7, 1, 7, 3, 1 },
		{ 2, 9, 8, 9, 1 }
      };
    printf("\nMinimam cost is %d\n", findOptimalPath(arr1,4,4));
    
    return 0;
}
