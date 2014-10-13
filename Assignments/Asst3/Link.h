//
//  link.h
//  Assignment3
//
//  Created by Jad Wahab on 9/30/14.
//  Copyright (c) 2014 Jad Wahab. All rights reserved.
//

#pragma once

// Singly-linked list node
template <class Elem>
class Link
{
public:
	Elem element;      // Value for this node
	Link *next;        // Pointer to next node in list
	
	Link( const Elem& elemval , Link* nextval= NULL ) // 1st Constructor
    { element= elemval ;  next= nextval; }
	
	Link( Link* nextval= NULL ) // 2nd Constructor
	{ next= nextval; }
};