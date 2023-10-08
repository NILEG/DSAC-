#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *link=NULL;
};
void create(struct node *&tail, int data);
void occurances(struct node *&tail, int &element, int &even, int &odd);
void display(struct node *&tail);

int main()
{
	struct node *tail=NULL;
	int element=0, even=0, odd=0;
	for(int i=0; i<5; i++)
	{
		create(tail, i);
	}
	create(tail, 3);
	display(tail);
	occurances(tail, element, even, odd);
	cout<<"Non-Zeros: "<<element<<"\nEven: "<<even<<"\nOdd: "<<odd;
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
void occurances(struct node *&tail, int &element, int &even, int &odd)
{
	struct node *q=tail->link;
	do
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
	}while(q != tail->link);
	

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
