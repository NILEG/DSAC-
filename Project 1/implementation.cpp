#include<iostream>
#include "my_header.h"
using namespace std;

void control::create(string data)
{
	struct node *temp=new node(), *q;
	temp->data=data;
	temp->link=NULL;
	if(start == NULL)
	{
		start=temp;
	}
	else
	{
		q=start;
		while(q->link !=NULL)
		{
			q=q->link;
		}
		q->link=temp;
	}
}
void control::display()
{
	struct node *q=start;
	while(q != NULL)
	{
		cout<<q->data<<endl;
		q=q->link;
	}
}
void control::del(int pos)
{
	struct node *q=start, *temp;
	if(pos==1)
	{
		start=q->link;
		delete(q);
		return ;
	}
	for(int i=1; i<pos-1; i++)
	{
		if(q->link == NULL)
		{
			cout<<"Index out of range"<<endl;
			return;
		}
		else
		{
			q=q->link;
		}
	}
	temp=q;
	q=q->link;
	temp->link=q->link;
	delete(q);
}
