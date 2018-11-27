#include<stdio.h>
#include<math.h>

static double TOLERANCE = 0.00000000001;

double squareRoot(double d) {
    double newX = 0, x = d;
    if(d < 0)
		return -1;
	else if(d == 0 || d == 1)
		return d;
	else{
		do {
			newX = 0.5 * (x + d / x);
			if (fabs(x - newX) < TOLERANCE)
				break;
			x = newX;
		} while (1);
    
		return newX;
	}
}

int main(){
	printf("Square root of 16 is %g\n", squareRoot(16));
    printf("Square root of 52 is %g\n", squareRoot(52));
    printf("Square root of 15 is %g\n", squareRoot(15));
    printf("Square root of 625 is %g\n", squareRoot(625));
    printf("Square root of 167 is %g\n", squareRoot(167));
	return 0;
}
