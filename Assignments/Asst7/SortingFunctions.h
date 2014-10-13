//
//  SortingFunctions.h
//  Asst7
//
//  Created by Jad Wahab on 11/17/14.
//  Copyright (c) 2014 Jad Wahab. All rights reserved.
//

#pragma once
#include "Comparators.h"

template <class Elem>
void swap(Elem A[], int i, int j)
{
    Elem temp;
    temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}


//////////////////// BUBBLE SORT: ////////////////////

template <class Elem, class Comp>
void bubsort(Elem A[], int n)
{
    for (int i=0; i<n-1; i++)
        for (int j=n-1; j>i; j--)
            if (Comp::lt(A[j], A[j-1]))
                swap(A, j, j-1);
}



//////////////////// INSERTION SORT: ////////////////////

template <class Elem, class Comp>
void inssort(Elem A[], int n)
{
    //starting from second element (1)
    for (int i=1; i<n; i++)
        //Compare adjacent elements starting from i and going
        //toward the top of the list (lower indices)
        //break if A[j] > A[j-1]: adjacent elements in proper order
        
        for (int j=i; ( (j>0)&&(Comp::lt(A[j], A[j-1])) ); j--)
            swap(A, j, j-1);

}



//////////////////// SELECTION SORT: ////////////////////

template <class Elem, class Comp>
void selsort(Elem A[], int n)
{
    // Go through all the elements
    for (int i=0; i<n-1; i++)
    {
        int lowindex = i; // Remember its index
        
        // Search through the remaining elements
        for (int j=n-1; j>i; j--)
            if (Comp::lt(A[j], A[lowindex]))
                lowindex = j; // Save index of smallest
        
        swap(A, i, lowindex); // Put it in place
    }
}



//////////////////// MERGE SORT: ////////////////////

template <class Elem, class Comp>
void mergesort(Elem A[], Elem temp[], int left, int right)
{
    int mid = (left+right)/2;
    if (left == right) return; // We have one element
    // Recursive calls on the two halves
    mergesort<Elem,Comp>(A, temp, left, mid);
    mergesort<Elem,Comp>(A, temp, mid+1, right);
    
    for (int i=left; i<=right; i++) // Copy to a temporary
        temp[i] = A[i];
    // below, we sort the two merged sublists
    int i1 = left; int i2 = mid + 1;
    for (int curr=left; curr<=right; curr++)
    {
        if (i1 == mid+1)      // Left exhausted
            A[curr] = temp[i2++];
        else if (i2 > right)  // Right exhausted
            A[curr] = temp[i1++];
        else if (Comp::lt(temp[i1], temp[i2]))
            A[curr] = temp[i1++];
        else A[curr] = temp[i2++];
    }
}



//////////////////// QUICK SORT: ////////////////////

template <class Elem, class Comp>
int partition(Elem A[], int l, int r, Elem& pivot)
{
    do
    { // Move the bounds inward until they meet
        while (Comp::lt(A[++l], pivot)); // Move l right
        while ((r != 0) &&
               Comp::gt(A[--r], pivot)); // Move r left
        
        swap(A, l, r); // Swap out-of-place values
    } while (l < r); // Stop when they cross
    
    swap(A, l, r);   // Reverse last swap
    
    return l;        // Return first pos on right
}


template <class Elem>
int findpivot(Elem A[], int i, int j)
{ return (i+j)/2; }


template <class Elem, class Comp>
void quicksort(Elem A[], int i, int j)
{
    if (j <= i) return; // zero or one elem
    
    // Find pivot
    int pivotindex = findpivot(A, i, j);
    swap(A, pivotindex, j);  // Save pivot at end
    
    // Make two partitions; k will be first position on right side
    int k = partition<Elem,Comp>(A, i-1, j, A[j]);
    // Put pivot in proper place
    swap(A, k, j);
    
    // Repeat above process for both partitions, excluding pivot
    quicksort<Elem,Comp>(A, i, k-1);
    quicksort<Elem,Comp>(A, k+1, j);
}






