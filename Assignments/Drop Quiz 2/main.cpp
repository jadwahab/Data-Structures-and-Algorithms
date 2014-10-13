//
//  main.cpp
//  Drop Quiz 2
//
//  Created by Jad Wahab on 11/19/14.
//  Copyright (c) 2014 Jad Wahab. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Graphm.h"
#include <iomanip>
using namespace std;

ifstream inData;

int main()
{
    int vertices, v1, v2, w;
    
    inData.open("file.txt");
    
    if (!inData)
    {
        cout<<"The file does not exist!\n";
        return 1;
    }
    
    
    
    inData>>vertices;
    
    Graphm *G = new Graphm(vertices);
    
    while(!inData.eof())
    {
        inData>>v1>>v2>>w;
        G->setEdge(v1,v2,w);
        G->setEdge(v2,v1,w);
    }
        
    
    
    inData.close();
    
    cout<<"Vertices: " <<G->n() <<endl;     //or put vertices instead of G->n()
    cout<<"Adjacency Matrix:\n";
    
    for(int i=0; i<G->n(); i++)
    {
        for(int j=0;j<G->n();j++)
            cout<< setw(3)<<G->weight(i, j);

        cout<<endl;
    }
    
    
    return 0;
}



