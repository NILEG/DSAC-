#ifndef my_header_H
#define my_header_H
#include<iostream>
using namespace std;
struct node
{
	int data;
	node *link=NULL;
};

struct control
{
	public:
		node *top=NULL;
	int fibonnaci(int num);
	void push(int data);
	void display();
	int sum();
	void reverse(node *pre, node *current, node *next);
	void menu();
};

#endif
