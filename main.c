#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x){
	return (x*x + x -6);
}

double phi(double x, double xant){
	double fx = f(x);
	double fxant = f(xant);
	return (((xant*fx) - (x*fxant))/(fx - fxant));
}

int main(){
	double x = 3, xant = 1, xprox;
	double fx, p = 0.0001;
	int k = 0;

	system("clear");

	printf("======== MÉTODO DA SECANTE ========\n\n");

	printf(" K |    Xn   |   |f(Xn)|\n---------------------------\n");
	printf("%2d | %.5f |   %2.5f\n", k, xant, fabs(f(xant)));
	printf("%2d | %.5f |   %2.5f\n", ++k, x, fabs(f(x)));
	do{
		xprox = phi(x, xant);
		xant = x;
		x = xprox;
		
		printf("%2d | %.5f |   %2.5f\n", ++k, x, fabs(f(x)));
	
	}while(fabs(f(x))>p);

	printf("\n\n\n\n");

	printf("A raiz encontrada pelo método da secante é: %.5lf\n",phi(x, xant));
}

