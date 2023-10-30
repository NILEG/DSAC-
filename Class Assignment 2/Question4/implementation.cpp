#include<iostream>
#include <cstdlib> 
#include <time.h> 
#include "my_header.h"
using namespace std;

void control::push()
{
	if(counter == Max && rear->link==front)
	{
		cout<<"Queue Overflow"<<endl;
	}
	else
	{
		cin.ignore();
		string data;
		cout<<"Enter the name of Song: ";
		getline(cin, data);
		if(nodes <Max)
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
			}
			else
			{
				temp->link=start;
				start->pre=temp;
				rear->link=temp;
				temp->pre=rear;
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

string control::pop()
{
	string data;
	if(front == NULL)
	{
		cout<<"Queue Underflow ";
		return "";
	}
	else
	{
		if(front == rear)
		{
			data=front->data;
			front->data="";
			front=rear=NULL;
			
		}
		else
		{
			data=front->data;
			front->data="";
			front=front->link;
			
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
void control::shuffle()
{
	int m, a,b;
	srand(time(0));
	m=(rand()%4)+1;
	for(int i=0; i<m; i++)
	{
		a=rand()%counter+1;
		b=rand()%counter+1;
		if(a!=b)
		{
			if(a>b)
			{
				swapping(b,a);
			}
			else
			{
				swapping(a,b);
			}
		}
		
	}
	//If same is generated
	//If a>b
	//If a&b=0
}
void control::swapping(int a, int b)
{
	struct node *prex=NULL, *prey=NULL,*x=front, *y=front, *nextx=NULL, *nexty=NULL;
	int count=1;
	//Searching A
	while(count != a)
	{
		x=x->link;
		count++;
	}
	//Searching B'
	count=1;
	while(count != b)
	{
		y=y->link;
		count++;
	}
	//cout<<x->data<<" "<<y->data<<endl;
	//Swapping
	//Both corners
	if(y->link==x)
	{
		y->link=x->link;
		x->link->pre=y;
		
		x->pre=y->pre;
		y->pre->link=x;
		
		x->link=y;
		y->pre=x;
		
		
		front=y;
		rear=x;
		if(x==start)
		{
			start=y;
		}
	}
	//Consective
	else if(b-a==1)
	{
		prex=x->pre;
		nexty=y->link;
		
		nexty->pre=x;
		x->link=nexty;
		
		y->pre=prex;
		prex->link=y;
		
		y->link=x;
		x->pre=y;
		
		if(x==front)
		front=y;
		
		if(y==rear)
		rear=x;
		
		if(x==start)
		start=y;
	}
	//Non-Consective
	else
	{
		prex=x->pre;
		prey=y->pre;
		
		y->link->pre=x;
		x->link->pre=y;
		
		nextx=x->link;
		x->link=y->link;
		
		prey->link=x;
		x->pre=prey;
		
		prex->link=y;
		y->pre=prex;
		y->link=nextx;
		
		if(x==front)
		front=y;
		
		if(y==rear)
		rear=x;
		
		if(x==start)
		start=y;
	}
}
void control::menu()
{
	int ch, price;
	string data;
	while(true)
	{
		cout<<"SELECT\n1. Insert\n2. Remove\n3. Play All\n4. Shuffle\nChoice>: "<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:
				cout<<pop()<<" removed from playlist"<<endl;
				break;
			case 3:
				display();
				break;
			case 4:
				shuffle();
				break;
			default:
				cout<<"Option Not found"<<endl;
		}
	}
}
