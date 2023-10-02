#include<iostream>
#define max 10
using namespace std;
int arr[max];
int top=-1;
int bottom=max;
void push1(int data);
int pop1();
void push2(int data);
int pop2();
int main()
{
	push2(1);
	push1(10);//push 2
	push2(2);
	push2(3);
	push2(4);
	push2(5);
	push2(6);
	push2(7);
	push2(8);
	push2(9);
	//push2(9);
	cout<<pop2()<<endl;
	cout<<pop2()<<endl;
	cout<<pop2()<<endl;
	cout<<pop2()<<endl;
	cout<<pop2()<<endl;
	cout<<pop2()<<endl;
	cout<<pop2()<<endl;
	cout<<pop2()<<endl;
	cout<<pop2()<<endl;
	cout<<pop1()<<endl;
	return 0;
}
void push1(int data)
{
	if((top == max-1) || (top == bottom-1))
	{
		cout<<"Stack Overflow"<<endl;
		return;
	}
	else
	{
		top++;
		arr[top]=data;
	}
}
int pop1()
{
	if(top==-1)
	{
		cout<<"Stack Underflow"<<endl;
		return -1;
	}
	else
	{
		top--;
		return arr[top+1];
	}
}
void push2(int data)
{
	if((bottom == -1) || (bottom == top+1))
	{
		cout<<"Stack Overflow"<<endl;
		return;
	}
	else
	{
		bottom--;
		arr[bottom]=data;
		
	}
}
int pop2()
{
	if(bottom==(max))
	{
		cout<<"Stack Underflow"<<endl;
		return -1;
	}
	else
	{
		bottom++;
		return arr[bottom-1];
		
	}
}
