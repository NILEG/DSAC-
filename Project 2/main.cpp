#include "my_header.h"
#include<iostream>
int main()
{
	string inp;
	struct control cont;
	for(int i=0; i<5; i++)
	{
		getline(cin, inp);
		cont.create(inp);
	}
	cont.del(3);
	cont.display();
	return 0;
}
