#include "my_header.h"
#include<iostream>
using namespace std;
int main()
{
	struct control cont;
	string inp;
	for(int i=0; i<6; i++)
	{
		getline(cin, inp);
		cont.create(inp);
	}
	cout<<"Forward Display"<<endl;
	cont.fdisplay();
	cout<<"Deleting pos: 1 Item"<<endl;
	cont.del(1);
	cout<<"Backward Display"<<endl;
	cont.bdisplay();
	return 0;
}
