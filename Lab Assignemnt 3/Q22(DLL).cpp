#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next=NULL, *pre=NULL;
};
void create(struct node *&start, int data);
void display(struct node *&start);
void arthm(struct node *&start, int &large, int &small, int &sum, float &avg);

int main()
{
	struct node *start=NULL;
	int large=0, small=0, sum=0;
	float avg=0;
	for(int i=0; i<5; i++)
	{
		create(start, i);
	}
	create(start, 2);
	create(start, 1);
	display(start);
	arthm(start, large, small, sum, avg);
	cout<<"Large: "<<large<<"\nSmall: "<<small<<"\nSum: "<<sum<<"\nAverage: "<<avg;
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
void arthm(struct node *&start, int &large, int &small, int &sum, float &avg)
{
	struct node *q=start;
	int count=0;
	while( q != NULL)
	{
		if(large< q->data)
		{
			large=q->data;
		}
		if(small>q->data)
		{
			small=q->data;
		}
		sum=sum+q->data;
		count++;
		q=q->next;
	}
	avg=sum/float(count);
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
