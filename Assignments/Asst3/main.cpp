//
//  main.cpp
//  Assignment3
//
//  Created by Jad Wahab on 9/30/14.
//  Copyright (c) 2014 Jad Wahab. All rights reserved.
//



//Single linked lists

#include <iostream>
#include <string>
#include "Link.h"
#include "List.h"
#include "LList.h"
#include "SLList.h"
#include "Student.h"
#include "StudentComparison.h"
using namespace std;



int main()
{

    LList<string> list;  // make a list of strings
	int choice;
	string data;
    
    SLList<Student, StudentComparison> slist;
    
    
	while(1)
	{
		cout<<"\nEnter 1 to append\n";
		cout<<"Enter 2 to insert after fence\n";
		cout<<"Enter 3 to print the list\n";
		cout<<"Enter 4 to delete the node after fence\n";
		cout<<"Enter 5 to set a new fence position\n";
		cout<<"Enter 0 to quit\n";
		cin>>choice;
		if (choice==0)
		{
			list.clear();
			break;
		}
		if (choice==1) {
			cout<<"Enter element to append: ";
			cin>>data;
			if (list.append(data))
				cout<<"Element " <<data<<" appended successfully\n";
			else
				cout<<"Could not append\n";
		}
		if (choice==2) {
			cout<<"Enter element to insert after fence: ";
			cin>>data;
			if (list.insert(data))
				cout<<"Element " <<data<<" inserted successfully after fence\n";
			else
				cout<<"Could not insert\n";
		}
		
		if (choice==3)
			list.print();
		if (choice==4) {
			if (list.remove(data))
				cout<<"element "<<data<<" removed successfully\n";
			else
				cout<<"Error during deletion\n";
		}
		if (choice==5)
		{
			int pos;
			cout<<"Enter desired new position of fence: ";
			cin>>pos;
			if (list.setPos(pos))
				cout<<"Fence positioned successfully after item "<<pos<<endl;
			else
				cout<<"Wrong position given, old kept\n";
		}
	}
    
    return 0;
}

