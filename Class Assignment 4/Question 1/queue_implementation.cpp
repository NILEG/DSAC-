#include<iostream>
#include "queue.h"
#include "graph.h"
using namespace std;

void control::push(node *vertix)
{
	struct Queue *temp=new Queue();
	temp->vertix=vertix;
	if(front == NULL)
	{
		front = temp;
	}
	else
	{
		rear->link=temp;
	}
	rear=temp;
}

node* control::pop()
{
	if(front !=NULL)
	{
		node *data=front->vertix;
		front=front->link;
		return data;
	}
	else
	{
		cout<<"Stack underflow: ";
		rear=NULL;
		front=NULL;
		return NULL;
	}
}
void control::display()
{
	struct Queue *q=front;
	while(q != NULL)
	{
		cout<<q->vertix->name<<endl;
		q=q->link;
	}
}
