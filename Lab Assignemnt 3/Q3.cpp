#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *link=NULL;
};
void create(struct node *&start, int data);
void copy(struct node *&start, struct node *&start1);
void display(struct node *&start);
int main()
{
	struct node *start=NULL, *start1=NULL;
	for(int i=4; i<10; i++)
	{
		create(start, i);
	}
	
	copy(start, start1);
	display(start1);
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
void copy(struct node *&start, struct node *&start1)
{
	struct node *q=start;
	while( q != NULL)
	{
		create(start1, q->data);
		q=q->link;
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

