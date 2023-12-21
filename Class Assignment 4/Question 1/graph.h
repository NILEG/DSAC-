#ifndef graph_H
#define graph_H
#include <iostream>
struct edge
{
	char dest;
	edge *link=NULL;
};
struct node
{
	char name;
	int index;
	edge *adj=NULL;
	node *next=NULL;
};
struct graph_control
{
	public:
		node *start=NULL;
	void insert_node(char ch, int index);
	node *find(char ch);
	void insert_edge(char source, char dest);
	void delete_node(char ch);
	void delete_edge(char source, char dest);
	void delnode_edge(char dest);
	void display();
	void bfs(char v);
	void dfs(char v);
};
#endif
