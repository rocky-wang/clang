#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define GUESS_NUM 8
int main()
{
	int rand_num;
	int guess_num;
	int i;
	int ret;

	srand(time(NULL));
	rand_num = (rand() % 100) + 1;

	for(i = 0; i < GUESS_NUM; i++){
		printf("[The %d Chance]Please input you guess num:",i+1);
		ret = scanf("%d",&guess_num);
		if(ret != 1){
			fprintf(stderr,"Please input correct format num,you waste a chance.");
			continue;
		}
		if(guess_num == rand_num){
			printf("The guess num %d Correct!!!\n",guess_num);
			break;
		}
		else if(guess_num > rand_num){
			printf("The Guess num is big...,try again!\n");
		}
		else{
			printf("The Guess num is small...,try again!\n");
		}
	}
	if(i == GUESS_NUM){
		printf("Sorry,Game over!!!\n");
	}

	return 0;
}

