#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *link=NULL;
};
void create(struct node *&tail, int data);
void concatenate(struct node *&tail1, struct node *&tail2);
void display(struct node *&tail);

int main()
{
	struct node *tail1=NULL, *tail2=NULL;
	for(int i=0; i<5; i++)
	{
		create(tail1, i);
	}
	for(int i=5; i<10; i++)
	{
		create(tail2, i);
	}
	concatenate(tail1, tail2);
	display(tail1);
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
void concatenate(struct node *&tail1, struct node *&tail2)
{
	struct node *temp;
	temp=tail1->link;
	tail1->link=tail2->link;
	tail2->link=temp;
	tail1=tail2;
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
