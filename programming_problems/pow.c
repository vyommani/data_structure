#include<stdio.h>
#include<stdlib.h>


/*
 * Implement integer exponentiation.
 *
 * The efficient exponentiation algorithm is based on Exponentiation by squaring, below is the algoritms.
 *      
 *                       1                    if b ==0
 *         Pow(a,b) =    a * Pow(a, b-1)      if b is odd
 *                       (Pow(a, b/2)) square if b ie even
 */
 
long Pow(int num, int exp){
    if(exp == 0) // if exp is 0
		return 1;
    else if(exp % 2 == 1) // exp is odd number
		return num * Pow(num, exp - 1);
    else{
		long partialResult = Pow(num, exp/2);
		return partialResult * partialResult;
	}
}

int main(){
    
    printf("\nPower of Pow(2,8)  is %li\n", Pow(2,8));
    printf("\nPower of Pow(2,10) is %li\n", Pow(2,10));
    printf("\nPower of Pow(3,4)  is %li\n", Pow(3,4));
    printf("\nPower of Pow(3,7)  is %li\n", Pow(3,7));
    return 0;
}
