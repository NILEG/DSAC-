#ifndef my_header_H
#define my_header_H
#include <iostream>
using namespace std;
struct node
{
	string order_name;
	int price;
	struct node *link=NULL;
};

struct control
{
	public: 
	struct node *rear=NULL, *front=NULL, *start=NULL;
	int counter=0;
	int nodes=0;
	int Max=10;
	
	void enqueue();
	void dequeue();
	void display();
	void menu();
	void setMax(int max);
	
};
#endif
