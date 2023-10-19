#ifndef my_header_h
#define my_header_h
#include<iostream>
using namespace std;
struct Queue_St
{
	public:
		int queue[10];
		int Max=10;
		int rear=-1, front=-1;
		
	void enqueue(int data);
	int dequeue();
	void display();
};
#endif
