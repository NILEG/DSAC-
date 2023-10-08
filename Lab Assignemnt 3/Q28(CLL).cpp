#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *link=NULL;
};
void create(struct node *&tail, int data);
void remove(struct node *&tail);
void display(struct node *&tail);

int main()
{
	struct node *tail=NULL;
	for(int i=0; i<5; i++)
	{
		create(tail, i);
	}
	remove(tail);
	display(tail);
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
void remove(struct node *&tail)
{
	node *temp=tail->link;
	if(tail == NULL)
	{
		cout<<"List is Empty"<<endl;
	}
	else
	{
		tail=tail->link;
	}
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
