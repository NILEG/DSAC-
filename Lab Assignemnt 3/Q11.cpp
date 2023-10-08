#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *link=NULL;
};
void create(struct node *&start, int data);
void display(struct node *&start);

int main()
{
	struct node *start=NULL;
	create(start, 2);
	create(start, 5);
	create(start, 1);
	create(start, 10);
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
	else if(start->data<temp->data)
	{
		temp->link=start;
		start=temp;
	}
	else
	{
		struct node *q=start, *pre=NULL;
		while(q != NULL)
		{
			if(q->data > data)
			{
				pre=q;
				q=q->link;
			}
			else
			{
				temp->link=q;
				pre->link=temp;
				return ;
			}
		}
		pre->link=temp;
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



