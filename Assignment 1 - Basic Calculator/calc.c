#include "calc.h"

int value = 0;

void add(int num){
	value=value+num;
	printf("%d\n", value);
}

void subtract(int num){
	value=value-num;
	printf("%d\n", value);
}

void divide(int num){
	value=value/num;
	printf("%d\n", value);
}

void multiply(int num){
	value=value*num;
	printf("%d\n", value);
}

void mod(int num){
	value=value%num;
	printf("%d\n", value);
}
void clear(void){
	value=0;
	printf("%d\n", value);
}
