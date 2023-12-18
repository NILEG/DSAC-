#include<iostream>
using namespace std;
struct edge
{
	char dest;
	edge *link=NULL;
};
struct node
{
	char name;
	edge *adj=NULL;
	node *next=NULL;
} *start=NULL;
void insert_node(char ch)
{
	node *temp=new node();
	temp->name=ch;
	node *ptr=start;
	if(ptr == NULL)
	{
		start=temp;
	}
	while(ptr->next != NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=temp;
}
node *find(char ch)
{
	node *ptr=start;
	while(ptr != NULL)
	{
		if(ptr->name == ch)
		{
			break;
		}
		else
		{
			ptr=ptr->next;
		}
	}
	return ptr;
}
void insert_edge(char source, char dest)
{
	edge *ptr;
	edge *temp=new edge();
	node *u=find(source);
	node *v=find(dest);
	if(u == NULL)
	{
		cout<<"Source doesn't exsist"<<endl;
		return ;
	}
	else if(v == NULL)
	{
		cout<<"Destination doesn't exsist"<<endl;
		return ;
	}
	temp->dest=dest;
	if(u->adj == NULL)
	{
		u->adj = temp;
		return ;
	}
	ptr=u->adj;
	while(ptr->link != NULL)
	{
		ptr=ptr->link;
	}
	ptr->link=temp;
}
void delete_node(char ch)
{
	node *q=start;
	node *temp;
	if(q->name == ch)
	{
		temp=start;
		start=start->next;
		delete(temp);
		return ;
	}
	while(q->next->next != NULL)
	{
		if(q->next->name == ch)
		{
			temp=q->next;
			q->next=q->next->next;
			delete(temp);
			return ;
		}
		q=q->next;
	}
	if(q->next->name == ch)
	{
		temp=q->next;
		q->next=NULL;
		delete(temp);
		return ;
	}
}
void delete_edge(char source, char dest)
{
	node *ptr=start;
	edge *eptr, *temp;
	while(ptr != NULL)
	{
		
		//Update
		ptr=ptr->next;
	}
}
void del_all_edges_of(char dest)
{
	
}