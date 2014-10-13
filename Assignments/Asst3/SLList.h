//
//  SLList.h
//  Assignment3
//
//  Created by Jad Wahab on 10/1/14.
//  Copyright (c) 2014 Jad Wahab. All rights reserved.
//

#pragma once

#include <iostream>
#include "Link.h"
#include "List.h"
#include "StudentComparison.h"
using namespace std;


template <class Elem, class compare>
class SLList: public LList<Elem>
{
public:
    SLList() : LList<Elem>() {}
    ~SLList()    {LList<Elem>::removeall();}
    
    using LList<Elem>::clear;
    using LList<Elem>::setStart;;
    using LList<Elem>::getValue;
    using LList<Elem>::next;
    
    bool insert( const Elem& item)
    {
        Elem curr;
        for (setStart();getValue(curr); next())
            if(!compare::less(curr,item))
				break;
            return LList<Elem>::insert(item);
    }
	
    bool append( const Elem& )
    {
        cout<<"Invalid operation...\n";
        return false;
    }
};