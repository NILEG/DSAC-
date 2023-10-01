#ifndef my_header_H
#define my_header_H
#include <iostream>
using namespace std;
struct node
{
	string data;
	struct node *link;
};

struct control
{
	public: 
	struct node *start=NULL;
	
	void create(string data);
	void display();
	void del(int pos);
};
#endif
