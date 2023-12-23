#ifndef my_header_H
#define my_header_H
#include <iostream>
struct edge
{
	char dest;
	int cost=1;
	edge *link=NULL;
};
struct node
{
	char name;
	int distance=9999;//infinity
	int status=0;
	char previous='?';
	edge *adj=NULL;
	node *next=NULL;
};
struct graph_control
{
	public:
		node *start=NULL;
	void insert_node(char ch);
	node *find(char ch);
	void insert_edge(char source, char dest, int cost);
	void delete_node(char ch);
	void delete_edge(char source, char dest);
	void delnode_edge(char dest);
	void display();
	void findpath(char src, char dest);
	void show_path(char u, char src);
};
#endif
