#include <stdio.h>

int main()
{
	unsigned int killer = 'A';
	int i;
	int flags = 0;

	for(killer = 'A'; killer <= 'D'; killer++){
		flags = (killer == 'B' || killer == 'C' || killer == 'D');
		flags += (killer == 'C');
		flags += (killer =='A' || killer == 'D');
		flags += (killer == 'C');
		if(flags == 2){
			printf("the killer is %c\n",killer);
			break;
		}
	}
	
	return 0;
}
