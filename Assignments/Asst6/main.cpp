//
//  main.cpp
//  Asst6
//
//  Created by Jad Wahab on 11/4/14.
//  Copyright (c) 2014 Jad Wahab. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Graph.h"
#include "Graphm.h"
using namespace std;

ifstream inData;
#define INFINITY 99999// Big enough for simple tests

//FUNCTIONS:

Graph* ReadGraph ()
{
    int vertex1, vertex2, weight;
    int numVertex;
    if (!inData)
    {
        cout<<"Invalid input file\n";
        return NULL;
    }
    inData >> numVertex;
    Graphm *G = new Graphm(numVertex);

    while((inData.peek()!='\n')&&(inData.peek()!='\r')&&(!inData.eof()))
    {
        inData >>vertex1 >>vertex2 >>weight;
        G->setEdge(vertex1, vertex2, weight);
    }
    
    return G;
}


Graph* GetGraph()
{
    int vertex1, vertex2, weight;
    int numVertex;
    cout << "Enter the number of vertices: " << endl;
    cin >> numVertex;
    Graph *G = new Graphm(numVertex);
 
    
    while (1)
    {
        cout <<"Enter a negative number to quit:\n";
        cout << "Else enter the edges and the weight: ";
        cin >> vertex1;
        if (vertex1<0)
            break;
        cin>>vertex2 >>weight;
        G->setEdge(vertex1, vertex2, weight);
    }
    
    return G;
}


void GprintToConsole(Graph* G)
{
    for( int i=0; i<G->n(); i++)
    {
        cout << i << " " ;
        for(int j=0; j<G->n(); j++)
        {
            cout << G->weight(i,j) << " ";
        }
        cout << endl;
    }
}


void GprintToFile(Graph* G, ofstream& outData)
{
    for( int i=0; i<G->n(); i++){
        outData << i << " " ;
        for(int j=0; j<G->n(); j++) {
            outData << G->weight(i,j) << " ";
        }
        outData << endl;
    }
}


int minVertex(Graph* G, int* D)  // Find min cost vertex

{    int i, v;
    for (i=0; i<G->n(); i++)  // Set v to an unvisited vertex
        if (G->getMark(i) == UNVISITED) { v = i; break; }
    for (i++; i<G->n(); i++)  // Now find smallest D value
        if ((G->getMark(i) == UNVISITED) && (D[i] < D[v]))
            v = i;
    return v;
}


void Dijkstra(Graph* G, int* D, int s)
{
    int i, v, w;
    for (i=0; i<G->n(); i++) // Process the vertices
    {
        v = minVertex(G, D);
        if (D[v] == INFINITY) return; // Unreachable vertices
        G->setMark(v, VISITED);
        for (w=G->first(v); w<G->n(); w = G->next(v,w))
            if (D[w] > (D[v] + G->weight(v, w)))
                D[w] = D[v] + G->weight(v, w);
    }
}


int shortestDistance(Graph* G, int i, int j)
{
    int* A=new int[G->n()];
    Dijkstra(G, A, i);
    return A[j];
}


int maxVertex(Graph* G, int* D) { // Find max cost vertex
    int i, v;
    for (i=0; i<G->n(); i++)  // Set v to an unvisited vertex
        if (G->getMark(i) == UNVISITED) { v = i; break; }
    for (i++; i<G->n(); i++)
        if ((G->getMark(i) == UNVISITED) && (D[i] > D[v]))
            v = i;
    return v;
}


void oppositeDijkstra(Graph* G, int* D, int s)
{
    int i, v, w;
    for (int i=0; i<G->n(); i++) // Initialize
        D[i] = 0;
    D[0] = 0;
    for (i=0; i<G->n(); i++) {      // Process the vertices
        v = maxVertex(G, D);
        if (D[v] == 0) return; // Unreachable vertices
        G->setMark(v, VISITED);
        for (w=G->first(v); w<G->n(); w = G->next(v,w))
            if (D[w] < (D[v] + G->weight(v, w)))
                D[w] = D[v] + G->weight(v, w);
    }
}


int longestDistance(Graph* G, int i, int j)
{
    int* A;
    A=new int[G->n()];
    oppositeDijkstra(G, A, i);
    return A[j];
    
}





////////////////////////////////////////////// MAIN //////////////////////////////////////////////

int main(int argc, const char * argv[])
{

//    char* input_filename;
//    char* output_filename;
    
//    if (argc == 1)
//    {
//        Graph *G = GetGraph();
//        GprintToConsole(G);
//    }
    
//    else
//    {
//        inData.open(argv[2]);
//        G = ReadGraph();
//        GprintToConsole(G);
//    }
    
    Graph *G = GetGraph();
    GprintToConsole(G);
    cout <<endl;
    
    
//    int** M;
//    M = new int* [G->n()];
//    
//    for (int i=0; i<G->n(); i++)
//    {
//        M[i] = new int[G->n()];
//    }
//    
//    for (int i=0; i<G->n(); i++)     // Initialize
//        for (int j=0; j<G->n(); j++)
//            M[i][j] = INFINITY;
//
//    shortestDistance(G, M);
//    
//    for (int i=0; i<G->n(); i++)     // Print
//    {
//        for (int j=0; j<G->n(); j++)
//            cout<< M[i][j] <<" ";
//        cout<< endl;
//    }
//
//
//    D[0] = 0;
//    
//    Dijkstra(G, D, 0);
//    for(int k=0; k<G->n(); k++)
//        cout << D[k] << " ";

    for(int i=0; i<G->n(); i++)
    {
        for (int j=0; j<G->n(); j++)
            cout << "Min distance from " << i << " to " << j << " is: " << shortestDistance(G, i, j) << endl;
    }
    
    for(int i=0; i<G->n(); i++)
    {
        for (int j=0; j<G->n(); j++)
            cout << "Max distance from " << i << " to " << j << " is: " << longestDistance(G, i, j) << endl;
    }
    
    
    
    cout << endl;
    return 0;
}
