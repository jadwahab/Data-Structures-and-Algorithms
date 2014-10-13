//
//  main.cpp
//  Lab 1
//
//  Created by Jad Wahab on 9/15/14.
//  Copyright (c) 2014 Jad Wahab. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;




const double pi = 3.14;


//PART 1

class point
{
protected:
    
    double X;
    double Y;
    
public:
    
    point(double x=0, double y=0)
    {
        X=x;
        Y=y;
    }
    
    double distance (point pt)
    {
        return sqrt( pow(X - pt.X, 2) + pow(Y - pt.Y, 2) );
    }
    
    double originDistance ()
    {
        return sqrt( pow(X, 2) + pow(Y, 2) );
    }
    
    void print ()
    {
        cout<<"The coordinates are: (" <<X <<", " <<Y <<").\n"
        <<"The distance between the point and the origin is: " <<originDistance() <<endl;
    }
    
};

//...........................................

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

//...........................................

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



int main(int argc, const char * argv[])
{
    
    
    
    
    return 0;
}

