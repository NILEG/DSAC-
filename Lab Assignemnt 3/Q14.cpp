/*
	Name: Q14
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
void multiply(struct node *&start1, struct node *&start2, struct node *&start3);
void concatenate_power(struct node *&start3);
int main()
{
	struct node *start1=NULL,*start2=NULL, *start3=NULL;
	//First Polynomial
	create(start1, 2,3);
	create(start1, 4,2);
	create(start1, -5,1);
	//Second Polynomial
	create(start2, 2,3);
	create(start2, 4,2);
	
	multiply(start1, start2, start3);
	display(start3);
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
void multiply(struct node *&start1, struct node *&start2, struct node *&start3)
{
	struct node *q=start1, *p=NULL;
	while(q != NULL)
	{
		p=start2;
		while(p != NULL)
		{
			int mul=q->coofficient*p->coofficient;
			int exp=q->exponent+p->exponent;
			create(start3, mul, exp);
			p=p->link;
		}
		q=q->link;
	}
	concatenate_power(start3);
}
void concatenate_power(struct node *&start3)
{
	struct node *q=start3, *temp=NULL;
	
	while( q->link != NULL)
	{
		if(q->exponent == q->link->exponent)
		{
			q->coofficient=q->link->coofficient+q->coofficient;
			temp=q->link;
			q->link=q->link->link;
			delete(temp);
		}
		else
		{
			q=q->link;
		}
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
