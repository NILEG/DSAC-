#ifndef stack_H
#define stack_H
#include "graph.h"
#include <iostream>
using namespace std;
struct Stack
{
	node *vertix=NULL;
	struct Stack *link=NULL;
};

struct stk_control
{
	public: 
	struct Stack *top=NULL;
	
	void push(node *data);
	node * pop();
	void display();
	
};
#endif
