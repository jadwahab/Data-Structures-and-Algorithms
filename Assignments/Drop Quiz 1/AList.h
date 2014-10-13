//
//  aList.h
//  Drop Quiz1
//
//  Created by Jad Wahab on 10/1/14.
//  Copyright (c) 2014 Jad Wahab. All rights reserved.
//

#ifndef Drop_Quiz1_aList_h
#define Drop_Quiz1_aList_h

#include "List.h"
using namespace std;

template <class Elem> // Array-based list implementation
class AList : public List<Elem> {
private:
    int maxSize;        // Maximum size of list
    int listSize;       // Actual number of elements in list
    int fence;          // Position of fence
    Elem* listArray;    // Array holding list elements
public:
    AList(int size=10) { // Constructor
        maxSize = size;
        listSize = fence = 0;
        listArray = new Elem[maxSize];
    }
    ~AList() { delete [] listArray; } // Destructor
    void clear() {
        delete [] listArray;
        listSize = fence = 0;
        listArray = new Elem[maxSize];
    }
    bool insert(const Elem&);
    bool append(const Elem&);
    bool remove(Elem&);
    void setStart() { fence = 0; }
    void setEnd()   { fence = listSize; }
    void prev()     { if (fence != 0) fence--; }
    void next()     { if (fence < listSize) fence++; }
    int leftLength() const  { return fence; }
    int rightLength() const { return listSize - fence; }
    bool setPos(int pos) {
        if ((pos >= 0) && (pos <= listSize)) fence = pos;
        return (pos >= 0) && (pos <= listSize);
    }
    bool getValue(Elem& it) const {
        if (rightLength() == 0) return false;
        else { it = listArray[fence]; return true; }
    }
    void print() const {
        int temp = 0;
        cout << "< ";
        while (temp < fence) cout << listArray[temp++] << " ";
        cout << "| ";
        while (temp<listSize) cout << listArray[temp++] << " ";
        cout << ">\n";
    }
};

template <class Elem> // Insert at front of right partition
bool AList<Elem>::insert(const Elem& item) {
    if (listSize == maxSize) return false; // List is full
    for(int i=listSize; i>fence; i--)      // Shift Elems up
        listArray[i] = listArray[i-1];       //   to make room
    listArray[fence] = item;
    listSize++;                       // Increment list size
    return true;
}

template <class Elem> // Append Elem to end of the list
bool AList<Elem>::append(const Elem& item) {
    if (listSize == maxSize) return false;
    listArray[listSize++] = item;
    return true;
}

// Remove and return first Elem in right partition
template <class Elem> bool AList<Elem>::remove(Elem& it) {
    if (rightLength() == 0) return false; // Nothing in right
    it = listArray[fence];                // Copy removed Elem
    for(int i=fence; i<listSize-1; i++)   // Shift them down
        listArray[i] = listArray[i+1];
    listSize--;                           // Decrement size
    return true;
}

#endif
