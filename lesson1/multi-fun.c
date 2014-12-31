#include <stdio.h>

typedef int (*multi_fun_t)(int a,int b);
#define NUM 3

int fun_add(int a,int b)
{
	return (a) + (b);
}

int fun_sub(int a,int b)
{
	return (a) - (b);
}

int fun_MUL(int a,int b)
{
	return (a)*(b);
}

multi_fun_t fun_array[NUM]; 

int execute_fun(int a,int b)
{
	static int i = 0;
	int result = 0;

	result = fun_array[i](a,b);

	i = (i+1)%NUM;

	return result;
}

int main()
{
	int ret;
	fun_array[0] = fun_add;
	fun_array[1] = fun_sub;
	fun_array[2] = fun_MUL;

	ret = execute_fun(20,10);
	printf("the result is %d\n",ret);
	ret = execute_fun(20,10);
	printf("the result is %d\n",ret);
	ret = execute_fun(20,10);
	printf("the result is %d\n",ret);
	ret = execute_fun(20,10);
	printf("the result is %d\n",ret);

	return 0;
}
