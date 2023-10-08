#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *link=NULL;
};
void create(struct node *&start, int data);
void deleting_creation(struct node *&start, struct node *&l2, struct node *&l3);
void display(struct node *&start);

int main()
{
	struct node *l1=NULL, *l2=NULL, *l3=NULL;
	for(int i=0; i<10; i++)
	{
		create(l1, i);
	}
	deleting_creation(l1,l2,l3);
	cout<<"Even: "<<endl;
	display(l2);
	cout<<"Odd: "<<endl;
	display(l3);
	cout<<"Original"<<endl;
	display(l1);
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
void deleting_creation(struct node *&start, struct node *&l2, struct node *&l3)
{
	struct node *q=start, *temp;
	while(q != NULL)
	{
		if(q->data%2==0)
		{
			create(l2, q->data);
		}
		else
		{
			create(l3, q->data);
		}
		temp=q;
		q=q->link;
		start=q;
		delete(temp);
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



