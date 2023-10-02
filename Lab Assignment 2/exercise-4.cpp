#include<iostream>
#define max 10
using namespace std;
struct ret
{
	int top;
	int bottom;
};
int arr[max];
int top=-1;
int bottom=max;
void push(int data);
struct ret pop();
int main()
{
	struct ret dt;
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	dt=pop();
	cout<<dt.top<<" "<<dt.bottom<<endl;
	dt=pop();
	cout<<dt.top<<" "<<dt.bottom<<endl;
	dt=pop();
	cout<<dt.top<<" "<<dt.bottom<<endl;
	dt=pop();
	cout<<dt.top<<" "<<dt.bottom<<endl;
	dt=pop();
	cout<<dt.top<<" "<<dt.bottom<<endl;
	dt=pop();
	cout<<dt.top<<" "<<dt.bottom<<endl;
	return 0;
}
void push(int data)
{
	if(max % 2 ==0)
	{
		if(top == int(max/2)-1)
		{
			cout<<"Stack overflow"<<endl;
			return ;
		}
		else
		{
			top++;
			bottom--;
			arr[top]=data;
			arr[bottom]=data;
		}
	}
	else
	{
		cout<<"Size is odd"<<endl;
	}
}
struct ret pop()
{
	struct ret dt;
	if(top == -1)
	{
		cout<<"Stack Underflow ";
		dt.bottom=-1;
		dt.top=-1;
		return dt;
	}
	else
	{
		top--;
		bottom++;
		dt.top=arr[top+1];
		dt.bottom=arr[bottom-1];
		return dt;
	}
}
