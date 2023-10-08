#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next=NULL, *pre=NULL;
};
void create(struct node *&start, int data);
void display(struct node *&start);
int occurances(struct node *&start, int data);

int main()
{
	struct node *start=NULL;
	for(int i=0; i<5; i++)
	{
		create(start, i);
	}
	create(start, 2);
	create(start, 2);
	cout<<"Total occurances of '2' is: "<<occurances(start, 2);
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
int occurances(struct node *&start, int data)
{
	int count=0;
	struct node *q=start;
	while( q != NULL)
	{
		if(data == q->data)
		{
			count++;
		}
		q=q->next;
	}
	return count;
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
