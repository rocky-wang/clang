#include <stdio.h>

void perm_show(unsigned int perm)
{
	int i;

	for(i = 8; i >= 0; i--){
		if(perm & (0x1<<i)){
			switch(i %3){
				case 2:
					printf("r");
					break;
				case 1:
					printf("w");
					break;
				case 0:
					printf("x");
					break;
			}
		}
		else{
			printf("-");
		}
	}	
	printf("\n");
}

int main()
{
	unsigned int var = 0657;

	perm_show(var);

	return 0;
}
