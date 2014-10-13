//
//  point.h
//  Lab1(Part2)
//
//  Created by Jad Wahab on 9/17/14.
//  Copyright (c) 2014 Jad Wahab. All rights reserved.
//

#ifndef Lab1_Part2__point_h
#define Lab1_Part2__point_h

using namespace std;

class point: public shape
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
    
    double originDistance()
    {
        return sqrt( pow(X, 2) + pow(Y, 2) );
    }
    
    void print()
    {
        cout<<"The coordinates are: (" <<X <<", " <<Y <<").\n"
        <<"The distance between the point and the origin is: " <<originDistance() <<endl;
    }
    
};


#endif
