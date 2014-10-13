//
//  main.cpp
//  Asst4
//
//  Created by Jad Wahab on 10/5/14.
//  Copyright (c) 2014 Jad Wahab. All rights reserved.
//

#include <iostream>
#include "Stack.h"
#include "AQueue.h"
#include "LQueue.h"
using namespace std;

int main()
{
    Stack<int> intStk;
    
    int choice,
        x;
    
    while (1)
    {
        cout<<"\nEnter 1 to push\n";
		cout<<"Enter 2 to pop\n";
		cout<<"Enter 3 to check if empty\n";
		cout<<"Enter 4 to check if full\n";
        cout<<"Enter 5 to print stack\n";
		cout<<"Enter 0 to quit\n";
		cin>>choice;
    
    switch (choice)
    {
        case 1:
            cout<<"Enter element to push: ";
            cin>>x;
            if (intStk.full())
                cout<<"The list is full!\n";
            else
                intStk.push(x);
            break;
            
        case 2:
            if (intStk.empty())
                cout<<"The list is empty!\n";
            else
                cout<<intStk.pop();
            break;
            
        case 3:
            if (intStk.empty())
                cout<<"Empty!\n";
            else
                cout<<"Not Empty!\n";
            break;
            
        case 4:
            if (intStk.full())
                cout<<"Full!\n";
            else
                cout<<"Not full!\n";
            break;
            
        case 5:
            intStk.print();
            break;
            
        case 0:default:
            break;
            break;
            
    }       //end case
        
    }       //end while
    
    return 0;
}

