//
//  main.cpp
//  Asst5
//
//  Created by Jad Wahab on 10/11/14.
//  Copyright (c) 2014 Jad Wahab. All rights reserved.
//

#include <iostream>
#include "binnode.h"
#include "bs2.h"
#include "dictionary.h"
#include "Employee.h"
#include "Comparators.h"
#include <fstream>
using namespace std;



int main()
{
    BST <int, Employee, EmployeeIntCompare, EmployeeCompare> tree;
    int choice, sal;
    Employee e;
    
    ifstream inData;
    inData.open("dataFile.txt");
    
    inData>>e;
    
    while (inData)
    {
        tree.insert(e);
        inData>>e;
    }
    
    inData.close();
    
    
    
    while (1)
    {
        cout<<"\n1) Insert new employee\n";
		cout<<"2) Search by salary\n";
		cout<<"3) Delete employee with specific salary\n";
		cout<<"4) Print in inorder\n";
        cout<<"5) Print in pre-order\n";
        cout<<"6) Print in post-order\n";
		cout<<"0) Quit\n";
		cin>>choice;
        
        if (choice==0)
        {
            tree.print();
            break;
        }
        
        if (choice==1)
        {
            cout<<"Enter new employee: ";
            cin>>e;
            tree.insert(e);
        }
        
        if (choice==2)
        {
            cout<<"Enter salary to search: ";
            cin>>sal;
            if (tree.find(sal, e))
                cout<<"Result: " <<e <<endl;
            else
                cout<<"No results found\n";
        }
        
        if (choice==3)
        {
            cout<<"Enter salary: ";
            cin>>sal;
            if (tree.remove(sal, e))
                cout<<"Deleted: " <<e <<endl;
            else
                cout<<"No results found\n";
        }
        
        if (choice==4)
        {
            cout<<"Printing elements...\n\n";
            cout<<"\n_____INORDER_____\n";
            tree.inorder();

        }
        
        if (choice==5)
        {
            cout<<"Printing elements...\n\n";
            cout<<"\n_____PREORDER_____\n";
            tree.preorder();

        }
        
        if (choice==6)
        {
            cout<<"Printing elements...\n\n";
            cout<<"\n_____POSTORDER_____\n";
            tree.postorder();
        }
        
        
    }//end while
    
    ofstream outData;
    
    
    
    return 0;
}