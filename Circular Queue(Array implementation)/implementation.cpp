#include "my_header.h"
#include<iostream>
using namespace std;

void Queue_St::enqueue(int data)
{
	if(rear==-1)
	{
		rear++;
		front++;
		queue[rear]=data;
	}
	else if((rear==Max-1 && front ==0) || rear==front-1)
	{
		cout<<"Overflow"<<endl;
		return;
	}
	else if(rear==9)
	{
		rear=0;
		queue[rear]=data;
	}
	else
	{
		rear++;
		queue[rear]=data;
	}
}
int Queue_St::dequeue()
{
	int data;
	if(front != Max and front != -1)
	{
		data = queue[front];
		if(front == Max-1 && rear<front)
		{
			front =0;
		}
		else if(front == rear)
		{
			rear=front=-1;
		}
		else
		{
			front++;
		}
	}
	else
	{
		cout<<"Underflow";
	}
}
void Queue_St::display()
{
	int index=front;
	do
	{
		cout<<queue[index%Max]<<endl;
		index++;
	}while((index-1)%Max != rear);
}
