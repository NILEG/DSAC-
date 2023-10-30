#include<iostream>
#include "my_header.h"
using namespace std;

void control::enqueue_right()
{
	if(counter == Max && rear->link==front)
	{
		cout<<"Queue Overflow"<<endl;
	}
	else
	{
		cin.ignore();
		string item_name;
		int price;
		cout<<"Enter Item Name: ";
		getline(cin, item_name);
		cout<<"Enter Price: ";
		cin>>price;
		item *it=new item();
		it->name=item_name;
		it->price=price;
		if(nodes <Max && rear == end)
		{
			cart *temp=new cart();
			temp->itm=it;
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
				rear->itm=it;
			}
			else
			{
				rear=rear->link;
				rear->itm=it;
			}
		}
		counter++;
	}
}

void control::enqueue_left()
{
	if(counter == Max && rear==front->pre)
	{
		cout<<"Queue Overflow"<<endl;
	}
	else
	{
		cin.ignore();
		string item_name;
		int price;
		cout<<"Enter Item Name: ";
		getline(cin, item_name);
		cout<<"Enter Price: ";
		cin>>price;
		item *it=new item();
		it->name=item_name;
		it->price=price;
		if(nodes <Max && front == start)
		{
			cart *temp=new cart();
			temp->itm=it;
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
				front->itm=it;
			}
			else
			{
				front=front->pre;
				front->itm=it;
			}
		}
		counter++;
	}
}

void control::dequeue_left()
{
	if(front == NULL)
	{
		cout<<"Queue Underflow ";
	}
	else
	{
		item *it;
		if(front == rear)
		{
			it=front->itm;
			front->itm=NULL;
			delete(it);
			front=rear=NULL;
			
		}
		else
		{
			it=front->itm;
			front->itm=NULL;
			delete(it);
			front=front->link;
			
		}
		counter--;
	}
}
void control::dequeue_right()
{
	if(rear == NULL)
	{
		cout<<"Queue Underflow ";
	}
	else
	{
		item *it;
		if(front == rear)
		{
			it=rear->itm;
			rear->itm=NULL;
			delete(it);
			front=rear=NULL;
			
		}
		else
		{
			it=rear->itm;
			rear->itm=NULL;
			delete(it);
			rear=rear->pre;
			
		}
		counter--;
	}
}
void control::display()
{
	struct cart *q=front;
	if(q != NULL)
	{
		do
		{
			cout<<q->itm->name<<" : "<<q->itm->price<<endl;
			q=q->link;
		}while(q != rear->link);
	}
}
void control::menu()
{
	int ch;
	while(true)
	{
		cout<<"SELECT\n1. Insert Front\n2. Insert Back\n3. Delete Front\n4. Delete Back\n5. Display\n6. Quit\n:>";
		cin>>ch;
		switch(ch)
		{
			case 1:
				enqueue_left();
				break;
			case 2:
				enqueue_right();
				break;
			case 3:
				dequeue_left();
				break;
			case 4:
				dequeue_right();
				break;
			case 5:
				display();
				break;
			case 6:
				cout<<"Quitting"<<endl;
				exit(0);	
		}
	}
}
