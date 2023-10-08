#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next=NULL, *pre=NULL;
};
void create(struct node *&start, int data);
void display(struct node *&start);
void copy(struct node *&start, struct node *&start1);

int main()
{
	struct node *start1=NULL, *start2=NULL;
	for(int i=0; i<5; i++)
	{
		create(start1, i);
	}
	copy(start1, start2);
	display(start2);
	return 0;
}
void copy(struct node *&start, struct node *&start1)
{
	struct node *q=start;
	while( q != NULL)
	{
		create(start1, q->data);
		q=q->next;
	}
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
		while(q->next != NULL)
		{
			q=q->next;
		}
		q->next=temp;
		temp->pre=q;
	}
}
void display(struct node *&start)
{
	struct node *q=start;
	while( q != NULL)
	{
		cout<<q->data<<endl;
		q=q->next;
	}
}
