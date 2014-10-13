//
//  LQueue.h
//  Asst4
//
//  Created by Jad Wahab on 10/6/14.
//  Copyright (c) 2014 Jad Wahab. All rights reserved.
//

#pragma once
#include "Link.h"

template <class Elem>
class LQueue
{
    Link<Elem>* front;
    Link<Elem>* rear;
    int size;
    
public:
    LQueue();
    ~LQueue();
    bool full();        //useless (linked list)
    bool empty();
    void enqueue(Elem);
    bool dequeue(Elem);
    void print();
    void clear();
};




////////////////////////////////////////////////////////////////////////////////////////////////////////////




template <class Elem>
LQueue<Elem>::LQueue()
{
    front = NULL;
    rear = NULL;
    size = 0;
}

template <class Elem>
LQueue<Elem>::~LQueue()
{
    clear();
}

template <class Elem>
bool LQueue<Elem>::full()
{
    return false;                       //useless (linked list)
}

template <class Elem>
bool LQueue<Elem>::empty()
{
    if ( (size == 0)||(rear == NULL) )
        return true;
    return false;
}

template <class Elem>
void LQueue<Elem>::enqueue(Elem item)
{
    if (empty())
        front = rear = new Link<Elem>(item, NULL);
    else
    {
        rear->next = new Link<Elem>(item, NULL);
        rear = rear->next;
    }
    size++;
}

template <class Elem>
bool LQueue<Elem>::dequeue(Elem item)
{
    if (empty())
        return false;

    item = front->element;
    Link<Elem>* ltemp = front;
    front = front->next;
    delete ltemp;
    
    if (front == NULL) rear = NULL;         //Dequeue last element
    
    size --;
    return true;
}