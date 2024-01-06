/*
	Name: Huffman
	Version: 0.1
	Date: 02-12-2023
	Author: @Umair-PC
*/
#include "my_header.h"
#include<graphics.h>
#include<string>
#include<sstream>  
#include<cstring>
using namespace std;
void control::swaping_to_balance(node *&ref)
{
	int key_temp;
	string name;
	node *sub_left;
	node *sub_right;
	node *ptr=ref;
	while(ptr->parent != NULL)
	{
		if(ptr->key < ptr->parent->key)
		{
			key_temp=ptr->key;
			name=ptr->name;
			sub_left=ptr->sub_left;
			sub_right=ptr->sub_right;
			
			ptr->key=ptr->parent->key;
			ptr->name=ptr->parent->name;
			ptr->sub_left=ptr->parent->sub_left;
			ptr->sub_right=ptr->parent->sub_right;
			
			ptr->parent->key=key_temp;
			ptr->parent->name=name;
			ptr->parent->sub_left=sub_left;
			ptr->parent->sub_right=sub_right;
		}
		ptr=ptr->parent;
	}
}
void control::swaping_after_del(node *&ref)
{
	int key_temp;
	string name;
	node *sub_left;
	node *sub_right;
	node *ptr=ref;
	node *child_with_small_key;
	//Changed || to &&
	while(ptr->left != NULL && ptr->right != NULL)
	{
		if(ptr->left->key < ptr->right->key)
		{
			child_with_small_key=ptr->left;
		}
		else
		{
			child_with_small_key=ptr->right;
		}
		if(child_with_small_key->key < ptr->key)
		{
			key_temp=ptr->key;
			name=ptr->name;
			sub_left=ptr->sub_left;
			sub_right=ptr->sub_right;
			
			ptr->key=child_with_small_key->key;
			ptr->name=child_with_small_key->name;
			ptr->sub_left=child_with_small_key->sub_left;
			ptr->sub_right=child_with_small_key->sub_right;
			
			child_with_small_key->key=key_temp;
			child_with_small_key->name=name;
			child_with_small_key->sub_right=sub_right;
			child_with_small_key->sub_left=sub_left;
		}
		ptr=child_with_small_key;
	}
	//Change started
	if(ptr->left!=NULL)
	{
		child_with_small_key=ptr->left;
		if(child_with_small_key->key < ptr->key)
		{
			key_temp=ptr->key;
			name=ptr->name;
			sub_left=ptr->sub_left;
			sub_right=ptr->sub_right;
			
			ptr->key=child_with_small_key->key;
			ptr->name=child_with_small_key->name;
			ptr->sub_left=child_with_small_key->sub_left;
			ptr->sub_right=child_with_small_key->sub_right;
			
			child_with_small_key->key=key_temp;
			child_with_small_key->name=name;
			child_with_small_key->sub_right=sub_right;
			child_with_small_key->sub_left=sub_left;
		}
	}
	//Change Ended
}
int control::get_height(node *ptr, bool &status)
{
	if(ptr == NULL)
	{
		return 0;
	}
	else
	{
		
		int ld= get_height(ptr->left, status);
		int rd= get_height(ptr->right, status);
		if(ld != rd)
		{
			status = false;
		}
		if(rd > ld)
		{
			return rd+1;
		}
		else
		{
			return ld+1;
		}
	}
} 
void control::insert(node *&root, int key, string name, node *sub_left, node *sub_right, char ins_for)
{
	node *temp=new node();
	temp->key=key;
	temp->name=name;
	temp->sub_left=sub_left;
	temp->sub_right=sub_right;
	if(root == NULL)
	{
		root=temp;
	}
	else
	{
		node *q=root, *parent=NULL;
		while(q != NULL)
		{
			bool l_status=true;
			int lh=get_height(q->left, l_status);
			bool r_status=true;
			int rh=get_height(q->right, r_status);
			if(lh >rh && l_status == true)
			{
				parent=q;
				q=q->right;
			}
			else if(lh == rh && r_status == false)
			{
				parent=q;
				q=q->right;
			}
			else
			{
				parent=q;
				q=q->left;
			}
		}
		if(parent->left == NULL)
		{
			parent->left=temp;
			temp->parent=parent;
		}
		else
		{
			parent->right=temp;
			temp->parent=parent;
		}
		//Printing the GUI of Huffman Tree
		if(ins_for=='h')
		{
			setbkcolor(BLACK); 
			cleardevice(); 
			int level=get_huffman_height(temp);
			create(temp, x1, y1, x2, y2, level);
		}
		//Ended Here
		swaping_to_balance(temp);
	}
	
}
int control::max_depth(node *ptr)
{
	if(ptr == NULL)
	{
		return 0;
	}
	else
	{
		int ld= max_depth(ptr->left);
		int rd= max_depth(ptr->right);
		if(rd > ld)
		{
			return rd+1;
		}
		else
		{
			return ld+1;
		}
	}
}
int control::get_huffman_height(node *ptr)
{
	if(ptr == NULL)
	{
		return 0;
	}
	else
	{
		int ld= get_huffman_height(ptr->sub_left);
		int rd= get_huffman_height(ptr->sub_right);
		if(rd > ld)
		{
			return rd+1;
		}
		else
		{
			return ld+1;
		}
	}
}
void control::print_level(node *ptr, int level)
{
	if(ptr== NULL)
	{
		return;
	}
	if(level==0)
	{
		cout<<ptr->key<<" ";
	}
	else
	{
		print_level(ptr->left, level-1);
		print_level(ptr->right, level-1);
	}
}
void control::level_order_traversel()
{
	int height=max_depth(main_root);
	for(int i=0; i<height; i++)
	{
		print_level(main_root, i);
		cout<<endl;
	}
}
node * control::get_last_node(node *&root)
{
	node *q=root, *loc=NULL;
	while(q != NULL)
	{
		bool l_status=true;
		int lh=get_height(q->left, l_status);
		bool r_status=true;
		int rh=get_height(q->right, r_status);
		if(lh == rh)
		{
			loc=q;
			q=q->right;
		}
		else if(lh>rh)
		{
			loc=q;
			q=q->left;
		}
	}
	return loc;
}
node * control::pop(node *&root)
{
	node *loc=root;
	node *lastNode=get_last_node(root);
	//Case-A: 
	if(loc->left == NULL && loc->right == NULL)
	{
		root=NULL;
	}
	//Case-B
	else if(loc->left != NULL && loc->right == NULL)
	{
		root=loc->left;
		root->parent=NULL;
	}
	//Case-C
	else
	{
		node *lastNp=lastNode->parent;
		//Detaching Last Node
		if(lastNp->left == lastNode)
		{
			lastNp->left=NULL;
		}
		else
		{
			lastNp->right=NULL;
		}
		lastNode->left=root->left;
		lastNode->right=root->right;
		lastNode->parent=NULL;
		
		root->left->parent=lastNode;
		//This if is a change
		if(root->right != NULL)
		root->right->parent=lastNode;
		
		root=lastNode;
		swaping_after_del(lastNode);
	}
	return loc;
}
void control::total_item(node *ptr, int &count)
{
	if(ptr == NULL)
	{
		return ;
	}
	else
	{
		count=count+1;
		total_item(ptr->left, count);
		total_item(ptr->right, count);
	}
}
void control::make_huffman_tree()
{
	node *ptr1;
	node *ptr2;
	node *temp;
	//2. Take Input
	get_input();
	//Ended
	while(main_root->left != NULL || main_root->right != NULL)
	{
		show_top_queue();
		mouse_wait_action();
		ptr1=pop(main_root);
		ptr2=pop(main_root);
		insert(main_root, ptr1->key+ptr2->key, "?", ptr1, ptr2, 'h');
	}
	//Graphics Instruction: Printing the last Item
	setbkcolor(BLACK); 
	cleardevice(); 
	show_top_queue();
	int level=get_huffman_height(main_root);
	create(main_root, x1, y1, x2, y2, level);
	//Show Codes
	mouse_wait_action();
	int window3=initwindow(1000, 600);
	setcurrentwindow(window3);
	show_codes(main_root, "");
	setcurrentwindow(window1);
	//Ended Here	
}
void control::show_codes(node *ptr, string code)
{
	if(ptr == NULL)
	{
		return;
	}
	else if(ptr->sub_left == NULL && ptr->sub_right == NULL)
	{
		settextstyle(8, 0, 2);
		setcolor(WHITE);
		setbkcolor(BLACK);
		char* char_arr = &ptr->name[0]; 
		outtextxy(200, code_height, char_arr);
		outtextxy(250, code_height, " : ");
		char* char_arr_1 = &code[0]; 
		outtextxy(300, code_height, char_arr_1);
		code_height=code_height+50;
		cout<<code<<" : "<<ptr->name<<endl;
		return ;
	}
	else
	{
		code.push_back('0');
		show_codes(ptr->sub_left, code);
		if(!code.empty())
		code = code.substr(0, code.size()-1);
		code.push_back('1');
		show_codes(ptr->sub_right, code);
	}
}
void control::create(node *ptr, int x1, int y1, int x2, int y2, int level)
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
	    //Labeling Line
	    if(x1-x2<0)
	    {
	    	settextstyle(8, 0, 2);
			setcolor(WHITE);
			setbkcolor(BLACK);
	    	outtextxy(x1+(x2-x1)/2, y2,"0");
		}
		else if(x1-x2>0)
		{
			settextstyle(8, 0, 2);
			setcolor(WHITE);
			setbkcolor(BLACK);
			outtextxy(x1-5-(x1-x2)/2, y2,"1");
		}
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
			setbkcolor(RED);
		}
		else //Show Sum on the node
		{
			stringstream ss;  
			ss<<ptr->key;  
			string s;  
			ss>>s;
			settextstyle(3, 0, 3);
			setbkcolor(RED);
			setcolor(WHITE);
			char* char_arr = &s[0]; 
			outtextxy(x1-14, y1-10, char_arr); 
		}
		//Creating  Circle(for hiding line)
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,RED);
		circle(x2, y2, 30);
		floodfill(x2,y2,WHITE);
		//Recursion
	    create(ptr->sub_left, x1-(50*level), y1+80, x1, y1, level-1);
	    create(ptr->sub_right, x1+(50*level), y1+80, x1, y1, level-1);
	}
}
void control::create_Queue_GUI()
{	
	int counter=0;
	total_item(main_root, counter);
	int x=(getmaxx()/2)-(counter/2)*sqr_w;
	clear_KeyLoc(); //Firstly Clear Key Location Linked List
	for(int i=0; i<counter; i++)
	{
		node *ptr_temp=pop(main_root);
		insert(temp_root, ptr_temp->key, ptr_temp->name, ptr_temp->sub_left, ptr_temp->sub_right, 'm');
		//Text Block
			//Converting INT to STRING
			stringstream ss;  
			ss<<ptr_temp->key;  
			string s;  
			ss>>s;
			//ENDED
			settextstyle(3, 0, 4);
			setcolor(WHITE);
			if(ptr_temp->sub_left == NULL)
			setbkcolor(RED);
			else
			setbkcolor(GREEN);
			char* char_arr = &s[0]; 
			outtextxy(x+10, sqr_y+25, char_arr); 
			//SHOWING CHARACTER
			if(ptr_temp->sub_left == NULL)
			{
				setbkcolor(BLACK);
				settextstyle(8, 0, 4);
				setcolor(WHITE);
				char* char_arr = &ptr_temp->name[0]; 
				outtextxy(x+10, sqr_y+85, char_arr); 
			}
			//ENDED
		//Text Block Ended
		setcolor(WHITE);
		insert_into_keyLoc(ptr_temp->key, x, x+sqr_w, sqr_y, sqr_y+sqr_h); //Insert Key along with Location into KeyLoc
		rectangle(x, sqr_y, x+sqr_w, sqr_y+sqr_h);
		if(ptr_temp->sub_left == NULL)
		setfillstyle(SOLID_FILL,RED);
		else
		setfillstyle(SOLID_FILL,GREEN);
		floodfill(x+10,sqr_y+10,WHITE);
		x=x+(sqr_w+10);
	}
	//Create Bottom Next Button
	next_btn();
}
void control::next_btn()
{
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,BLUE);
	rectangle(getmaxx()-150, getmaxy()-100, getmaxx()-50, getmaxy()-50);
	floodfill(getmaxx()-100,getmaxy()-75,WHITE);
	settextstyle(3, 0, 4);
	setcolor(WHITE);
	setbkcolor(BLUE);
	outtextxy(getmaxx()-140, getmaxy()-90, "Next");
}
void control::copying_temp_to_main()
{
	int counter=0;
	node *ptr;
	total_item(temp_root, counter);
	for(int i=0; i<counter; i++)
	{
		ptr=pop(temp_root);
		insert(main_root, ptr->key, ptr->name, ptr->sub_left, ptr->sub_right, 'm');
	}
}
void control::show_top_queue()
{
	create_Queue_GUI();
	copying_temp_to_main();
}
void control::clear_KeyLoc()
{
	KeyLoc *temp=NULL;
	while(start != NULL)
	{
		temp=start;
		start=start->next;
		delete(temp);
	}
}
void control::insert_into_keyLoc(int key, int x1, int x2, int y1, int y2)
{
	KeyLoc *q=start;
	KeyLoc *temp=new KeyLoc();
	temp->key=key;
	temp->x1=x1;
	temp->x2=x2;
	temp->y1=y1;
	temp->y2=y2;
	if(start == NULL)
	{
		start=temp;
	}
	else
	{
		while(q->next != NULL)
		{
			q=q->next;
		}
		q->next=temp;
	}
}
void control::mouse_wait_action()
{
	while(1)
	{
		 while (!ismouseclick(WM_LBUTTONDOWN))
		 {
		 	delay(100);
		 }
		 int x, y; 
		 getmouseclick(WM_LBUTTONDOWN, x, y);
		 //If User has clicked on next Button
		 int x1=getmaxx()-150, y1=getmaxy()-100, x2=getmaxx()-50, y2=getmaxy()-50;
		 if(x>x1 && x<x2 && y>y1 && y<y2)
		 {
		 	break;
		 }
		 else
		 {
		 	int key=get_key_of_loc(x, y);
		 	if(key != -404)
		 	{
		 		node *loc=NULL;
		 		//Open Second Screen
		 		window2=initwindow(1000,1000);
		 		//Get the location
		 		find_loc(key, main_root, loc);
		 		//Display Structure
		 		setcurrentwindow(window2);
		 		int level=get_huffman_height(loc);
				create(loc, 500, 50, 500, 50, level);
		 		setcurrentwindow(window1);
			}
		 }
	}
}
int control::get_key_of_loc(int x, int y)
{
	KeyLoc *q=start;
	int x1, x2, y1, y2;
	while(q != NULL)
	{
		x1=q->x1;
		x2=q->x2;
		y1=q->y1;
		y2=q->y2;
		if(x>x1 && x<x2 && y>y1 && y<y2)
		{
			return q->key;
		}
		q=q->next;
	}
	return -404;
}
void control::find_loc(int key, node *ptr, node *&loc)
{
	if(ptr == NULL)
	{
		return ;
	}
	else if(ptr->key == key)
	{
		loc=ptr;
		return ;
	}
	else
	{
		find_loc(key, ptr->left, loc);
		find_loc(key, ptr->right, loc);
	}
}
void control::introduction()
{
	//Next Button
	next_btn();
	//Definition
		//Heading
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(BLACK);
		outtextxy(getmaxx()/2-100, 10, "Huffman Tree");
		//Explanation
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(BLACK);
		outtextxy(200, 50, "Huffman coding is a lossless data compression algorithm.");
		outtextxy(25, 90, "The idea is to assign variable-length codes to characters based on their frequency.");
	while(1)
	{
		while (!ismouseclick(WM_LBUTTONDOWN))
		{
			delay(100);
		}
		int x, y; 
		getmouseclick(WM_LBUTTONDOWN, x, y);
		//If User has clicked on next Button
		int x1=getmaxx()-150, y1=getmaxy()-100, x2=getmaxx()-50, y2=getmaxy()-50;
		if(x>x1 && x<x2 && y>y1 && y<y2)
		{
			break;
		}
	}
	//Example
		//Heading
		settextstyle(3, 0, 4);
		setcolor(RED);
		setbkcolor(BLACK);
		outtextxy(50, 130, "Example: ");
		//Explanation
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(BLACK);
		outtextxy(50, 170, "Data: AAAAAAAABBBBCCCCCDD      (We want to send this data on the Network)");
	while(1)
	{
		while (!ismouseclick(WM_LBUTTONDOWN))
		{
			delay(100);
		}
		int x, y; 
		getmouseclick(WM_LBUTTONDOWN, x, y);
		//If User has clicked on next Button
		int x1=getmaxx()-150, y1=getmaxy()-100, x2=getmaxx()-50, y2=getmaxy()-50;
		if(x>x1 && x<x2 && y>y1 && y<y2)
		{
			break;
		}
	}
	//Step-1
		//Heading
		settextstyle(3, 0, 4);
		setcolor(RED);
		setbkcolor(BLACK);
		outtextxy(50, 200, "Step-1:        (We are going to calculate the frequency)");
		//A
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(BLACK);
		outtextxy(50, 235, "A -> 8");
		//B
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(BLACK);
		outtextxy(50, 270, "B -> 4");
		//C
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(BLACK);
		outtextxy(50, 305, "C -> 5");
		//D
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(BLACK);
		outtextxy(50, 340, "D -> 2");
	while(1)
	{
		while (!ismouseclick(WM_LBUTTONDOWN))
		{
			delay(100);
		}
		int x, y; 
		getmouseclick(WM_LBUTTONDOWN, x, y);
		//If User has clicked on next Button
		int x1=getmaxx()-150, y1=getmaxy()-100, x2=getmaxx()-50, y2=getmaxy()-50;
		if(x>x1 && x<x2 && y>y1 && y<y2)
		{
			break;
		}
	}
	//Step-2
		//Heading
		settextstyle(3, 0, 4);
		setcolor(RED);
		setbkcolor(BLACK);
		outtextxy(50, 380, "Step-2:");
		//Select
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(BLACK);
		outtextxy(50, 410, "Select two low frequency nodes and make a tree.");
		outtextxy(50, 440, "The internel node frequency will be their sum.");
	while(1)
	{
		while (!ismouseclick(WM_LBUTTONDOWN))
		{
			delay(100);
		}
		int x, y; 
		getmouseclick(WM_LBUTTONDOWN, x, y);
		//If User has clicked on next Button
		int x1=getmaxx()-150, y1=getmaxy()-100, x2=getmaxx()-50, y2=getmaxy()-50;
		if(x>x1 && x<x2 && y>y1 && y<y2)
		{
			break;
		}
	}
	//Creating the tree
		//Creating Lines
		setcolor(YELLOW);
		line(600, 560, 550, 640);
		line(600, 560, 650, 640);
		//Internel Circle
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,RED);
		circle(600, 560, 30);
		floodfill(600,560,WHITE);
		//D Circle
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,BLUE);
		circle(550, 640, 30);
		floodfill(550,640,WHITE);
		//B Circle
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,BLUE);
		circle(650, 640, 30);
		floodfill(650,640,WHITE);
		//Putting Text
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(RED);
		outtextxy(590, 545, "6");
		
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(BLUE);
		outtextxy(540, 625, "2");
		
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(BLACK);
		outtextxy(540, 680, "D");
		
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(BLUE);
		outtextxy(640, 625, "4");
		
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(BLACK);
		outtextxy(640, 680, "B");
		
		//Updated Data
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(BLACK);
		outtextxy(800, 620, "Updated Frequency:   5, 6, 8");
	while(1)
	{
		while (!ismouseclick(WM_LBUTTONDOWN))
		{
			delay(100);
		}
		int x, y; 
		getmouseclick(WM_LBUTTONDOWN, x, y);
		//If User has clicked on next Button
		int x1=getmaxx()-150, y1=getmaxy()-100, x2=getmaxx()-50, y2=getmaxy()-50;
		if(x>x1 && x<x2 && y>y1 && y<y2)
		{
			break;
		}
	}
	//Step-3
		//Heading
		settextstyle(3, 0, 4);
		setcolor(RED);
		setbkcolor(BLACK);
		outtextxy(50, 720, "Step-3:");
		setcolor(WHITE);
		outtextxy(300, 720, "Repeat step two until only one element in left in queue.");
		
	while(1)
	{
		while (!ismouseclick(WM_LBUTTONDOWN))
		{
			delay(100);
		}
		int x, y; 
		getmouseclick(WM_LBUTTONDOWN, x, y);
		//If User has clicked on next Button
		int x1=getmaxx()-150, y1=getmaxy()-100, x2=getmaxx()-50, y2=getmaxy()-50;
		if(x>x1 && x<x2 && y>y1 && y<y2)
		{
			break;
		}
	}
	cleardevice();
}
void control::get_input()
{
	string a, b;
	cin.ignore();
	cout<<"Enter the data: "<<endl;
	getline(cin, a);
	string temp="";
	int count=0;
	for(int i=0; i<a.size(); i++)
	{
		if(temp.find(a[i]) >= temp.length())
		{
			temp.push_back(a[i]);
		}
	}
	for(int i=0; i<temp.size(); i++)
	{
		for(int j=0; j<a.size(); j++)
		{
			if(temp[i] == a[j])
			{
				count++;
			}
		}
		b=temp[i];
		insert(main_root, count, b, NULL, NULL, 'm');
		count=0;
	}
}
void control::memory_view()
{
	//int level=get_huffman_height(main_root);
	//create(main_root, x1, y1, x2, y2, level);
	outtextxy(700, 20, "Memory Diagram");
	int counter=1;
	int x=500, y=100, width=80, height=50;
	create_memory_view(main_root, x,y,width, height, "A1", counter);
}
void control::create_memory_view(node * ptr, int x, int y, int width, int height, string address, int &counter)
{
	if(ptr == NULL)
	{
		return ;
	}
	else
	{
		address = address.substr(0, address.size()-1);
		counter++;
		stringstream stream;
		string str;
		stream << address<<counter;
		address=stream.str();
		rectangle(x, y, x+width, y+height);
		rectangle(x-30, y, x, y+height);
		rectangle(x+width, y, x+width+30, y+height);
		outtextxy(x+30, y-20, &address[0]);
		outtextxy(x+30, y+20, &(ptr->name[0]));
		//Creating Box containing Left child address
		if(ptr->sub_left != NULL)
		{
			string temp_str=address.c_str();
			temp_str = temp_str.substr(0, temp_str.size()-1);
			int dumy=counter+1;
			stringstream stream2;
			stream2<<temp_str<<dumy;
			string str2;
			str2=stream2.str();
			outtextxy(x-20, y+20, &str2[0]);
		}
		//Left Recursive Call
		create_memory_view(ptr->sub_left, x-200, y+80, width, height, address, counter);
		//Creating Box containing Right child address
		if(ptr->sub_right != NULL)
		{
			string temp_str2=address.c_str();
			temp_str2 = temp_str2.substr(0, temp_str2.size()-1);
			int dumy2=counter+1;
			stringstream stream3;
			stream3<<temp_str2<<dumy2;
			string str3;
			str3=stream3.str();
			outtextxy(x+width+10, y+20, &str3[0]);
		}
		//Right Recursive Call
		create_memory_view(ptr->sub_right, x+150, y+100, width, height, address, counter);
	}
}
void control::quiz()
{
	int score = 0;
    int totalQuestions = 20; // Number of MCQs

    Question quizQuestions[20] = {
        {
            "What type of tree is a Huffman tree?",
            {"A. Specific type of binary tree", "B. Binary Search Tree", "C. AVL Tree", "D. Red-Black Tree"},
            0 // Correct option index (A)
        },
        {
            "Which property ensures the optimality of Huffman codes?",
            {"A. Prefix property", "B. Suffix property", "C. Equidistant property", "D. Variable property"},
            0 // Correct option index (A)
        },
        {
            "How are Huffman codes represented in terms of code length?",
            {"A. Variable-length codes", "B. Fixed-length codes", "C. Equal-length codes", "D. Incremental-length codes"},
            0 // Correct option index (A)
        },
        {
            "What is the primary criterion for constructing a Huffman tree?",
            {"A. Frequency of characters", "B. Depth of the tree", "C. Number of nodes", "D. Height of the tree"},
            0 // Correct option index (A)
        },
        {
            "Which nodes represent individual characters in a Huffman tree?",
            {"A. Leaf nodes", "B. Internal nodes", "C. Root nodes", "D. None of the above"},
            0 // Correct option index (A)
        },
        {
            "What happens to the code length as the frequency of a character increases in Huffman coding?",
            {"A. Increases", "B. Decreases", "C. Remains constant", "D. Cannot be determined"},
            1 // Correct option index (B)
        },
        {
            "How are Huffman codes assigned to characters?",
            {"A. Sequentially", "B. Based on frequency", "C. Alphabetically", "D. Randomly",},
            1 // Correct option index (B)
        },
        {
            "In Huffman coding, what is the expected result of characters with lower frequencies?",
            {"A. Shorter codes", "B. Longer codes", "C. Equal-length codes", "D. No specific pattern"},
            1 // Correct option index (B)
        },
        {
            "Which algorithm constructs a Huffman tree?",
            {"A. Breadth-First Search", "B. Greedy algorithm", "C. Depth-First Search", "D. Dijkstra's algorithm"},
            1 // Correct option index (B)
        },
        {
            "What is the purpose of using Huffman coding in data compression?",
            {"A. To minimize compression time", "B. To maximize compression ratios", "C. To reduce compression quality", "D. To optimize compression for specific data types"},
            1 // Correct option index (B)
        },
        {
            "In Huffman coding, what is the main advantage of shorter codes for frequently used characters?",
            {"A. Lesser memory usage", "B. Faster encoding", "C. Improved compression ratios", "D. Easier decoding"},
            2 // Correct option index (C)
        },
        {
            "Which step is NOT a part of Huffman coding algorithm?",
            {"A. Constructing a frequency table", "B. Building a Huffman tree", "C. Balancing the tree", "D. Assigning codes to characters",},
            2 // Correct option index (C)
        },
        {
            "What happens if two characters have the same frequency in Huffman coding?",
            {"A. Both characters are discarded", "B. One character is randomly assigned a code", "C. Their codes are concatenated", "D. Their codes are interchanged"},
            2 // Correct option index (C)
        },
        {
            "Which operation involves combining two nodes with the lowest frequencies in Huffman tree construction?",
            {"A. Split", "B. Swap", "C. Merge", "D. Join"},
            2 // Correct option index (C)
        },
        {
            "What is the Huffman code for a character that appears most frequently?",
            {"A. Longer code", "B. No code is assigned", "C. Shorter code", "D. Code is decided randomly"},
            2 // Correct option index (C)
        },
        {
            "Which data structure is commonly used to implement a priority queue in Huffman coding?",
            {"A. Array", "B. Linked List", "C. Stack", "D. Heap"},
            3 // Correct option index (D)
        },
        {
            "Which operation reduces the average code length in Huffman coding?",
            {"A. Splitting nodes", "B. Removing nodes", "C. Reordering nodes", "D. Merging nodes", },
            3 // Correct option index (D)
        },
        {
            "Which step ensures uniquely decodable codes in Huffman coding?",
            {"A. Codes are assigned alphabetically", "B. Codes have equal lengths", "C. All codes start with '0'", "D. No code is a prefix of another code"},
            3 // Correct option index (D)
        },
        {
            "What is the primary application of Huffman coding in data transmission?",
            {"A. Image compression", "B. Audio compression", "C. Video compression", "D. Text compression"},
            3 // Correct option index (D)
        },
        {
            "What is the primary aim of Huffman coding?",
            {"A. Maximizing compression time", "B. Minimizing compression ratios", "C. Reducing compression quality", "D. Maximizing compression ratios"},
            3 // Correct option index (D)
        }
// Add more questions..
    };

    cout << "Welcome to the Huffman Data Structure MCQs Quiz!\n" << endl;

    for (int i = 0; i < totalQuestions; ++i) {
        cout << "Question " << i + 1 << ": " << quizQuestions[i].question << endl;

        for (int j = 0; j < 4; ++j) {
            cout << quizQuestions[i].options[j] << endl;
        }

        cout << "Enter your choice (A/B/C/D): ";
        char userChoice;
        cin >> userChoice;
        cin.ignore();

        int userOption = toupper(userChoice) - 'A'; // Convert user choice to index (0, 1, 2, 3)

        if (userOption >= 0 && userOption < 4) {
            if (userOption == quizQuestions[i].correctOption) {
                cout << "Correct!\n" << endl;
                score++;
            } else {
                cout << "Incorrect. The correct answer is: "
                     << quizQuestions[i].options[quizQuestions[i].correctOption] << "\n"
                     << endl;
            }
        } else {
            cout << "Invalid choice. Skipping to the next question.\n" << endl;
        }
    }

    // Display quiz results
    cout << "Quiz Completed!\n";
    cout << "You scored " << score << " out of " << totalQuestions << " correct.\n";
}
void control::pros_and_cons() {
    cout<< "Advantages of Huffman Data Structure:\n";
    cout<< "1. Efficient data compression: Provides good compression ratios for various data types.\n";
    cout<< "2. Simple implementation: Relatively easy to implement and understand.\n";
    cout<< "3. Minimal loss of data: Huffman encoding is a lossless compression technique.\n";
    cout<< "4. Variable-length encoding: Allows encoding with shorter codes for more frequent symbols.\n\n";

    cout<< "Disadvantages of Huffman Data Structure:\n";
    cout<< "1. Encoding and decoding overhead: Huffman encoding/decoding can be computationally expensive.\n";
    cout<< "2. Need for storage of encoding tree: Additional space required to store the Huffman tree.\n";
    cout<< "3. Lack of adaptability: Once the tree is built, it remains static for encoding/decoding.\n";
}

void control::uses() {
    cout<< "\nUses of Huffman Data Structure:\n";
    cout<< "1. Data compression: Huffman encoding is used in file compression algorithms.\n";
    cout<< "2. Network transmission: Efficient data encoding for network transmission.\n";
    cout<< "3. Lossless data compression: Used in various applications to compress data without loss.\n";
    cout<< "4. File storage: Compression of files for efficient storage.\n";
    cout<< "5. Encoding characters: Creating variable-length codes for characters in text.\n";
    cout<< "6. Image Compression: JPEG format utilizes Huffman encoding for smaller image sizes.\n";
    cout<< "7. Text Compression in Databases: Enhances query performance by compressing text data.\n";
    cout<< "8. Embedded Systems: Optimizes storage and transmission in constrained environments.\n";
    cout<< "9. Voice Encoding: Enables efficient compression of voice data in telecommunication.\n";
    cout<< "10. Genetic Sequencing: Huffman coding used in bioinformatics for DNA compression.\n";

}
void control::menu()
{
	int ch=0;
	while(ch != -1)
	{
		cout<<"===============================================\n1. Introduction\n2. Demonstration\n3. Memory View\n4. Quiz\n5. Advantages/Disadvantages\n6. Uses\n====To Exit: -1====\n:>";
		cin>>ch;
		switch(ch)
		{
			case 1:
				window1=initwindow(getmaxwidth(),getmaxheight()-10);
				introduction();
				closegraph();
				break;
			case 2:
				main_root=NULL;
				temp_root=NULL;
				start=NULL;
				window1=initwindow(getmaxwidth(),getmaxheight()-10);
				make_huffman_tree();
				getch();
				closegraph();
				break;
			case 3:
				window1=initwindow(getmaxwidth(),getmaxheight()-10);
				memory_view();
				getch();
				closegraph();
				break;
			case 4:
				quiz();
				break;
			case 5:
				pros_and_cons();
				break;
			case 6:
				uses();
				break;
			case -1:
				break;
			default:
				cout<<"-----------------Invalid Choice-----------------"<<endl;
		}
	}
}
void control::changes()
{
	changes_structure storage[20];
	string a;
	string b="";
	cout<<"Enter the data: "<<endl;
	getline(cin, a);
	string temp="";
	int sum=0;
	string concatenated_string="";
	int storage_counter=0;
	for(int i=0; i<a.size(); i++)
	{
		if(i!=0 && i%5 == 0)
		{
			storage[storage_counter].my_string=b;
			storage[storage_counter].sum=sum;
			//Convert sum to string and add in concatenated_string
			stringstream stream;
			string str;
			stream <<sum;
			concatenated_string +=stream.str();
			storage_counter++;
			//cout<<b<<endl;
			//cout<<"Sum: "<<sum<<endl;
			sum=0;
			b="";
		}
		b.push_back(a[i]);
		sum=sum+int(a[i]);
	}
	//Last Operation
	storage[storage_counter].my_string=b;
	storage[storage_counter].sum=sum;
	//Convert sum to string and add in concatenated_string
	stringstream stream;
	string str;
	stream <<sum;
	concatenated_string +=stream.str();
	storage_counter++;
	//cout<<b<<endl;
	//cout<<"Sum: "<<sum<<endl;
	sum=0;
	b="";
	cout<<"Concatenated String: "<<concatenated_string<<endl;
	//Decoding the concatenated String
	for(int i=0; i<concatenated_string.size(); i++)
	{
		if(i!=0 && i%3 == 0)
		{
			//Check for matching sum
			for(int j=0; j<storage_counter; j++)
			{
				if(sum == storage[j].sum)
				{
					cout<<sum<<" : "<<storage[j].my_string<<endl;
					sum=0;
					break;
				}
			}
			
		}
		sum=sum*10+(concatenated_string[i]-'0');
	}
	for(int j=0; j<storage_counter; j++)
	{
		if(sum == storage[j].sum)
		{
			cout<<sum<<" : "<<storage[j].my_string<<endl;
			sum=0;
			break;
		}
	}
}
