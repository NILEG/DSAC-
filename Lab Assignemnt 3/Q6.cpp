#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *link=NULL;
};
void create(struct node *&start, int data);
int occurances(struct node *&start, int data);
void display(struct node *&start);

int main()
{
	struct node *start=NULL;
	for(int i=0; i<5; i++)
	{
		create(start, i);
	}
	create(start, 0);
	create(start, 0);
	cout<<"Total occurances of '0' is: "<<occurances(start, 0);
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
		q=q->link;
	}
	return count;
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



