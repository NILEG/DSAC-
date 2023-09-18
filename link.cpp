#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *link;
};
void create(struct node * &head, int data);
void display(struct node * &head);
void insert_at_start(struct node * &head, int data);
void insert_middle(struct node * &head, int pos, int data);
int count(struct node * &head);
void del(struct node * &head);
int main()
{
	struct node *head=NULL;
	for(int i=0; i<5; i++)
	{
		create(head, i);
	}
	display(head);
	insert_at_start(head, 20);
	create(head, 100);
	cout<<"INSERT AT START\n\n";
	display(head);
	cout<<"\nTotal Nodes: "<<count(head)<<endl;
	cout<<"INSERT AT 3rd pos\n\n";
	insert_middle(head, 3, 200);
	display(head);
	return 0;
}
void create(struct node * &head, int data)
{
	struct node *ptr, *current;
	ptr=new node();
	ptr->data=data;
	ptr->link=NULL;
	if(head==NULL)
	{
		head=ptr;
	}
	else
	{
		current=head;
		while(current->link != NULL)
		{
			current=current->link;
		}
		current->link=ptr;
	}
}
void display(struct node * &head)
{
	struct node *ptr=head;
	while(ptr != NULL)
	{
		cout<<ptr->data<<endl;
		ptr=ptr->link;
	}
}
void insert_at_start(struct node * &head, int data)
{
	struct node *current, * ptr=new node();
	ptr->data=data;
	ptr->link=NULL;
	if(head==NULL)
	{
		head=ptr;
	}
	else
	{
		ptr->link=head;
		head=ptr;
	}
}
int count(struct node * &head)
{
	int counter=0;
	struct node *current=head;
	while(current != NULL)
	{
		counter++;
		current=current->link;
	}
	return counter;
}
void insert_middle(struct node * &head, int pos, int data)
{
	int counter=0;
	struct node *ptr, *temp;
	ptr=new node();
	ptr->data=data;
	ptr->link=NULL;
	temp=head;
	for(int i=0; i<pos-1; i++)
	{
		if(temp->link == NULL)
		{
			cout<<"position out of bound"<<endl;
			return;
		}
		temp=temp->link;
	}
	ptr->link=temp->link;
	temp->link=ptr;
}
