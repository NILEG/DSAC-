#ifndef my_header_H
#define my_header_H
#include <iostream>
using namespace std;
struct node
{
	string data;
	struct node *link=NULL, *pre=NULL;
};

struct control
{
	public: 
	struct node *rear=NULL, *front=NULL, *start=NULL;
	int counter=0;
	int nodes=0;
	int Max=10;
	
	void push();
	string pop();
	void display();
	void shuffle();
	void swapping(int i, int j);
	void menu();
};
#endif
