#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next=NULL, *pre=NULL;
};
void create(struct node *&start, int data);
void display(struct node *&start);
void split(struct node *&start, struct node *&start1, struct node *&start2);
int count(struct node *&start);
int main()
{
	struct node *start=NULL, *start1=NULL, *start2=NULL;
	
	for(int i=4; i<10; i++)
	{
		create(start, i);
	}
	
	split(start, start1, start2);
	cout<<"First Slice"<<endl;
	display(start1);
	cout<<"Second Slice"<<endl;
	display(start2);
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
void split(struct node *&start, struct node *&start1, struct node *&start2)
{
	struct node *q=start;
	
	int size=count(start);
	if(size%2 == 0)
	{
		for(int i=1; i<=int(size/2); i++)
		{
			create(start1, q->data);
			q=q->next;
		}
		for(int i=1; i<=int(size/2); i++)
		{
			create(start2, q->data);
			q=q->next;
		}
	}
	else
	{
		for(int i=1; i<=int(size/2)+1; i++)
		{
			create(start1, q->data);
			q=q->next;
		}
		for(int i=1; i<=int(size/2); i++)
		{
			create(start2, q->data);
			q=q->next;
		}
	}
}
int count(struct node *&start)
{
	struct node *q=start;
	int counter=0;
	while( q != NULL)
	{
		counter ++;
		q=q->next;
	}
	return counter;
}
