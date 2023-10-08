#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *link=NULL;
};
void create(struct node *&tail, int data);
void swapping(struct node *&tail, int a, int b);
void display(struct node *&tail);

int main()
{
	struct node *tail=NULL;
	for(int i=0; i<5; i++)
	{
		create(tail, i);
	}
	//Swap node 3 and 5
	swapping(tail, 2,5);
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
void swapping(struct node *&tail, int a, int b)
{
	struct node *prevx=NULL, *x=tail->link, *prevy=NULL, *y=tail->link;
	int count=1;
	//Searching A
	while( x != NULL && count != a)
	{
		prevx=x;
		x=x->link;
		count++;
	}
	//Searching B
	count=1;
	while( y !=NULL && count != b)
	{
		prevy=y;
		y=y->link;
		count++;
	}
	//Swapping
	//Case-1: If A is starting node
	if(prevx == NULL)
	{
		//Case-1: If both are consective
		if(b-a == 1)
		{
			x->link=y->link;
			y->link=x;
			tail->link=y;
			
		}
		else
		{
			struct node *temp=y->link;
			y->link=x->link;
			x->link=temp;
			prevy->link=x;
			tail->link=y;
		}
	}
	//Case-2: If B is ending node
	else if(y == tail)
	{
		//Case-1: If both are consective
		if(b-a == 1)
		{
			x->link=y->link;
			y->link=x;
			prevx->link=y;
			tail=x;
		}
		else
		{
			node *temp=y->link;
			y->link=x->link;
			prevx->link=y;
			prevy->link=x;
			x->link=temp;
			tail=x;
		}
	}
	
	//Case-3: If both in middle
	else if(prevx != NULL && y != tail)
	{
		//Case-1: If both are consective
		if(b-a == 1)
		{
			x->link=y->link;
			y->link=x;
			prevx->link=y;
		}
		else
		{
			struct node *temp=y->link;
			y->link=x->link;
			x->link=temp;
			prevy->link=x;
			prevx->link=y;
		}
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
