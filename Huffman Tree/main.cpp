#include "my_header.h"
#include<graphics.h>
#include<iostream>
#include<string>
using namespace std;
void create(node *ptr, int x1, int y1, int x2, int y2, int level)
{
	if(ptr ==NULL)
	{
		return ;
	}
	else
	{
		
		//Creating Line
		setcolor(YELLOW);
	    line(x1, y1, x2, y2);
	    //Creating  Circle
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,RED);
		circle(x1, y1, 30);
		floodfill(x1,y1,WHITE);
		//Putting Text
		if(ptr->sub_left == NULL && ptr->sub_right == NULL)
		{
			settextstyle(8, 0, 4);
			setcolor(WHITE);
			setbkcolor(RED);
			char* char_arr = &ptr->name[0]; 
			outtextxy(x1-10, y1-15,char_arr);
		}
		//Recursion
	    create(ptr->sub_left, x1-(30*level), y1+80, x1, y1, level-1);
	    create(ptr->sub_right, x1+(30*level), y1+80, x1, y1, level-1);
	}
}
int main()
{
	initwindow(1200,800);
	int x1=250, y1=100, x2=250, y2=100;
	control c1;
	c1.insert(5, "A", NULL, NULL);
	c1.insert(9, "B", NULL, NULL);
	c1.insert(12, "C", NULL, NULL);
	c1.insert(4, "D", NULL, NULL);
	c1.insert(23, "E", NULL, NULL);
	c1.insert(46, "F", NULL, NULL);
	c1.level_order_traversel();
	c1.make_huffman_tree();
	c1.show_codes(c1.root, "");
	create(c1.root, x1,y1,x2,y2, c1.get_huffman_height(c1.root));
	getch();
	closegraph();
}
