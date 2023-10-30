#include "my_header.h"
int main()
{
	control c1;
	c1.enqueue_right(10);
	c1.enqueue_right(20);
	
	c1.enqueue_right(30);
	c1.enqueue_right(40);
	
	c1.enqueue_left(9);
	c1.enqueue_left(8);
	c1.reverse();
	c1.display();
	return 0;
}
