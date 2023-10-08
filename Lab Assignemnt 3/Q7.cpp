#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *link=NULL;
};
void create(struct node *&start, int data);
void occurances(struct node *&start, int &element, int &even, int &odd);
void display(struct node *&start);

int main()
{
	struct node *start=NULL;
	int element=0, even=0, odd=0;
	for(int i=0; i<5; i++)
	{
		create(start, i);
	}
	create(start, 2);
	create(start, 2);
	display(start);
	occurances(start, element, even, odd);
	cout<<"Non-Zeros: "<<element<<"\nEven: "<<even<<"\nOdd: "<<odd;
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
void occurances(struct node *&start, int &element, int &even, int &odd)
{
	struct node *q=start;
	while( q != NULL)
	{
		if(q->data != 0)
		{
			element++;
		}
		if(q->data%2==0)
		{
			even++;
		}
		else
		{
			odd++;
		}
		
		q=q->link;
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



