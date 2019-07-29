#include<stdio.h>
#include "funcs.h"
int multiplication(struct complex_number number1, struct complex_number number2, struct complex_number result)
{
        result.real=number1.real*number2.real-number1.image*number2.image;
        result.image=number1.real*number2.image+number1.image*number2.real;
        printf("Result is\n%d %di\n",result.real,result.image);
        return 0;
}

