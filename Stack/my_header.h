#ifndef my_header_H
#define my_header_H
#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node *link=NULL;
};

struct control
{
	public: 
	struct node *top=NULL;
	
	void push(int data);
	int pop();
	void display();
	
};
#endif
