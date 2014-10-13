//
//  cylinder.h
//  Lab1(Part2)
//
//  Created by Jad Wahab on 9/17/14.
//  Copyright (c) 2014 Jad Wahab. All rights reserved.
//

#ifndef Lab1_Part2__cylinder_h
#define Lab1_Part2__cylinder_h

using namespace std;


class cylinder: public circle
{
    double H;
    
public:
    
    cylinder(double x, double y, double r, double h):circle(x,y,r)
    {
        H=h;
    }
    
    double surfaceArea()
    {
        return 2*pi*R*(R + H);
    }
    
    double volume()
    {
        return pi*R*R*H;
    }
    
    void print()
    {
        circle::print();
        cout<<"Height: " <<H
        <<"\nSurface Area: " <<surfaceArea()
        <<"\nVolume: " <<volume() <<endl;
    }
    
};


#endif
