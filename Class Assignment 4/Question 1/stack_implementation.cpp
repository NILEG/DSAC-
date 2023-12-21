#include<iostream>
#include "stack.h"
#include "graph.h"
using namespace std;

void stk_control::push(node * vertix)
{
	struct Stack *temp=new Stack();
	temp->vertix=vertix;
	temp->link=top;
	top=temp;
}

node * stk_control::pop()
{
	if(top !=NULL)
	{
		node * vertix=top->vertix;
		top=top->link;
		return vertix;
	}
	else
	{
		cout<<"Stack underflow: ";
		return NULL;
	}
}
void stk_control::display()
{
	struct Stack *q=top;
	while(q != NULL)
	{
		cout<<q->vertix->name<<endl;
		q=q->link;
	}
}
