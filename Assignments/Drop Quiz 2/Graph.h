//
//  Graph.h
//  Asst6
//
//  Created by Jad Wahab on 11/4/14.
//  Copyright (c) 2014 Jad Wahab. All rights reserved.
//

#pragma once

// Graph abstract class
class Graph
{
public:
    // Return the number of vertices
    virtual int n() =0;
    // Return the current number of edges
    virtual int e() =0;
    // Return the index of the first neigbor of given vertex
    virtual int first(int) =0;
    // Return the index of the next neigbor of given vertex
    virtual int next(int, int) =0;
    // Store an edge defined by two vertices and weight
    virtual void setEdge(int, int, int) =0;
    // Delete edge defined by two vertices
    virtual void delEdge(int, int) =0;
    // Return weight of edge connecting two vertices
    // Return 0 if no such edge exists
    virtual int weight(int, int) =0;
    // Get mark value for a vertex
    virtual int getMark(int) =0;
    //  Set mark value for a vertex
    virtual void setMark(int, int) =0;
};
