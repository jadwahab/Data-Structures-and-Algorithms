//
//  student.h
//  Assignment3
//
//  Created by Jad Wahab on 10/1/14.
//  Copyright (c) 2014 Jad Wahab. All rights reserved.
//

#pragma once

class Student
{
    int ID;
    double fees;
    
public:
    
    int getID() {return ID;}
    
    friend ostream &operator<<(ostream &output, const Student &s)
    {
        output<<"Sudent ID: " <<s.ID <<"\nStudent Fees: " <<s.fees <<endl;
        return output;
    }
    
    friend istream &operator>>(istream &input, Student &s)
    {
        cout<<"Enter the student's ID: ";
        input>>s.ID;
        cout<<"Enter the sudent's fees: ";
        input>>s.fees;
        return input;
    }

};
