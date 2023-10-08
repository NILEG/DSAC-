#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *link=NULL;
};
void create(struct node *&start, int data);
void remove(struct node *&start);
void display(struct node *&start);

int main()
{
	struct node *start=NULL;
	for(int i=0; i<5; i++)
	{
		create(start, i);
	}
	remove(start);
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
		struct node *q=start;
		while(q->link != NULL)
		{
			q=q->link;
		}
		q->link=temp;
	}
}
void remove(struct node *&start)
{
	if(start == NULL)
	{
		cout<<"List is empty"<<endl;
	}
	else
	{
		struct node *q=start, *temp;
		while(q->link != NULL)
		{
			q=q->link;
		}
		temp=start;
		start=start->link;
		q->link=temp;
		temp->link=NULL;
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



