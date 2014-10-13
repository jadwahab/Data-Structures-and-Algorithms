//
//  Graphm.h
//  Asst6
//
//  Created by Jad Wahab on 11/4/14.
//  Copyright (c) 2014 Jad Wahab. All rights reserved.
//

#pragma once

// Used by the mark array
#define UNVISITED 0
#define VISITED 1

#include "graph.h"


class Graphm : public Graph  // Implement adjacency matrix
{
private:
    int numVertex, numEdge; // Store number of vertices, edges
    int **matrix;           // Pointer to adjacency matrix
    int *mark;              // Pointer to mark array
public:
    Graphm(int numVert) {   // Make graph w/ numVert vertices
        int i;
        numVertex = numVert;
        numEdge = 0;
        mark = new int[numVert]; // Initialize mark array
        for (i=0; i<numVertex; i++)
            mark[i] = UNVISITED;
        matrix = (int**) new int*[numVertex]; // Make matrix
        for (i=0; i<numVertex; i++)
            matrix[i] = new int[numVertex];
        for (i=0; i< numVertex; i++) // Edges start w/ 0 weight
            for (int j=0; j<numVertex; j++) matrix[i][j] = 0;
    }
    
    ~Graphm() {       // Destructor
        delete [] mark; // Return dynamically allocated memory
        for (int i=0; i<numVertex; i++)
            delete [] matrix[i];
        delete [] matrix;
    }
    
    int n() { return numVertex; } // Number of vertices
    int e() { return numEdge; }   // Number of edges
    
    int first(int v) {            // Return v's first neighbor
        int i;
        for (i=0; i<numVertex; i++)
            if (matrix[v][i] != 0) return i;
        return i;       // Return n if none
    }
    
    int next(int v1, int v2) { // Get v1's neighbor after v2
        int i;
        for(i=v2+1; i<numVertex; i++)
            if (matrix[v1][i] != 0) return i;
        return i;
    }
    
    // Set edge (v1, v2) to wgt
    void setEdge(int v1, int v2, int wgt) {
//        Assert(wgt>0, "Illegal weight value");
        if (matrix[v1][v2] == 0) numEdge++;
        matrix[v1][v2] = wgt;
    }
    
    void delEdge(int v1, int v2) { // Delete edge (v1, v2)
        if (matrix[v1][v2] != 0) numEdge--;
        matrix[v1][v2] = 0;
    }
    
    int weight(int v1, int v2) { return matrix[v1][v2]; }
    int getMark(int v) { return mark[v]; }
    void setMark(int v, int val) { mark[v] = val; }
    
    
};
