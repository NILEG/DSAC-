#ifndef queue_H
#define queue_H
#include "graph.h"
#include <iostream>
using namespace std;
struct Queue
{
	node *vertix=NULL;
	struct Queue *link=NULL;
};

struct control
{
	public: 
	struct Queue *rear=NULL, *front=NULL;
	
	void push(node *vertix);
	node* pop();
	void display();
	
};
#endif
