#include "my_header.h"
#include<iostream>
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
int graph_control::vertices_len()
{
	int count=0;
	node *q=start;
	while(q != NULL)
	{
		count++;
		q=q->next;
	}
	return count;
}
void graph_control::insert_edge_queue(char src, char dest, int weight)
{
	Queue_Edge *temp=new Queue_Edge();
	temp->u=src;
	temp->v=dest;
	temp->weight=weight;
	if(front == NULL || temp->weight < front->weight)
	{
		temp->link=front;
		front=temp;
	}
	else
	{
		Queue_Edge *q=front;
		while(q->link !=NULL && q->link->weight <= temp->weight)
		q=q->link;
		
		temp->link=q->link;
		q->link=temp;
		if(q->link == NULL)
		temp->link = NULL;
	}
}
Queue_Edge* graph_control::pop_queue_edge()
{
	Queue_Edge *temp=front;
	front=front->link;
	return temp;
}
void graph_control::make_tree()
{
	int n=vertices_len();
	int count=0;
	char u,v, root_u, root_v;
	Queue_Edge *temp;
	node *q=start;
	node *temp_node;
	edge *adj;
	//Making priority Queue
	while(q != NULL)
	{
		adj=q->adj;
		while(adj != NULL)
		{
			insert_edge_queue(q->name, adj->dest, adj->cost);
			adj=adj->link;
		}
		q=q->next;
	}
	
	while(count< n-1)
	{
		temp=pop_queue_edge();
		u=temp->u;
		v=temp->v;
		while(u != '?')
		{
			root_u=u;
			temp_node=find(u);
			u=temp_node->previous;
		}
		while(v != '?')
		{
			root_v=v;
			temp_node=find(v);
			v=temp_node->previous;
		}
		if(root_u != root_v)
		{
			cout<<temp->u<<" -> "<<temp->v<<" :: "<<temp->weight<<endl;
			count++;
			temp_node=find(root_v);
			temp_node->previous=root_u;
		}
	}
}
