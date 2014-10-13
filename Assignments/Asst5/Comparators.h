//
//  Comparators.h
//  Asst5
//
//  Created by Jad Wahab on 10/11/14.
//  Copyright (c) 2014 Jad Wahab. All rights reserved.
//

#pragma once
#include "Employee.h"

class EmployeeCompare
{
public:
    static bool eq(Employee e1, Employee e2)
    {
        return ( e1.getSalary()==e2.getSalary() );
    }
    
    static bool lt(Employee e1, Employee e2)
    {
        return ( e1.getSalary()<e2.getSalary() );
    }
    
    static bool gt(Employee e1, Employee e2)
    {
        return ( e1.getSalary()>e2.getSalary() );
    }
};









class EmployeeIntCompare
{
public:
    static bool eq(int s1, Employee e2)
    {
        return ( s1==e2.getSalary() );
    }
    
    static bool lt(int s1, Employee e2)
    {
        return ( s1<e2.getSalary() );
    }
    
    static bool gt(int s1, Employee e2)
    {
        return ( s1>e2.getSalary() );
    }
};