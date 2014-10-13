//
//  Comparators.h
//  Asst7
//
//  Created by Jad Wahab on 11/17/14.
//  Copyright (c) 2014 Jad Wahab. All rights reserved.
//

#pragma once

class cppCompare
{
public:
    template<class Elem>
    static bool eq(Elem i1, Elem i2)
    {
        return ( i1 == i2 );
    }
    
    template<class Elem>
    static bool lt(Elem i1, Elem i2)
    {
        return ( i1 < i2 );
    }
    
    template<class Elem>
    static bool gt(Elem i1, Elem i2)
    {
        return ( i1 > i2 );
    }
};
