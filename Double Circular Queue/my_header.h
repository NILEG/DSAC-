#ifndef my_header_H
#define my_header_H
#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node *link=NULL, *pre=NULL;
};

struct control
{
	public: 
	struct node *rear=NULL, *front=NULL, *start=NULL, *end=NULL;
	int counter=0;
	int nodes=0;
	int Max=10;
	
	void enqueue_left(int data);
	void enqueue_right(int data);
	int dequeue_left();
	int dequeue_right();
	void display();
};
#endif
