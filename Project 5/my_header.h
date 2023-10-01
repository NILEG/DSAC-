#ifndef my_header_h
#define my_header_h
#include<iostream>
using namespace std;
struct node
{
	string data;
	struct node *next, *pre;
};
struct control
{
	public:
		struct node *tail=NULL;
		
	void create(string data);
	void del(int pos);
	void fdisplay();
	void bdisplay();
};
#endif
