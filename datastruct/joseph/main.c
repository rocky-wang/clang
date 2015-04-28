#include <stdio.h>
#include "slink.h"

#define NUM 8

int main()
{
	plink josephHead,oplink;
	int i;
	int count;
	
	josephHead = createLoopHead();
	if(josephHead == NULL){
		printf("failed create loop head!\n");
		return -1;
	}
	
	oplink = josephHead;
	for(i = 0; i < NUM -1; i++){
		oplink = insert_node(oplink,i+2);
	}
	
	oplink = josephHead->next->next;
	printf("start count is %d\n",oplink->value);
	
	count = 0;
	while(oplink){
		count++;
		if(count == 3){
			if( del_node(oplink) != 0){
				oplink = NULL;
				break;
			}
			count = 0;
		}
		oplink = oplink->next;
	}
	
	return 0;
}