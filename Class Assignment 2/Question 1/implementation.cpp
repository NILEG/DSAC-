#include "my_header.h"
#include<iostream>
using namespace std;

int control::fibonnaci(int num)
{
	if(num<=1)
	{
		return num;
	}
	else
	{
		return fibonnaci(num-2)+fibonnaci(num-1);
	}
}
void control::push(int data)
{
	struct node *temp=new node();
	temp->data=data;
	temp->link=top;
	top=temp;
}
void control::display()
{
	struct node *q=top;
	while(q != NULL)
	{
		cout<<q->data<<" ";
		q=q->link;
	}
	cout<<endl;
}
int control::sum()
{
	struct node *q=top;
	int sum=0;
	while(q != NULL)
	{
		sum=sum+q->data;
		q=q->link;
	}
	return sum;
}
void control::reverse(node *pre, node *current, node *next)
{
	if(next == NULL)
	{
		top=current;
		current->link=pre;
		return ;
	}
	else
	{
		if(current == top)
		{
			next=current->link;
			current->link=NULL;
			reverse(current, next, next->link);
		}
		else
		{
			current->link=pre;
			reverse(current, next, next->link);
		}
	}
}
void control::menu()
{
	int choice, num;
	while(true)
	{
	cout<<"SELECT\n1. Enter Fibo Number\n2. Sum\n3. Reverse\n4. Display\n:>";
	cin>>choice;
	switch(choice)
	{
		case 1:
			cout<<"Enter the number: ";
			cin>>num;
			for(int i=1; i<=num; i++)
			{
				push(fibonnaci(i));
			}
			break;
		case 2:
			cout<<"Sum of element is: "<<sum()<<endl;
			break;
		case 3:
			reverse(NULL, top, top);
			cout<<"Reversed"<<endl;
			break;
		case 4:
			display();
			break;
		default:
			cout<<"Invalid Selection";
	}
	}
}
