#include "my_header.h"
int main()
{
	control c1;
	c1.push(10);
	c1.push(11);
	c1.push(12);
	c1.push(13);
	c1.push(14);
	c1.push(15);
	c1.push(16);
	c1.push(17);
	c1.push(18);
	c1.push(19);
	c1.pop();
	c1.pop();
	c1.pop();
	c1.pop();
	c1.pop();
	c1.pop();
	c1.pop();
	c1.pop();
	c1.pop();
	c1.pop();
	c1.push(200);
	c1.push(100);
	c1.display();
}
