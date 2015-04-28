#include "slink.h"
#include <stdio.h>

int main()
{
	plink ex1Head;
	plink oplink,tmplink;
	int i;
	
	ex1Head = createLinkHead();
	if(ex1Head == NULL){
		printf("ex1 error!\n");
		return -1;
	}
	
	/*产生一个测试链表数据*/
	oplink = ex1Head;
	for(i = 0; i < 5; i++){
		oplink = insert_node(oplink,i+2);
	}
	
	printf("raw data is :\n");
	show_link(ex1Head);
	
	/*倒置链表数据*/
	oplink = ex1Head->next;
	ex1Head->next = NULL;
	while(oplink){
		tmplink = oplink;
		oplink = oplink->next;
		tmplink->next = ex1Head->next;
		ex1Head->next = tmplink;
	}
	printf("resver data is :\n");
	
	show_link(ex1Head);
	
	return 0;
}