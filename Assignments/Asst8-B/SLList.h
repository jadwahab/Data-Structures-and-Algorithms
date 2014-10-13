//
//  SLList.h
//  asst8-B
//
//  Created by Jad Wahab on 12/3/14.
//  Copyright (c) 2014 Jad Wahab. All rights reserved.
//

#pragma once
#include "LList.h"

template <class Elem, class Compare>
class SLList: public LList<Elem>   // Solution for public inheritance: insert and append overridden, others inherited
{
public:
    bool  insert( const Elem& item );
    bool  append( const Elem& item );
};

template <class Elem, class Compare> // Insert at front of right partition
bool SLList<Elem, Compare>::insert( const Elem& item )
{
    Elem curr;
    for (LList<Elem>::setStart(); LList<Elem>::getValue(curr); LList<Elem>::next())
        if (Compare::lt(item , curr))       //MISTAKE IN GIVEN CODES
            break;                           //make use of LList insert after right positioning of fence
    return LList<Elem>::insert(item);        //sorted up down by IDs, write gt instead of lt if you need the contrary
}

template <class Elem, class Compare> // Append Elem to end of the list
bool SLList<Elem, Compare>::append( const Elem& item )
{
    cout<<"Can not append in a sorted list\n";  //append returns false always in a sorted list
    return false;
}