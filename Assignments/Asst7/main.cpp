//
//  main.cpp
//  Asst7
//
//  Created by Jad Wahab on 11/17/14.
//  Copyright (c) 2014 Jad Wahab. All rights reserved.
//

#include <iostream>
#include "SortingFunctions.h"
#include <iomanip>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

//FUNCTIONS:

template <class Elem, class Comp>
void printArray(Elem A[], int n);

template <class Elem, class Comp>
void testarray(Elem A[], int n);

void stringPrintArray(string A[], int n);

template <class Elem>
void unsort(Elem Array[], Elem ArrayTemp[], int size);


////////////////////////////// MAIN //////////////////////////////

int main()
{
    
    ifstream inData;
    
    string word;
    
    inData.open("words.txt");       //large file with text from econ text book (many words)
    
    if (!inData) {
        cout<<"File does not exist\n";
    }
 
    srand(time(NULL));
    int size, choice;
    double start, end;
    
    cout<<"Enter the number of elements in the array: ";
    cin>>size;

    int *Array = new int[size];
    int *ArrayTemp = new int[size];
    int *temp = new int[size];      //for merge sort
    
    for (int i=0; i<size; i++)
        Array[i] = rand()%100;
    
    string *stringArray = new string[size];
    string *stringArrayTemp = new string[size];
    string *stringtemp = new string[size];      //for merge sort
    
    for (int i=0; i<size; i++)
    {
        inData>>word;
        stringArray[i] = word;
    }
    
    
    if (size<1000)
    {
        
        while (1)
        {
            unsort(Array, ArrayTemp, size);                     //to unsort elements after every iteration of the while
            unsort(stringArray, stringArrayTemp, size);         //loop so that we don't sort and already sorted array
                
            cout<<"\n----------------------------------------\n"
                <<"Choose from the following sort algorithms:\n"
                <<"(1) Bubble Sort\n"
                <<"(2) Insertion Sort\n"
                <<"(3) Selecstion Sort\n"
                <<"(4) Merge Sort\n"
                <<"(5) Quick Sort\n"
                <<"(6) Print Array\n"
                <<"(0) QUIT\n";
            
            cin>>choice;
            
            if (choice == 1)
            {
                cout<<"BUBBLE SORT: ";
                bubsort<int, cppCompare>(ArrayTemp, size);
                printArray<int, cppCompare>(ArrayTemp, size);
                
                bubsort<string, cppCompare>(stringArrayTemp, size);
                stringPrintArray(stringArrayTemp, size);
            }
            
            else if (choice == 2)
            {
                cout<<"INSERTION SORT: ";
                inssort<int, cppCompare>(ArrayTemp, size);
                printArray<int, cppCompare>(ArrayTemp, size);
                
                inssort<string, cppCompare>(stringArrayTemp, size);
                stringPrintArray(stringArrayTemp, size);
            }
            
            else if (choice == 3)
            {
                cout<<"SELECTION SORT: ";
                selsort<int, cppCompare>(ArrayTemp, size);
                printArray<int, cppCompare>(ArrayTemp, size);
                
                selsort<string, cppCompare>(stringArrayTemp, size);
                stringPrintArray(stringArrayTemp, size);
            }
            
            else if (choice == 4)
            {
                cout<<"MERGE SORT: ";
                mergesort<int, cppCompare>(ArrayTemp, temp, 0, size-1);
                printArray<int, cppCompare>(ArrayTemp, size);
                
                mergesort<string, cppCompare>(stringArrayTemp, stringtemp, 0, size-1);
                stringPrintArray(stringArrayTemp, size);
            }
            
            else if (choice == 5)
            {
                cout<<"QUICK SORT: ";
                quicksort<int, cppCompare>(ArrayTemp, 0, size-1);
                printArray<int, cppCompare>(ArrayTemp, size);
                
                quicksort<string, cppCompare>(stringArrayTemp, 0, size-1);
                stringPrintArray(stringArrayTemp, size);
            }
            
            else if (choice == 6)
            {
                cout<<"(1) int Array\n"
                    <<"(2) string Array\n";
                cin>>choice;
                
                if (choice == 1)
                {
                    cout<<"PRINTING INITIAL ARRAY: ";
                    printArray<int, cppCompare>(ArrayTemp, size);
                }
                else
                {
                    cout<<"PRINTING INITIAL ARRAY: ";
                    stringPrintArray(stringArrayTemp, size);
                }
            }
            
            else
                break;
            
            cout<<endl;
        } //end while
    } //end if
    
    else
    {
        puts("Time taken for each algorithm:\n");
        
//BUBBLE SORT:
        puts("BUBBLE SORT: ");
        cout<<"int:\n";
        start = clock();
        bubsort<int, cppCompare>(ArrayTemp, size);
        end = clock();
        cout<<end-start <<endl;
        cout<<"string:\n";
        start = clock();
        bubsort<string, cppCompare>(stringArrayTemp, size);
        end = clock();
        cout<<end-start <<endl;
        
        unsort(Array, ArrayTemp, size);                     //to unsort elements after every iteration of the while
        unsort(stringArray, stringArrayTemp, size);         //loop so that we don't sort and already sorted array
        
//INSERTION SORT:
        puts("\nINSERTION SORT: ");
        cout<<"int:\n";
        start = clock();
        inssort<int, cppCompare>(ArrayTemp, size);
        end = clock();
        cout<<end-start <<endl;
        cout<<"string:\n";
        start = clock();
        inssort<string, cppCompare>(stringArrayTemp, size);
        end = clock();
        cout<<end-start <<endl;
        
        unsort(Array, ArrayTemp, size);                     //to unsort elements after every iteration of the while
        unsort(stringArray, stringArrayTemp, size);         //loop so that we don't sort and already sorted array
        
//SELECTION SORT:
        puts("\nSELECTION SORT: ");
        cout<<"int:\n";
        start = clock();
        selsort<int, cppCompare>(ArrayTemp, size);
        end = clock();
        cout<<end-start <<endl;
        cout<<"string:\n";
        start = clock();
        selsort<string, cppCompare>(stringArrayTemp, size);
        end = clock();
        cout<<end-start <<endl;
        
        unsort(Array, ArrayTemp, size);                     //to unsort elements after every iteration of the while
        unsort(stringArray, stringArrayTemp, size);         //loop so that we don't sort and already sorted array
        
//MERGE SORT:
        puts("\nMERGE SORT: ");
        cout<<"int:\n";
        start = clock();
        mergesort<int, cppCompare>(ArrayTemp, temp, 0, size-1);
        end = clock();
        cout<<end-start <<endl;
        cout<<"string:\n";
        start = clock();
        mergesort<string, cppCompare>(stringArrayTemp, stringtemp, 0, size-1);
        end = clock();
        cout<<end-start <<endl;
        
        unsort(Array, ArrayTemp, size);                     //to unsort elements after every iteration of the while
        unsort(stringArray, stringArrayTemp, size);         //loop so that we don't sort and already sorted array
        
//QUICK SORT:
        puts("\nQUICK SORT: ");
        cout<<"int:\n";
        start = clock();
        quicksort<int, cppCompare>(ArrayTemp, 0, size-1);
        end = clock();
        cout<<end-start <<endl;
        cout<<"string:\n";
        start = clock();
        quicksort<string, cppCompare>(stringArrayTemp, 0, size-1);
        end = clock();
        cout<<end-start <<endl;
        
    }
    
    
    delete [] Array;
    cout<<endl;
    return 0;
}




template <class Elem, class Comp>
void printArray(Elem A[], int n)
{
        cout<<endl;
        for (int i=0; i<n; i++)
        {
            cout<<setw(6) <<A[i];
            if ((i+1)%8 == 0)
                cout<<endl;
        }
}

void stringPrintArray(string A[], int n)
{
    cout<<endl;
    for (int i=0; i<n; i++)
    {
        cout<<A[i] <<"   ";
        if ((i+1)%8 == 0)
            cout<<endl;
    }
}


template <class Elem, class Comp>
void testarray(Elem A[], int n)
{
    for (int i=0; i<n; i++)
        A[i]=i;
}


template <class Elem>
void unsort(Elem Array[], Elem ArrayTemp[], int size)
{
    for (int i=0; i<size; i++)
        ArrayTemp[i]= Array[i];
}
