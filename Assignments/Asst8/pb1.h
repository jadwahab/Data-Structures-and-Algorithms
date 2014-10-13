//
//  pb1.h
//  Asst8
//
//  Created by Jad Wahab on 11/26/14.
//  Copyright (c) 2014 Jad Wahab. All rights reserved.
//

#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

//Array functions:

void init_zero(int A[], int n)
{
    for (int i=0; i<n; i++)
        A[i] = 0;
}


void print_array(int A[], int n)
{
    for (int i=0; i<n; i++)
    {
        cout<<setw(5) <<A[i];
        if ((i+1)%5 == 0)
            cout<<endl;
    }
    
}

void swap(int A[], int i, int j)
{
    int temp;
    temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}



//A:
//BUCKET HASHING:

void bucket_hashing(int A[], int Overflow[], int num)
{
    int index = (num%10)*5;
    int i=index;
    int j=0;
    
    while ( i<(index+5) && (A[i]!=0) )
        i++;
    
    if (A[i] == 0)
        A[i] = num;
    else
    {
        while (Overflow[j]!=0)
            j++;
        Overflow[j] = num;
    }
    
}

void search_bucket_hashing(int A[], int Overflow[], int num)
{
    int index = (num%10)*5;
    int i=index;
    
    if (A[i] == num)
        cout<<"Number found directly\n";
    else
    {
        while (i<(index+5) && A[i]!=num)
            i++;
        if (i<(index+5))
            cout<<"Number found indirectly through probe\n";
        else
        {
            int j=0;
            while ( (Overflow[j]!=0) && (Overflow[j]!=num) )
                j++;
            if (Overflow[j]==num)
                cout<<"Number found indirectly in overflow array\n";
            else
                cout<<"Number NOT found\n";
            
        }
    }
    
}



//B:
//LINEAR PROBING:

void linear_probing(int A[], int num)
{
    int index = (num%10)*5;
    
    while ( A[index]!=0 )
        index = (index+1)%50;

    A[index] = num;
}

void search_linear_probing(int A[], int num)
{
    int index = (num%10)*5;
    
    if (A[index]==num)
        cout<<"Number found directly\n";
    else
    {
        int i=(index+1)%50;
        
        while ( (i!=index) && (A[i]!=num) )
            i = (i+1)%50;
        
        if (A[i]==num)
            cout<<"Number found indirectly\n";
        else
            cout<<"Number NOT found\n";
    }
}


//C:
//PSEUDO-RANDOM:

//using a pseudo-random sequence:
void pseudo_random_sequence(int A[], int n)
{
    for (int i=0; i<n; i++)
        swap(A, rand()%49 + 1, rand()%49 + 1 );
}

void pseudo_random_sequence_probing(int A[], int SeqA[], int num)
{
    int index = (num%10)*5;
    int i=index;
    int count=1;    //1 not 0 since 0 is useless to compare to
    
    while ( A[i]!=0 && i<50 )      //i<50 not really needed but just in case array full
        i = (index + SeqA[count++])%50;
    
    A[i] = num;
}

void search_pseudo_random_sequence_probing(int A[], int SeqA[], int num)
{
    int index = (num%10)*5;
    
    if (A[index]==num)
        cout<<"Number found directly\n";
    else
    {
        int i, count=1;
        
        while ( (A[i]!=num) && (count<50) )
            i = (index + SeqA[count++])%50;
        
        if (A[i]==num)
            cout<<"Number found indirectly\n";
        else
            cout<<"Number NOT found\n";
    }
}

void pseudo_random_probing2(int A[], int num)
{
    int index = (num%10)*5;
    int count=0;
    
    while ( A[index]!=0 )
    {
        if (count%2 == 0)
            index = (index+2)%50;
        else
            index = (index+5)%50;
        count++;
    }
    A[index] = num;
}

void search_pseudo_random_probing2(int A[], int num)
{
    int index = (num%10)*5;
    int i = index;
    int count=0;
    
    if (A[index]==num)
        cout<<"Number found directly\n";
    else
    {
        do
        {
            if (count%2 == 0)
                i = (i+2)%50;
            else
                i = (i+5)%50;
            count++;
        } while ( (A[i]!=num) && ((i != index)||(count%2 != 0)) );  //while num not found and not cycled
        
        if (A[i]==num)
            cout<<"Number found indirectly\n";
        else
            cout<<"Number NOT found\n";
    }
}



//D:
//DOUBLE HASHING:

void double_hashing(int A[], int num)
{
    int index = (num%10)*5;
    int count=0;
    
    do
    {
        index = ( (count+1)*index + (count*(num-13))%27 )%50;
        count++;
    } while (A[index]!=0);
    
    A[index] = num;
}

void search_double_hashing(int A[], int num)
{
    int index = (num%10)*5;
    int count=0;
    
    if (A[index]==num)
        cout<<"Number found directly\n";
    else
    {

        while ( (A[index]!=num)&&(count<500) )
        {
            index = ( (count+1)*index + (count*(num+13))%27 )%50;
            count++;
        }
    
    if (A[index]==num)
        cout<<"Number found indirectly\n";
    else
        cout<<"Number NOT found\n";
    }
}
