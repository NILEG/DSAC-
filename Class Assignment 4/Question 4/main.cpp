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
	c2.insert_edge('A', 'B', 5);
	c2.insert_edge('B', 'A', 5);
	c2.insert_edge('A', 'D', 9);
	c2.insert_edge('D', 'A', 9);
	c2.insert_edge('A', 'C', 14);
	c2.insert_edge('C', 'A', 14);
	c2.insert_edge('A', 'E', 7);
	c2.insert_edge('E', 'A', 7);
	c2.insert_edge('B', 'D', 11);
	c2.insert_edge('D', 'B', 11);
	c2.insert_edge('B', 'F', 3);
	c2.insert_edge('F', 'B', 3);
	c2.insert_edge('C', 'D', 2);
	c2.insert_edge('D', 'C', 2);
	c2.insert_edge('C', 'E', 8);
	c2.insert_edge('E', 'C', 8);
	c2.insert_edge('D', 'F', 6);
	c2.insert_edge('F', 'D', 6);
	c2.insert_edge('D', 'E', 4);
	c2.insert_edge('E', 'D', 4);
	c2.insert_edge('E', 'F', 19);
	c2.insert_edge('F', 'E', 19);
	//c2.findpath('A', 'F');
	c2.make_tree();
}
