#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *link=NULL;
};
void create(struct node *&start, int data);
void display(struct node *&start);

int main()
{
	struct node *start=NULL;
	int num;
	cout<<"Enter number: ";
	cin>>num;
	while(num != 0)
	{
		create(start, num%10);
		num=num/10;
	}
	display(start);
	return 0;
}

void create(struct node *&start, int data)
{
	struct node *temp=new node();
	temp->data=data;
	if(start == NULL)
	{
		start=temp;
	}
	else
	{
		temp->link=start;
		start=temp;
	}
}

void display(struct node *&start)
{
	struct node *q=start;
	while( q != NULL)
	{
		cout<<q->data<<endl;
		q=q->link;
	}
}



