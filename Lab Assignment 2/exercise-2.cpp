#include<iostream>
#define max 10
using namespace std;
struct node
{
	int data;
	struct node *link;
} *start=NULL;
int top=-1;
void push(int data);
int pop();
int main()
{
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
	push(7);
	push(8);
	push(9);
	push(10);
	cout<<pop()<<endl;
	cout<<pop()<<endl;
	cout<<pop()<<endl;
	cout<<pop()<<endl;
	cout<<pop()<<endl;
	cout<<pop()<<endl;
	cout<<pop()<<endl;
	cout<<pop()<<endl;
	cout<<pop()<<endl;
	cout<<pop()<<endl;
	cout<<pop()<<endl;
	return 0;
}

void push(int data)
{
	if(top != (max-1))
	{
		struct node *temp=new node();
		temp->data=data;
		temp->link=NULL;
		if(start == NULL)
		{
			start=temp;
		}
		else
		{
			temp->link=start;
			start=temp;
		}
		top++;
	}
	else
	{
		cout<<"Stack Overflow"<<endl;
		return ;
	}
}
int pop()
{
	struct node *temp;
	if(top == -1)
	{
		cout<<"Stack underflow"<<endl;
		return -1;
	}
	else
	{
		temp=start;
		start=start->link;
		top--;
	}
	return temp->data;
}
