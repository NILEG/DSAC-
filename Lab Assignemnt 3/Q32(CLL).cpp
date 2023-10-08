#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *link=NULL;
};
void create(struct node *&tail, int data);
void arthm(struct node *&tail,  int &large, int &small, int &sum, float &avg);
void display(struct node *&tail);

int main()
{
	struct node *tail=NULL;
	int large=0, small=0, sum=0;
	float avg=0;
	for(int i=0; i<5; i++)
	{
		create(tail, i);
	}
	create(tail, 3);
	display(tail);
	arthm(tail, large, small, sum, avg);
	cout<<"Large: "<<large<<"\nSmall: "<<small<<"\nSum: "<<sum<<"\nAverage: "<<avg;
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
void arthm(struct node *&tail,  int &large, int &small, int &sum, float &avg)
{
	struct node *q=tail->link;
	int count=0;
	do
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
		q=q->link;
	}while(q != tail->link);
	avg=sum/float(count);

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
