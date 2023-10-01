#include "my_header.h"
#include<iostream>
void control::create(string data)
{
	struct node *temp=new node();
	temp->data=data;
	temp->link=NULL;
	if(tail == NULL)
	{
		tail=temp;
		tail->link=tail;
	}
	else
	{
		temp->link=tail->link;
		tail->link=temp;
		tail=temp;
	}
}
void control::display()
{
	struct node *q=tail->link;
	do
	{
		cout<<q->data<<endl;
		q=q->link;
	}while(q != tail->link);
}
void control::del(int pos)
{
	struct node *q=tail->link, *temp;
	if(pos == 1)
	{
		tail->link=tail->link->link;
		delete(q);
		return ;
	}
	for(int i=1; i<pos-1; i++)
	{
		q=q->link;
	}
	temp=q;
	q=q->link;
	temp->link=q->link;
	if(q==tail)
	{
		tail=temp;
	}
	delete(q);
}
