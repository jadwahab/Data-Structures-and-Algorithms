//
//  main.cpp
//  Drop Quiz1
//
//  Created by Jad Wahab on 10/1/14.
//  Copyright (c) 2014 Jad Wahab. All rights reserved.
//

#include <iostream>
#include <string>
#include "List.h"
#include "AList.h"
#include "Car.h"
using namespace std;



int main()
{
    
    int choice;
    Car c,x;
    AList<Car> baseList;
    

    while (true)
    {
        cout<<"0: Quit the menu and the program\n"
            <<"1: Add a new car(use cin) in the list\n"
            <<"2: Print the list\n"
            <<"3: Input a new car and check if it exists in the list\n";
        cin>>choice;
        
        if (choice==0)
            break;
        
        if (choice==1)
        {
            cout<<"Enter new car: ";
            cin>>c;
            
            if (baseList.append(c))
                cout<<"Success\n";
            else
                cout<<"Fail\n";
        }
        
        if (choice==2)
        {
            cout<<"Base list: ";
            baseList.print();
        }
        
        if (choice==3)
        {
            cout<<"Enter new car: ";
            cin>>c;
            
            for (baseList.setStart();baseList.getValue(x);baseList.next())
            {
                
                if (c==x)
                {
                    cout<<"city name found\n";
                }
            }
            
        }
        
    
    }
    
    return 0;
}

