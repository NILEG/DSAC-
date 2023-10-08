#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next=NULL, *pre=NULL;
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
	//Swapping node 2 & 4
	swapping(start, 2,4);
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
		while(q->next != NULL)
		{
			q=q->next;
		}
		q->next=temp;
		temp->pre=q;
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
		x=x->next;
		count++;
	}
	//Searching B
	count=1;
	while( y !=NULL && count != b)
	{
		prevy=y;
		y=y->next;
		count++;
	}
	//Swapping
	//Case-1: If A is starting node
	if(prevx == NULL)
	{
		//Case-1: If both are consective
		if(b-a == 1)
		{
			x->next=y->next;
			if(x->next!=NULL)
			x->next->pre=x;
			y->next=x;
			x->pre=y;
			y->pre=NULL;
			start=y;
			
		}
		else
		{
			struct node *temp=y->next;
			y->next=x->next;
			y->pre=NULL;
			x->next=temp;
			if(temp != NULL)
			temp->pre=x;
			prevy->next=x;
			x->pre=prevy;
			start=y;
		}
	}
	//Case-2: If B is ending node
	else if(y->next == NULL)
	{
		//Case-1: If both are consective
		if(b-a == 1)
		{
			x->next=y->next;
			y->next=x;
			y->pre=x->pre;
			x->pre=y;
			prevx->next=y;
			
		}
		else
		{
			y->next=x->next;
			x->next->pre=y;
			prevx->next=y;
			y->pre=prevx;
			prevy->next=x;
			x->pre=prevy;
			x->next=NULL;
		}
	}
	
	//Case-3: If both in middle
	else if(prevx != NULL && y->next != NULL)
	{
		//Case-1: If both are consective
		if(b-a == 1)
		{
			x->next=y->next;
			y->next->pre=x;
			y->next=x;
			x->pre=y;
			prevx->next=y;
			y->pre=prevx;
		}
		else
		{
			struct node *temp=y->next;
			y->next=x->next;
			x->next->pre=y;
			
			x->next=temp;
			temp->pre=x;
			
			prevy->next=x;
			x->pre=prevy;
			
			prevx->next=y;
			y->pre=prevx;
		}
	}
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
