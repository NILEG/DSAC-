#ifndef my_header_H
#define my_header_H
#include <iostream>
using namespace std;
struct item
{
	string name;
	int price;
};
struct cart
{
	struct item *itm=NULL;
	struct cart *link=NULL, *pre=NULL;
};

struct control
{
	public: 
	struct cart *rear=NULL, *front=NULL, *start=NULL, *end=NULL;
	int counter=0;
	int nodes=0;
	int Max=10;
	
	void enqueue_left();
	void enqueue_right();
	void dequeue_left();
	void dequeue_right();
	void display();
	void menu();
};
#endif
