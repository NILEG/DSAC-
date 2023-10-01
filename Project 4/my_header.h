#ifndef my_header_h
#define my_header_h
#include<iostream>
using namespace std;
struct student
{
	int rollno;
	string name;
	string cls;
	struct student *next, *pre;
};
struct control
{
	public:
		struct student * tail=NULL;
	int to_index(char a);
	void create(int, string, string);
	void del(int pos);
	void display();
	void search(string);
};
#endif
