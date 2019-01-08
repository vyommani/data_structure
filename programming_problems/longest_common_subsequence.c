#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max(x,y) ((x)>(y)?(x):(y))

static int** arr;
static int WIDTH;

int LCS(char* first, int m, char* second, int n){
    if(m == 0 || n == 0)
	return 0;
    else{
        if(first[m] != second[n])
	    return max(LCS(first, m-1, second, n), LCS(first, m, second, n-1));
	else
	    return 1+ LCS(first, m-1, second, n-1);
    }
}
/*
 * 
 */
int LCS_DP(char* first, int m, char* second, int n){
    if(m == 0 || n == 0)
	return 0;
    else{
	if(arr[m][n] != -1)
	    return arr[m][n];
	else{
	    int result;
	    if(first[m] != second[n])
	        result = max(LCS_DP(first, m-1, second, n), LCS_DP(first, m, second, n-1));
	    else
	        result = 1 + LCS_DP(first, m-1, second, n-1);
	    arr[m][n] = result;
	    return result;
        }
    }
}

int main(void){
  char* first="ABAZDC";
  char* second="BACBAD";
  int r = strlen(first);
  int c = strlen(second);
  WIDTH = c;

  arr =  malloc(sizeof(int*)* r+1);
  for(int i=0;i<r+1;i++)
     arr[i]=malloc(sizeof(int)*c+1);
  for(int i=0;i<r+1;i++)
     for(int j=0;j <c+1;j++)
	     arr[i][j]=-1;
  memset(arr, -1, sizeof(r * c * sizeof(int*)));

  printf("\n Longest Common sub sequence=%d\n", LCS(first,6,second,6));
  printf("\n Longest Common sub sequence=%d\n", LCS_DP(first,r, second,c));
  printf("\n");
  return 0;
}

