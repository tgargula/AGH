// random.c - simple example of setting random number seeds with time

#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double gen(double a, double b) {
	return (b - a) * drand48() + a;
}

int main(void) {
	srand48(time(NULL));	//	use time in seconds to set seed

//	lrand48() returns non-negative long integers
//	uniformly distributed over the interval [0, 2^31).
//	drand48() returns non-negative double precision floating-point
//	values  uniformly  distributed  between [0.0, 1.0).

	printf("\n");
	printf("5 long random numbers:\n");
	for (int i = 0; i < 5; ++i) printf("%ld ", lrand48()); 
	printf("\n\n");
	printf("5 double random numbers:\n");
	for (int i = 0; i < 5; ++i) printf("%f ", drand48()); 
	printf("\n\n");
	printf("5 double random numbers from [-10, 10):\n");
	for (int i = 0; i < 5; ++i) printf("%f ", gen(-10., 10.)); 
	printf("\n\n");
	return 0;
}