#include <stdio.h>

int del_str_space(char *str)
{
	int loop = 0;
	int rep = 0;

	if(str == NULL){
		return -1;
	}

	while(str[loop]){
		if(str[loop] != ' '){
			str[rep] = str[loop];
			rep++;
		}
		loop++;
	}
	str[rep] = 0;

	return 0;
}

int main()
{
	char buf[] = "  he   ll o  ";

	if(del_str_space(buf) != 0){
		printf("error input buf!\n");
		return -1;
	}

	printf("the buf is %s\n",buf);

	return 0;
}
