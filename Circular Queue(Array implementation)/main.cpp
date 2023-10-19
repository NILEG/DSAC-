#include "my_header.h"
int main()
{
	Queue_St q1;
	q1.enqueue(1);
	q1.enqueue(2);
	q1.enqueue(3);
	q1.enqueue(4);
	q1.enqueue(5);
	q1.enqueue(6);
	q1.enqueue(7);
	q1.enqueue(8);
	q1.enqueue(9);
	q1.enqueue(10);
	q1.dequeue();
	q1.dequeue();
	q1.dequeue();
	q1.enqueue(0);
	q1.enqueue(0);
	q1.enqueue(0);
	//q1.enqueue(0);
	q1.display();
}
