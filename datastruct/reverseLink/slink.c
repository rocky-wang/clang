#include <stdio.h>
#include <stdlib.h>
#include "slink.h"

plink createLinkHead()
{
	plink head = NULL;
	
	head = (plink)malloc(sizeof(link));
	if(head == NULL){
		fprintf(stderr,"create link head failed!\n");
		return NULL;
	}
	
	head->value = 0;
	head->next = NULL;
	
	return head;
}

plink insert_node(plink node,int data)
{
	plink new_node = NULL;
	
	new_node = (plink)malloc(sizeof(link));
	if(new_node == NULL){
		fprintf(stderr,"create new node failed!\n");
		return NULL;
	}
	
	new_node->value = data;
	new_node->next = node->next;
	node->next = new_node;
	
	return new_node;
}

int show_link(plink node)
{
	if(node == NULL)
		return -1;
		
	while(node){
		printf("the node value is %d\n",node->value);
		node = node->next;
	}
	
	return 0;
}
