#include "my_header.h"
#include<iostream>
using namespace std;
int control::to_index(char a)
{
	int index;
	char arr[]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't','u', 'v', 'w', 'x', 'y', 'z'};
	for(int i=0; i<26; i++)
	{
		if(arr[i]==a)
		{
			index=i;
			break;
		}
	}
	return index;
}
void control::create(int r, string n, string c)
{
	struct student *temp=new student(), *q;
	temp->cls=c;
	temp->name=n;
	temp->rollno=r;
	temp->next=NULL;
	temp->pre=NULL;
	if(tail == NULL)
	{
		tail=temp;
		tail->next=tail;
		tail->pre=tail;
	}
	else
	{
		q=tail->next;
		while(to_index(temp->name[0])> to_index(q->name[0]))
		{
			if(q==tail)
			{
				temp->next=q->next;
				temp->pre=q;
				q->next->pre=temp;
				q->next=temp;
				tail=temp;
				return;
			}
			q=q->next;
		}
		q=q->pre;
		temp->next=q->next;
		temp->pre=q;
		q->next->pre=temp;
		q->next=temp;
		if((q==tail) && (to_index(temp->name[0])>to_index(tail->name[0])))
		{
			tail=temp;	
		}	
	}
}
void control::display()
{
	struct student *q=tail->next;
	if( q != NULL)
	{
		do
		{
			cout<<"Name: "<<q->name<<" Roll Number: "<<q->rollno<<" Class: "<<q->cls<<endl;
			q=q->next;
		}while(q != tail->next);
	}
}
void control::del(int pos)
{
	struct student *q=tail->next;
	if(pos == 1)
	{
		tail->next=tail->next->next;
		tail->next->pre=tail;
		delete(q);
		return ;
	}
	for(int i=1; i<pos; i++)
	{
		q=q->next;
	}
	q->next->pre=q->pre;
	q->pre->next=q->next;
	if(q==tail)
	{
		tail=q->pre;
	}
	delete(q);
}
void control::search(string name)
{
	struct student *q=tail->next;
	do
	{
		if(q->name == name)
		{
			cout<<"\nFound\n"<<endl;
			cout<<"Name: "<<q->name<<" Roll Number: "<<q->rollno<<" Class: "<<q->cls<<endl;
			return;
		}
		q=q->next;	
	}while(q != tail->next);
}
