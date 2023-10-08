/*
	Name: Q13
	Version: 0.1
	Date: 08-10-2023
	Author: @Umair-PC
*/
#include<iostream>
using namespace std;
struct node
{
	int coofficient, exponent;
	struct node *link=NULL;
};
void create(struct node *&start, int coofficient, int exponent);
void display(struct node *&start);
void multiply(struct node *&start, int multiplier);
int main()
{
	struct node *start=NULL;
	create(start, 2,3);
	create(start, 4,2);
	create(start, -5,1);
	multiply(start, 3);
	display(start);
	return 0;
}

void create(struct node *&start, int coofficient, int exponent)
{
	struct node *temp=new node();
	temp->coofficient=coofficient;
	temp->exponent=exponent;
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
void multiply(struct node *&start, int multiplier)
{
	struct node *q=start;
	while(q != NULL)
	{
		q->coofficient=q->coofficient*multiplier;
		q=q->link;
	}
}
void display(struct node *&start)
{
	struct node *q=start;
	while( q != NULL)
	{
		if(q ->link != NULL)
		cout<<"("<<q->coofficient<<"x^"<<q->exponent<<")+";
		else
		cout<<"("<<q->coofficient<<"x^"<<q->exponent<<")";
		q=q->link;
	}
}



