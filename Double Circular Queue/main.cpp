#include "my_header.h"
int main()
{
	control c1;
	c1.enqueue_right(10);
	c1.enqueue_right(20);
	
	c1.dequeue_right();
	c1.dequeue_left();
	
	c1.enqueue_right(10);
	c1.enqueue_right(20);
	
	c1.enqueue_left(30);
	c1.enqueue_left(40);
	
	c1.display();
	return 0;
}
