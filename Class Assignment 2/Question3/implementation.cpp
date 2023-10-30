#include "my_header.h"
#include<iostream>
using namespace std;

void control::push_change(string name)
{
	doc_undo *temp=new doc_undo();
	temp->change_name=name;
	temp->link=top;
	top=temp;
}
string control::pop_change()
{
	if(top==NULL)
	{
		cout<<"Stack Underflow";
		return "";
	}
	else
	{
		string change=top->change_name;
		doc_undo *temp=top;
		top=top->link;
		delete(temp);
		return change;
	}
}
void control::display_stack()
{
	doc_undo *q=top;
	while(q!=NULL)
	{
		cout<<q->change_name<<endl;
		q=q->link;
	}
}
