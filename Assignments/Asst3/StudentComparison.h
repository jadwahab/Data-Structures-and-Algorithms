//
//  StudentComparison.h
//  Assignment3
//
//  Created by Jad Wahab on 10/1/14.
//  Copyright (c) 2014 Jad Wahab. All rights reserved.
//

#pragma once

#include "Student.h"

class StudentComparison
{
public:
    
    static bool eq(Student s1, Student s2)
    {
        return ( s1.getID()==s2.getID() );
    }
    
    static bool less(Student s1, Student s2)
    {
        return ( s1.getID()<s2.getID() );
    }
    
    static bool greater(Student s1, Student s2)
    {
        return ( s1.getID()>s2.getID() );
    }
};