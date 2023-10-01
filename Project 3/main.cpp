#include "my_header.h"
using namespace std;
int main()
{
	struct control cont;
	string inp;
	for(int i=0; i<6; i++)
	{
		getline(cin, inp);
		cont.create(inp,cont.tail);
	}
	cont.display_mid(cont.tail, cont.list1, cont.list2);
	return 0;
}
