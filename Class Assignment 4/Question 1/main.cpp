#include "queue.h"
#include "graph.h"
int main()
{
	graph_control c2;
	c2.insert_node('A', 0);
	c2.insert_node('B', 1);
	c2.insert_node('C', 2);
	c2.insert_node('D', 3);
	c2.insert_node('E', 4);
	c2.insert_node('F', 5);
	c2.insert_node('G', 6);
	c2.insert_node('H', 7);
	c2.insert_node('I', 8);
	c2.insert_edge('A', 'B');
	c2.insert_edge('A', 'D');
	c2.insert_edge('A', 'E');
	c2.insert_edge('B', 'C');
	c2.insert_edge('B', 'E');
	c2.insert_edge('C', 'F');
	c2.insert_edge('D', 'G');
	c2.insert_edge('E', 'F');
	c2.insert_edge('E', 'H');
	c2.insert_edge('G', 'E');
	c2.insert_edge('G', 'H');
	c2.insert_edge('H', 'I');
	//c2.display();
	c2.bfs('A');
}
