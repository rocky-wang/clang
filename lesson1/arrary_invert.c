#include <stdio.h>
#include <stdio.h>

#define ARRAY_SIZE(name)	(sizeof(name)/sizeof((name)[0]))

void invert_array(int *array,int num)
{
	int i;
	int tmp;

	for(i = 0; i < num/2; i++){
		tmp = array[i];
		array[i] =  array[num-i-1];
		array[num-i-1] = tmp;
	}
}

void show_array(int *array,int num)
{
	int i;

	for(i = 0; i < num; i++){
		printf("the array[%d] is %d\n",i,array[i]);
	}
}

int main()
{
	int integer_array[]={1,2,3,4,5,6,7};

	invert_array(integer_array,ARRAY_SIZE(integer_array));

	show_array(integer_array,ARRAY_SIZE(integer_array));

	return 0;
}

