#include "my_header.h"
int main()
{
	graph_control c2;
	c2.insert_node('A');
	c2.insert_node('B');
	c2.insert_node('C');
	c2.insert_node('D');
	c2.insert_node('E');
	c2.insert_node('F');
	c2.insert_node('G');
	c2.insert_node('H');
	c2.insert_edge('A', 'C', 2);
	c2.insert_edge('A', 'D', 7);
	c2.insert_edge('A', 'B', 8);
	c2.insert_edge('B', 'F', 16);
	c2.insert_edge('C', 'A', 5);
	c2.insert_edge('C', 'D', 4);
	c2.insert_edge('C', 'G', 3);
	c2.insert_edge('D', 'E', 9);
	c2.insert_edge('E', 'F', 5);
	c2.insert_edge('E', 'H', 8);
	c2.insert_edge('G', 'C', 6);
	c2.insert_edge('G', 'D', 3);
	c2.insert_edge('G', 'E', 4);
	c2.insert_edge('G', 'H', 5);
	c2.insert_edge('H', 'F', 2);
	//c2.findpath('A', 'F');
	c2.all_path('A');
}
