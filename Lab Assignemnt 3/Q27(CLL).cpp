#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *link=NULL;
};
void create(struct node *&tail, int data);
void copy(struct node *&tail1, struct node *&tail2);
void display(struct node *&tail);

int main()
{
	struct node *tail1=NULL, *tail2=NULL;
	for(int i=0; i<5; i++)
	{
		create(tail1, i);
	}
	copy(tail1, tail2);
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
void copy(struct node *&tail1, struct node *&tail2)
{
	struct node *q=tail1->link;
	do
	{
		create(tail2, q->data);
		q=q->link;
	}while(q != tail1->link);
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
