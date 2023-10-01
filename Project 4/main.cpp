#include "my_header.h"
#include<iostream>
using namespace std;
int main()
{
	int roll;
	string name, cls;
	struct control cont;
	for(int i=0; i<5; i++)
	{
		getline(cin, name);
		getline(cin, cls);
		cin>>roll;
		cin.ignore();
		//cout<<name<<"\n"<<cls<<"\n"<<roll<<endl;
		cont.create(roll, name, cls);
	}
	cont.display();
	cont.del(2);
	cout<<"\nAfter Deleting position 2\n"<<endl;
	cont.display();
	cont.search("umair");
	return 0;
}

