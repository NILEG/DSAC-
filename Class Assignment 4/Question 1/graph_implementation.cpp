#include "graph.h"
#include "queue.h"
#include<iostream>
using namespace std;
void graph_control::insert_node(char ch, int index)
{
	node *temp=new node();
	temp->name=ch;
	temp->index=index;
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
void graph_control::insert_edge(char source, char dest)
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
void graph_control::bfs(char v)
{
	bool visited[20];
	for(int i=0; i<20; i++)
	{
		visited[i]=false;
	}
	node *temp=NULL, *temp2=NULL;
	control que;
	node *q=find(v);
	cout<<q->name<<", ";
	que.push(q);
	visited[q->index]=true;
	while(que.rear != NULL && que.front != NULL)
	{
		temp=que.pop();
		edge *adj=temp->adj;
		while(adj != NULL)
		{
			temp2=find(adj->dest);
			if(visited[temp2->index] == false)
			{
				cout<<temp2->name<<", ";
				visited[temp2->index]=true;
				que.push(temp2);
			}
			adj=adj->link;
		}
	}
}
