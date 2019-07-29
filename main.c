#include<stdio.h>
#include<dlfcn.h>
#include"funcs.h"

int main()
{
	void *ext_library;
	int(*ptr)(struct complex_number number1, struct complex_number number2, struct complex_number result);
	struct complex_number number1;
	struct complex_number number2;
	struct complex_number result;
	int menu=0;
	printf("Input 1st number real\n");
	scanf("%d", &number1.real);
	printf("Input 1st number image\n");
        scanf("%d", &number1.image);
	printf("Input 2nd number real\n");
        scanf("%d", &number2.real);
        printf("Input 2nd number image\n");
        scanf("%d", &number2.image);
	printf("Choose operation\n1)Addition\n2)Subtraction\n3)Multiplication\n4)Division\n");
        scanf("%d", &menu);
	if (menu==1)
	{
		ext_library=dlopen("./addition.so",RTLD_LAZY);
        	if(!ext_library)
        	{
                	fprintf(stderr,"dlopen() error: %s\n", dlerror());
                	return 1;
        	};
	ptr=dlsym(ext_library, "addition");
	}
	else if (menu==2)
        {
		ext_library=dlopen("./substraction.so",RTLD_LAZY);
                if(!ext_library)
                {
                        fprintf(stderr,"dlopen() error: %s\n", dlerror());
                        return 1;
                };
        ptr=dlsym(ext_library, "substraction");
        }
	else if (menu==3)
        {
		ext_library=dlopen("./multiplication.so",RTLD_LAZY);
		if(!ext_library)
                {
                        fprintf(stderr,"dlopen() error: %s\n", dlerror());
                        return 1;
                };

        ptr=dlsym(ext_library, "multiplication");
        }
	else if (menu==4)
        {
		ext_library=dlopen("./division.so",RTLD_LAZY);
        	if(!ext_library)
                {
                        fprintf(stderr,"dlopen() error: %s\n", dlerror());
                        return 1;
                };
	ptr=dlsym(ext_library, "division");
        }
	else
	{
	printf("Incorrect option!\n");
	return 0;
	}
	ptr(number1,number2,result);
	dlclose(ext_library);
}
