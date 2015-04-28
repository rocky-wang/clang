#ifndef SLINK_H
#define SLINK_H

typedef struct _node{
	int value;
	struct _node *next;
}link,*plink;

plink createLinkHead();

plink insert_node(plink node,int data);

int show_link(plink node);

#endif
