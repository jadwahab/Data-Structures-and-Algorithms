//
//  main.cpp
//  Lab1(Part2)
//
//  Created by Jad Wahab on 9/15/14.
//  Copyright (c) 2014 Jad Wahab. All rights reserved.
//


#include <iostream>
#include <cmath>
#include "shape.h"
#include "point.h"
#include "circle.h"
#include "cylinder.h"

using namespace std;

//PART 2



int main()
{
    
    shape *ptr[100];
    double  x,
            y,
            r,
            h;
    int choice=1,
        total=0,
        points=0,
        circles=0,
        cylinders=0;
    
    while ( (choice!=0)&&(total <=100) )
    {
        cout<<"\n..........LAB 1 (Part2)..........\n"
            <<"Select object: \n(1) Point \n(2) Circle \n(3) Cylinder \n(0) Quit\n";
        cin >>choice;
        
        switch (choice)
        {
            case 1:
                cout<<"\n.....Point.....\n"
                    <<"Enter coordinates: ";
                cin >>x >>y;
                
                ptr[total] = new point(x,y);
                total++;
                points++;
                break;
                
            case 2:
                cout<<"\n.....Circle.....\n"
                    <<"Enter center coordinates: ";
                cin>>x >>y;
                cout<<"Enter radius: ";
                cin>>r;
                
                ptr[total] = new circle(x,y,r);
                total++;
                circles++;
                break;
                
            case 3:
                cout<<"\n.....Cylinder.....\n"
                    <<"Enter center coordinates: ";
                cin>>x >>y;
                cout<<"Enter radius: ";
                cin>>r;
                cout<<"Enter height: ";
                cin>>h;
                
                ptr[total] = new cylinder(x,y,r,h);
                total++;
                cylinders++;
                break;
                
            case 0:
                choice = 0;
                break;
                
            default:
                cout <<"\nInvalid input!!\nTRY AGAIN...\n";
                total--;
                break;
        
        }//end switch
    }//end while
    
    cout<<"\n~~~~~~~~~~QUITTING~~~~~~~~~~\n"
        <<"\nNumber of points: " <<points
        <<"\nNumber of circles: " <<circles
        <<"\nNumber of cylinders: " <<cylinders
        <<"\nNet total: " <<total <<endl <<endl;
    
    for (int i=0; i<total; i++)
    {
        cout<<"\nObject #" <<i+1 <<":\n";
        ptr[i]->print();
        //(*ptr[i]).print();            (OR^^)
        delete ptr[i];
    }

    
    return 0;
}

