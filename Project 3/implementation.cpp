#include "my_header.h"
#include<iostream>
void control::create(string data, struct node *& tail)
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
void control::display_mid(struct node *& tail, struct node * &list1, struct node * &list2)
{
	struct node *q=tail->link, *temp;
	if(count(tail) % 2 == 0) //Even Case
	{
		for(int i=1; i<=int(count(tail)/2); i++)
		{
			create(q->data, list1);
			q=q->link;
		}
		for(int i=1; i<=int(count(tail)/2); i++)
		{
			create(q->data, list2);
			q=q->link;
		}
		cout<<"The nodes are even. The mid point is between node "<<int(count(tail)/2)<<" and "<<int(count(tail)/2)+1<<endl;
		cout<<"First Slice"<<endl;
		display(list1);
		cout<<"Second Slice"<<endl;
		display(list2);
	}
	else //Odd Case
	{
		for(int i=1; i<=int(count(tail)/2)+1; i++)
		{
			create(q->data, list1);
			q=q->link;
		}
		for(int i=1; i<=int(count(tail)/2); i++)
		{
			create(q->data, list2);
			q=q->link;
		}	
		cout<<"Mid Node is at "<<int(count(tail)/2)+1<<" position"<<endl;
		cout<<"First Slice"<<endl;
		display(list1);
		cout<<"Second Slice"<<endl;
		display(list2);
	}
	
}
int control::count(struct node *& tail)
{
	int counter=0;
	struct node * q=tail->link;
	do
	{
		q=q->link;
		counter++;
	}while(q != tail->link);
	return counter;
}
void control::display(struct node * &tail)
{
	struct node *q=tail->link;
	do
	{
		cout<<q->data<<endl;
		q=q->link;
	}while(q != tail->link);
}
