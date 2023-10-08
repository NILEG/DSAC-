#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *link=NULL;
};
void create(struct node *&tail, int data);
int occurances(struct node *&tail, int data);
void display(struct node *&tail);

int main()
{
	struct node *tail=NULL;
	for(int i=0; i<5; i++)
	{
		create(tail, i);
	}
	create(tail, 3);
	display(tail);
	cout<<"Total occurances of '3' is: "<<occurances(tail, 3);
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
int occurances(struct node *&tail, int data)
{
	struct node *q=tail->link;
	int count=0;
	do
	{
		if(q->data == data)
		{
			count++;
		}
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
