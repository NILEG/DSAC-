#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *link=NULL;
};
void create(struct node *&tail, int data);
void deleting_creation(struct node *&tail, struct node *&tail1, struct node *&tail2);
void display(struct node *&tail);

int main()
{
	struct node *tail=NULL, *tail1=NULL, *tail2=NULL;
	for(int i=0; i<10; i++)
	{
		create(tail, i);
	}
	deleting_creation(tail, tail1,tail2);
	cout<<"Even: "<<endl;
	display(tail1);
	cout<<"Odd: "<<endl;
	display(tail2);
	cout<<"Original"<<endl;
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
void deleting_creation(struct node *&tail, struct node *&tail1, struct node *&tail2)
{
	struct node *q=tail->link, *temp;
	do
	{
		if(q->data%2==0)
		{
			create(tail1, q->data);
		}
		else
		{
			create(tail2, q->data);
		}
		temp=q;
		q=q->link;
		tail->link=q;
		delete(temp);
	}while(q != tail);
	if(q->data%2==0)
	{
		create(tail1, q->data);
		tail=NULL;
		delete(q);
	}
	else
	{
		create(tail2, q->data);
		tail=NULL;
		delete(q);
	}

}
void display(struct node *&tail)
{
	if(tail != NULL)
	{
		struct node *q=tail->link;
		do
		{
			cout<<q->data<<endl;
			q=q->link;
		}while(q != tail->link);
	}
}
