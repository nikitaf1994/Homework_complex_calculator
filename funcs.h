struct complex_number
{
        int real;
        int image;
};

int addition(struct complex_number number1, struct complex_number number2, struct complex_number result);
int substraction(struct complex_number number1, struct complex_number number2, struct complex_number result);
int multiplication(struct complex_number number1, struct complex_number number2, struct complex_number result);
int division(struct complex_number number1, struct complex_number number2, struct complex_number result);
