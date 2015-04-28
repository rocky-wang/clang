#ifndef SLINK_H
#define SLINK_H

typedef struct _node{
	int value;
	struct _node *next;
}link,*plink;

plink createLoopHead();

plink insert_node(plink node,int data);

int del_node(plink node);
//int show_link(plink node);

#endif
