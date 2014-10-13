//
//  Queue.h
//  Asst4
//
//  Created by Jad Wahab on 10/6/14.
//  Copyright (c) 2014 Jad Wahab. All rights reserved.
//

#pragma once
#include <iostream>
using namespace std;

template <class Elem>
class AQueue
{
    int size;
    int front;
    int rear;
    int count;
    Elem *arrayList;
    
public:
    AQueue(int s=10);
    ~AQueue();
    bool empty();
    bool full();
    bool enqueue(const Elem&);
    bool dequeue(Elem&);
    void print();
    
};





////////////////////////////////////////////////////////////////////////////////////////////////////////////





template <class Elem>
AQueue<Elem>::AQueue(int s)
{
    size=s;
    front=0;
    rear=0;
    count=0;
    arrayList = new Elem[s];
}

template <class Elem>
AQueue<Elem>::~AQueue()
{
    delete [] arrayList;
}

template <class Elem>
bool AQueue<Elem>::empty()
{
    if (count == 0)
        return true;
    return false;
}

template <class Elem>
bool AQueue<Elem>::full()
{
    if (count == size)
        return true;
    return false;
}

template <class Elem>
bool AQueue<Elem>::enqueue(const Elem& item)
{
    if (full())
        return false;
    
    rear = (rear+1)%size;
    arrayList[rear] = item;
    count++;
    return true;
}

template <class Elem>
bool AQueue<Elem>::dequeue(Elem& item)
{
    if (empty())
        return false;
        
    item = arrayList[front];
    front = (front+1)%size;
    count--;
    return true;
}

template <class Elem>
void AQueue<Elem>::print()
{
    if (empty())
        cout<<"The list is empty!\n";
    else
        cout<<"Printing stacked array elements:\n";
        for (int i=front; i==rear; i=(i+1)%size)
        {
            cout<<arrayList[i]<<endl;
        }
}