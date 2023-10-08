#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *link=NULL;
};
void create(struct node *&tail, int data);
void split(struct node *&tail, struct node *&tail1, struct node *&tail2);
void display(struct node *&tail);
int count(struct node *&tail);
int main()
{
	struct node *tail=NULL, *tail1=NULL, *tail2=NULL;
	for(int i=0; i<9; i++)
	{
		create(tail, i);
	}
	split(tail, tail1, tail2);
	cout<<"First Slice"<<endl;
	display(tail1);
	cout<<"Second Slice"<<endl;
	display(tail2);
	return 0;
}

void create(struct node *&tail, int data)
{
	struct node *temp=new node();
	temp->data=data;
	if(tail == NULL)
	{
		tail=temp;
		temp->link=tail;
	}
	else
	{
		struct node *q=tail;
		do
		{
			q=q->link;
			
		}while(q != tail);
		temp->link=q->link;
		q->link=temp;
		tail=temp;
	}
}
void split(struct node *&tail, struct node *&tail1, struct node *&tail2)
{
	node *q=tail->link;
	int size=count(tail);
	if(size%2 == 0)
	{
		for(int i=1; i<=int(size/2); i++)
		{
			create(tail1, q->data);
			q=q->link;
		}
		for(int i=1; i<=int(size/2); i++)
		{
			create(tail2, q->data);
			q=q->link;
		}
	}
	else
	{
		for(int i=1; i<=int(size/2)+1; i++)
		{
			create(tail1, q->data);
			q=q->link;
		}
		for(int i=1; i<=int(size/2); i++)
		{
			create(tail2, q->data);
			q=q->link;
		}
	}
}
int count(struct node *&tail)
{
	struct node *q=tail->link;
	int count=0;
	do
	{
		count++;
		q=q->link;
	}while(q != tail->link);
	return count;
}
void display(struct node *&tail)
{
	struct node *q=tail->link;
	do
	{
		cout<<q->data<<endl;
		q=q->link;
	}while(q != tail->link);
}
