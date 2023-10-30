#include<iostream>
#include "my_header.h"
using namespace std;

void control::setMax(int max)
{
	Max=max;
}
void control::enqueue()
{
	if(counter == Max && rear->link==front)
	{
		cout<<"Queue Overflow"<<endl;
	}
	else
	{
		string data;
		int price;
		cin.ignore();
		cout<<"Order Name: ";
		getline(cin, data);
		cout<<"Order Price: ";
		cin>>price;
		if(nodes <Max)
		{
			node *temp=new node();
			temp->order_name=data;
			temp->price=price;
			if(rear == NULL)
			{
				front=temp;
				rear=temp;
				rear->link=temp;
				start=temp;
			}
			else
			{
				temp->link=start;
				rear->link=temp;
				rear=temp;
			}
			nodes++;
		}
		else
		{
			if(front == NULL)
			{
				rear=start;
				front=start;
				rear->order_name=data;
				rear->price=price;
			}
			else
			{
				rear=rear->link;
				rear->order_name=data;
				rear->price=price;
			}
		}
		counter++;
	}
}

void control::dequeue()
{
	if(front == NULL)
	{
		cout<<"Queue Underflow ";
		return;
	}
	else
	{
		if(front == rear)
		{
			front->order_name="";
			front->price=NULL;
			front=rear=NULL;
		}
		else
		{
			front->order_name="";
			front->price=NULL;
			front=front->link;
			
		}
		counter--;
	}
}
void control::display()
{
	struct node *q=front;
	if(q != NULL)
	{
		do
		{
			cout<<q->order_name<<" : "<<q->price<<endl;
			q=q->link;
		}while(q != rear->link);
	}
}
void control::menu()
{
	int ch, price;
	string data;
	while(true)
	{
		cout<<"SELECT\n1. Insert\n2. Remove\n3. Display\nChoice>: "<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				cout<<"Order Processed"<<endl;
				break;
			case 3:
				display();
				break;
			default:
				cout<<"Option Not found"<<endl;
		}
	}
}

