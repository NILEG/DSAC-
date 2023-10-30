#include "my_header.h"
int main()
{
	control c1;
	c1.push_change("1. Font changed");
	c1.push_change("2. Color Changed to Red");
	c1.push_change("3. Heading Included");
	c1.display_stack();
	//poping previously made change
	c1.pop_change();
	cout<<"Undo the last change"<<endl;
	c1.display_stack();
}
