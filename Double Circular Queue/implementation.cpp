#include<iostream>
#include "my_header.h"
using namespace std;

void control::enqueue_right(int data)
{
	if(counter == Max && rear->link==front)
	{
		cout<<"Queue Overflow"<<endl;
	}
	else
	{
		if(nodes <Max && rear == end)
		{
			node *temp=new node();
			temp->data=data;
			if(rear == NULL)
			{
				front=temp;
				rear=temp;
				rear->link=temp;
				rear->pre=temp;
				start=temp;
				end=temp;
			}
			else
			{
				temp->link=start;
				start->pre=temp;
				rear->link=temp;
				temp->pre=rear;
				rear=temp;
				end=temp;
			}
			nodes++;
		}
		else
		{
			if(rear == NULL)
			{
				rear=start;
				front=start;
				rear->data=data;
			}
			else
			{
				rear=rear->link;
				rear->data=data;
			}
		}
		counter++;
	}
}

void control::enqueue_left(int data)
{
	if(counter == Max && rear==front->pre)
	{
		cout<<"Queue Overflow"<<endl;
	}
	else
	{
		if(nodes <Max && front == start)
		{
			node *temp=new node();
			temp->data=data;
			if(front == NULL)
			{
				front=temp;
				rear=temp;
				front->link=temp;
				front->pre=temp;
				start=temp;
				end=temp;
			}
			else
			{
				temp->link=start;
				start->pre=temp;
				end->link=temp;
				temp->pre=end;
				start=temp;
				front=temp;
			}
			nodes++;
		}
		else
		{
			if(front == NULL)
			{
				rear=start;
				front=start;
				front->data=data;
			}
			else
			{
				front=front->pre;
				front->data=data;
			}
		}
		counter++;
	}
}

int control::dequeue_left()
{
	int data;
	if(front == NULL)
	{
		cout<<"Queue Underflow ";
		return -1;
	}
	else
	{
		if(front == rear)
		{
			data=front->data;
			front->data=NULL;
			front=rear=NULL;
			
		}
		else
		{
			data=front->data;
			front->data=NULL;
			front=front->link;
			
		}
		counter--;
		return data;
	}
}
int control::dequeue_right()
{
	int data;
	if(rear == NULL)
	{
		cout<<"Queue Underflow ";
		return -1;
	}
	else
	{
		if(front == rear)
		{
			data=rear->data;
			rear->data=NULL;
			front=rear=NULL;
			
		}
		else
		{
			data=rear->data;
			rear->data=NULL;
			rear=rear->pre;
			
		}
		counter--;
		return data;
	}
}
void control::display()
{
	struct node *q=front;
	if(q != NULL)
	{
		do
		{
			cout<<q->data<<endl;
			q=q->link;
		}while(q != rear->link);
	}
}
bool control::is_empty()
{
	if(front==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void control::reverse()
{
	int data;
	if(is_empty()==true)
	{
		return ;
	}
	else
	{
		data=dequeue_left();
		reverse();
		enqueue_right(data);
	}
}
