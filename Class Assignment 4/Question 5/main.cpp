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
	c2.insert_edge('A', 'B', 7);
	c2.insert_edge('B', 'A', 7);
	
	c2.insert_edge('A', 'C', 8);
	c2.insert_edge('C', 'A', 8);
	
	c2.insert_edge('B', 'D', 6);
	c2.insert_edge('D', 'B', 6);
	
	c2.insert_edge('D', 'C', 4);
	c2.insert_edge('C', 'D', 4);
	
	c2.insert_edge('B', 'C', 1);
	c2.insert_edge('C', 'B', 1);
	
	c2.insert_edge('B', 'F', 1);
	c2.insert_edge('F', 'B', 1);
	
	c2.insert_edge('C', 'F', 3);
	c2.insert_edge('F', 'C', 3);
	
	c2.insert_edge('D', 'F', 2);
	c2.insert_edge('F', 'D', 2);
	
	c2.insert_edge('F', 'E', 2);
	c2.insert_edge('E', 'F', 2);
	
	c2.insert_edge('E', 'D', 5);
	c2.insert_edge('D', 'E', 5);
	
	c2.insert_edge('A', 'A', 0);
	c2.insert_edge('E', 'E', 1);
	c2.make_tree();
}
