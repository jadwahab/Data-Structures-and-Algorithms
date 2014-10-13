//
//  Employee.h
//  Asst5
//
//  Created by Jad Wahab on 10/11/14.
//  Copyright (c) 2014 Jad Wahab. All rights reserved.
//

#pragma once
#include <string>

class Employee
{
    int ID;
    string name;
    int salary;
    
public:
    Employee (int idn=0, string nm="unknown", int sal=0)
    {
        ID = idn;
        name = nm;
        salary = sal;
    }
    
    void setValues(int idn, string nm, int sal)
    {
        ID = idn;
        name = nm;
        salary = sal;
    }
    
    friend ostream &operator<<(ostream &output, const Employee &e)
    {
        output<<"\nID number: " <<e.ID
              <<"\nName: " <<e.name
              <<"\nSalary: " <<e.salary
              <<endl;
        return output;
    }
    
    friend istream &operator>>(istream &input, Employee &e)
    {
        input>>e.ID >>e.name >>e.salary;
        return input;
    }
    
    int getSalary()
    {
        return salary;
    }
    
};