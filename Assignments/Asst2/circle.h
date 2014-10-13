//
//  circle.h
//  Lab1(Part2)
//
//  Created by Jad Wahab on 9/17/14.
//  Copyright (c) 2014 Jad Wahab. All rights reserved.
//

//#pragma once


#ifndef Lab1_Part2__circle_h
#define Lab1_Part2__circle_h

using namespace std;

const double pi = 3.1416;


class circle: public point
{
protected:
    
    double R;
    
public:
    
    circle (double x, double y, double r):point(x,y)
    {
        R=r;
    }
    
    double circumference()
    {
        return 2*pi*R;
    }
    
    double area()
    {
        return pi*pow(R,2);
    }
    
    void print()
    {
        point::print();
        cout<<"Radius: " <<R
            <<"\nCircumference: " <<circumference()
            <<"\nArea: " <<area() <<endl;
    }
    
};


#endif
