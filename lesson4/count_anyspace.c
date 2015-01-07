#include <stdio.h>

int count_anyspace(const void *p,int num)
{
	const unsigned char *tmp = (const unsigned char *)p;
	unsigned char workc;
	unsigned int result = 0;
	int i,j;
	 
	for(i = 0; i < num; i++){
		workc = tmp[i];
		while(workc){
			if(workc & 0x1){
				result++;
			}
			workc>>=1;
		}
	}

	return result;
}

int main()
{
	int buf[]={0xff1,0x22};

	printf("the buf num'1s is %d\n",count_anyspace(buf,sizeof(buf)));

	return 0;
}

