#ifndef my_header_h
#define my_header_h
#include<iostream>
using namespace std;
struct node
{
	string data;
	struct node *link;
};
struct control
{
	public:
		struct node * tail=NULL;
		struct node *list1=NULL;
		struct node *list2=NULL;
	void create(string data,struct node *& tail);
	void display(struct node * &tail);
	void display_mid(struct node *& tail, struct node * &list1, struct node * &list2);
	int count(struct node *& tail);		
};
#endif
