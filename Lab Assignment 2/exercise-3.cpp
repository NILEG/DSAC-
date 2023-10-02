#include<iostream>
#define max 10
using namespace std;
int arr[max];
int top=max-1;
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
	return 0;
}

void push(int data)
{
	if(top == -1)
	{
		cout<<"Stack Overflow"<<endl;
		return;
	}
	else
	{
		arr[top]=data;
		top--;
	}
}
int pop()
{
	if(top==(max-1))
	{
		cout<<"Stack Underflow"<<endl;
		return -1;
	}
	else
	{
		top++;
		return arr[top];
	}
}
