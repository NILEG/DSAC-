#include "my_header.h"
#include<iostream>
#define MAX 20
using namespace std;
void graph_control::insert_node(char ch)
{
	node *temp=new node();
	temp->name=ch;
	node *ptr=start;
	if(start == NULL)
	{
		start=temp;
		return;
	}
	while(ptr->next != NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=temp;
}
node* graph_control::find(char ch)
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
void graph_control::insert_edge(char source, char dest, int cost)
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
	temp->cost=cost;
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
void graph_control::delete_node(char ch)
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
void graph_control::delete_edge(char source, char dest)
{
	node *ptr=start;
	edge *temp, *q;
	node *u=find(source);
	if(u ==  NULL)
	{
		cout<<"Source doesn't exsist"<<endl;
		return ;
	}
	if(u->adj->dest == dest)
	{
		temp=u->adj;
		u->adj=u->adj->link;
		delete(temp);
		return ;
	}
	q=u->adj;
	while(q->link->link != NULL)
	{
		if(q->link->dest == dest)
		{
			temp=q->link;
			q->link=q->link->link;
			delete(temp);
			return ;
		}
		q=q->link;
	}
	if(q->link->dest == dest)
	{
		temp=q->link;
		q->link=NULL;
		delete(temp);
		return ;
	}
}
void graph_control::delnode_edge(char dest)
{
	node *ptr=start;
	edge *temp, *q;
	while(ptr != NULL)
	{
		if(ptr->adj->dest == dest)
		{
			temp=ptr->adj;
			ptr->adj=ptr->adj->link;
			delete(temp);
			continue ;
		}
		q=ptr->adj;
		while(q->link->link != NULL)
		{
			if(q->link->dest == dest)
			{
				temp=q->link;
				q->link=q->link->link;
				delete(temp);
				continue ;
			}
			q=q->link;
		}
		if(q->link->dest == dest)
		{
			temp=q->link;
			q->link=NULL;
			delete(temp);
		}
		ptr=ptr->next;
	}
}
void graph_control::display()
{
	node *ptr=start;
	edge *q=NULL;
	while(ptr != NULL)
	{
		q=ptr->adj;
		cout<<ptr->name<<" : ";
		while(q != NULL)
		{
			cout<<q->dest<<" , ";
			q=q->link;
		}
		cout<<endl;
		ptr=ptr->next;
	}
}
void graph_control::make_tree()
{
	memory tree[MAX];
	node *current=start;
	node *temp=NULL;
	node *temp2=NULL;
	edge *adj=NULL;
	int min=9999;
	current->status=1;
	current->distance=0;
	int count=0;
	while(all_perm(start) != true)
	{
		adj=current->adj;
		while(adj != NULL)
		{
			temp=find(adj->dest);
			if(temp->status == 0)
			{
				if(adj->cost < temp->distance)
				{
					temp->previous=current->name;
					temp->distance=adj->cost;
				}
			}
			adj=adj->link;
		}
		//Searching for temp node with minimum distance
		min=9999;
		temp2=start;
		while(temp2 != NULL)
		{
			if(temp2->status == 0 && temp2->distance < min)
			{
				min=temp2->distance;
				current = temp2;
			}
			temp2=temp2->next;
		}
		current->status=1;
		//Inserting edge in memory
		tree[count].u=current->previous;
		tree[count].v=current->name;
		cout<<tree[count].u<<"->"<<tree[count].v<<endl;
		count++;
	}
}
bool graph_control::all_perm(node *start)
{
	node *q=start;
	while(q != NULL)
	{
		if(q->status == 0)
		{
			return false;
		}
		q=q->next;
	}
	return true;
}
