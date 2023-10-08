#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *link=NULL;
};
void create(struct node *&start, int data);
void concatenate(struct node *&start1, struct node *&start2);
void display(struct node *&start);

int main()
{
	struct node *start1=NULL, *start2=NULL;
	for(int i=0; i<5; i++)
	{
		create(start1, i);
	}
	for(int i=5; i<10; i++)
	{
		create(start2, i);
	}
	concatenate(start1, start2);
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
void concatenate(struct node *&start1, struct node *&start2)
{
	struct node *q=start1;
	while( q->link != NULL)
	{
		q=q->link;
	}
	q->link=start2;
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














