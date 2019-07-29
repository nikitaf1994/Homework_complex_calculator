#include<stdio.h>
#include"funcs.h"
int addition(struct complex_number number1, struct complex_number number2, struct complex_number result)
{
	result.real=number1.real+number2.real;
	result.image=number1.image+number2.image;
	printf("Result is\n%d %di\n",result.real,result.image);
	return 0;
}

