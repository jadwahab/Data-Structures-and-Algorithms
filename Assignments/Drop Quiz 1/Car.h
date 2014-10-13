//
//  car.h
//  Drop Quiz1
//
//  Created by Jad Wahab on 10/1/14.
//  Copyright (c) 2014 Jad Wahab. All rights reserved.
//

#ifndef Drop_Quiz1_car_h
#define Drop_Quiz1_car_h

#include <string>
using namespace std;

class Car
{
    string model;
    int madeYear;
    
public:
    
    Car(string m = "unknown", int mY = 2014)
    {
        model = m;
        madeYear = mY;
    }
    
    bool operator==(const Car& c) const
    {
        return ( (model== c.model)&&(madeYear==c.madeYear) );
    }
    
    friend ostream &operator<<(ostream &output, const Car &c)
    {
        output<<"Model: " <<c.model <<"\nYear Made: " <<c.madeYear <<endl;
        return output;
    }
    
    friend istream &operator>>(istream &input, Car &c)
    {
        input>>c.model;
        input>>c.madeYear;
        return input;
    }
    
};

#endif
