#include <stdio.h>
#include <stdlib.h>
#include "slink.h"

plink createLoopHead()
{
	plink head = NULL;
	
	head = (plink)malloc(sizeof(link));
	if(head == NULL){
		fprintf(stderr,"create link head failed!\n");
		return NULL;
	}
	
	head->value = 1;
	head->next = head;
	
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

int del_node(plink node)
{
	plink tmp = node->next;
	if(tmp == NULL)
		return -1;
	
	printf("del node is %d\n",tmp->value);
	if(tmp != node){
		node->next = tmp->next;
		free(tmp);
		return 0;
	}
	else{
		node->next = NULL;
		free(node);
		return 1;
	}
}
