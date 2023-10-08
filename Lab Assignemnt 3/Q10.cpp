#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *link=NULL;
};
void create(struct node *&start, int data);
void display(struct node *&start);
void swapping(struct node *&start, int a, int b);
int main()
{
	struct node *start=NULL;
	for(int i=0; i<5; i++)
	{
		create(start, i);
	}
	//Swap node 3 and 5
	swapping(start, 4,5);
	display(start);
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
void swapping(struct node *&start, int a, int b)
{
	struct node *prevx=NULL, *x=start, *prevy=NULL, *y=start;
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
			start=y;
			
		}
		else
		{
			struct node *temp=y->link;
			y->link=x->link;
			x->link=temp;
			prevy->link=x;
			start=y;
		}
	}
	//Case-2: If B is ending node
	else if(y->link == NULL)
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
			y->link=x->link;
			prevx->link=y;
			prevy->link=x;
			x->link=NULL;
		}
	}
	
	//Case-3: If both in middle
	else if(prevx != NULL && y->link != NULL)
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

void display(struct node *&start)
{
	struct node *q=start;
	while( q != NULL)
	{
		cout<<q->data<<endl;
		q=q->link;
	}
}



