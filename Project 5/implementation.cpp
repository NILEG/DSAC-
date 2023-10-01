#include "my_header.h"
#include<iostream>
using namespace std;
void control::create(string data)
{
	struct node *temp=new node(), *q;
	temp->data=data;
	temp->next=NULL;
	temp->pre=NULL;
	if(tail == NULL)
	{
		tail=temp;
		temp->next=tail;
		temp->pre=tail;
	}
	else
	{
		q=tail->next;
		do
		{
			q=q->next;
		}while(q != tail->next);
		
		tail->next->pre=temp;
		temp->next=tail->next;
		tail->next=temp;
		temp->pre=tail;
		tail=temp;
	}
}
void control::fdisplay()
{
	struct node *q=tail->next;
	if( q != NULL)
	{
		do
		{
			cout<<q->data<<endl;
			q=q->next;
		}while(q != tail->next);
	}
}
void control::bdisplay()
{
	struct node *q=tail;
	if( q != NULL)
	{
		do
		{
			cout<<q->data<<endl;
			q=q->pre;
		}while(q != tail);
	}	
}
void control::del(int pos)
{
	struct node *q=tail->next;
	if(pos == 1)
	{
		tail->next=tail->next->next;
		tail->next->pre=tail;
		delete(q);
		return ;
	}
	for(int i=1; i<pos; i++)
	{
		q=q->next;
	}
	q->next->pre=q->pre;
	q->pre->next=q->next;
	if(q==tail)
	{
		tail=q->pre;
	}
	delete(q);
}
