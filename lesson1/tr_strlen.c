#include <stdio.h>

int mystrlen(const char *str)
{
	int count = 0;
	
	if(str == NULL)
		return -1;

	while(*str){
		count++;
		str++;
	}

	return count;
}

int main(int argc,char *argv[])
{
	char *s = "hello world!";
	
	printf("the str:%s len is %d\n",s,mystrlen(s));

	return 0;
}
