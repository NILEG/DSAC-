#ifndef my_header_H
#define my_header_H
#include <iostream>
using namespace std;
struct doc_undo
{
	string change_name;
	doc_undo *link;
};

struct control
{
	public:
		doc_undo *top=NULL;
	
	void push_change(string change_name);
	string pop_change();
	void display_stack();
};

#endif
