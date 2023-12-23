#ifndef my_header_H
#define my_header_H
#include <iostream>
struct edge
{
	char dest;
	int cost=1;
	edge *link=NULL;
};
struct Queue_Edge //remember the vertics of edge
{
	char u='?', v='?';
	int weight=1;
	Queue_Edge *link=NULL;
};
struct node
{
	char name;
	char previous='?';
	edge *adj=NULL;
	node *next=NULL;
};
struct graph_control
{
	public:
		node *start=NULL;
		Queue_Edge *front=NULL;
	void insert_node(char ch);
	node *find(char ch);
	void insert_edge(char source, char dest, int cost);
	void delete_node(char ch);
	void delete_edge(char source, char dest);
	void delnode_edge(char dest);
	void display();
	void make_tree();
	int vertices_len();
	void insert_edge_queue(char src, char dest, int weight);
	Queue_Edge* pop_queue_edge();
};
#endif
