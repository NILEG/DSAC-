#include<iostream>
#include "my_header.h"
using namespace std;
int main()
{
	struct control c1;
	c1.create("Hello 1");
	c1.create("Hello 2");
	c1.create("Hello 3");
	c1.create("Hello 4");
	//Deleting hello 3
	c1.del(3);
	c1.display();
	return 0;
}
//How to program in C++ by Dietel & Dietel
