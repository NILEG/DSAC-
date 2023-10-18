#include<iostream>
#include "my_header.h"
using namespace std;

void control::push(int data)
{
	struct node *temp=new node();
	temp->data=data;
	temp->link=top;
	top=temp;
}

int control::pop()
{
	if(top !=NULL)
	{
		int data=top->data;
		struct node *temp=top;
		top=top->link;
		delete(temp);
		return data;
	}
	else
	{
		cout<<"Stack underflow: ";
		return -1;
	}
}
void control::display()
{
	struct node *q=top;
	while(q != NULL)
	{
		cout<<q->data<<endl;
		q=q->link;
	}
}
#mussaratabdullah@gmail.com
