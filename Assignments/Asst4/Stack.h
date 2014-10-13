//
//  Stack.h
//  Asst4
//
//  Created by Jad Wahab on 10/5/14.
//  Copyright (c) 2014 Jad Wahab. All rights reserved.
//

#pragma once
#include <iostream>
using namespace std;


template <class T>
class Stack
{
    T *ptrData;  //pointer
    int size;    //total size of array stack
    int top;     //pointer value
    
public:
	Stack(int s=10);      //constructor to initialize.
    ~Stack();
	void push(T x);
	T pop();
	bool empty();   //returns true if empty, can not pop
	bool full();    //returns true if full, no more place to push
	void print();   //print the stack beginning from top
};





////////////////////////////////////////////////////////////////////////////////////////////////////////////





template <class T>
Stack<T>::Stack(int s)
{
    size = s;
    top=0;
    ptrData = new T[s];
}

template <class T>
Stack<T>::~Stack()
{
    delete [] ptrData;
}

template <class T>
void Stack<T>::push(T x)
{
    ptrData[top] = x;
    top++;
}

template <class T>
T  Stack<T>::pop()
{
    return ptrData[--top];
}

template <class T>
bool Stack<T>::empty()
{
    if (top == 0)
        return true;
    return false;
}

template <class T>
bool Stack<T>::full()
{
    if (size == top)
        return true;
    return false;
}

template <class T>
void Stack<T>::print()
{
    if (empty())
        cout<<"The list is empty!\n";
    else
        cout<<"Printing stacked array elements:\n";
        for (int i=0; i<top; i++)
        {
            cout<<ptrData[i]<<endl;
        }
}

