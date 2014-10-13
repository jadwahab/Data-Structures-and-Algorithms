//
//  main.cpp
//  Asst8
//
//  Created by Jad Wahab on 11/26/14.
//  Copyright (c) 2014 Jad Wahab. All rights reserved.
//

#include <iostream>
#include <ctime>
#include "pb1.h"
using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));
    
    int n=50;
    int Array[n];
    int num;    
    int choice;
    int search;
    
    while (1)
    {
        cout<<"(1) Bucket Hashing with overflow\n"
            <<"(2) Bucket Hashing with linear probing\n"
            <<"(3) Pseudo-random probing (with sequence)\n"
            <<"(4) Pesudo-random probing (using r1=2 and r2=5)\n"
            <<"(5) Double hashing\n"
            <<"(0) Exit\n";
        
        cin>>choice;
//A:
//BUCKET HASHING:
        if (choice == 1)
        {
            int Overflow[n-5];      //max of overflow array is n-5 in the worst case (but highly unlikely)
            
            init_zero(Array, n);
            init_zero(Overflow, n-5);
            
            for (int i=0; i<n; i++)
            {
                num = (rand()%999) + 1;
                bucket_hashing(Array, Overflow, num);
            }
            
            cout<<"Bucket hashing array:\n";
            print_array(Array, n);
            cout<<"Overflow array:\n";
            print_array(Overflow, n-5);
            cout<<endl;
            
            while (1)
            {
                cout<<"Enter number to search (or enter 0 to quit)\n";
                cin>>search;
                if (search == 0)
                    break;
                else
                    search_bucket_hashing(Array, Overflow, search);
            }
        }
//B:
//LINEAR PROBING:
        else if (choice == 2)
        {
            init_zero(Array, n);
            
            for (int i=0; i<n; i++)
            {
                num = (rand()%999) + 1;
                linear_probing(Array, num);
            }
            
            cout<<"Bucket hashing with linear probing array:\n";
            print_array(Array, n);
            
            while (1)
            {
                cout<<"Enter number to search (or enter 0 to quit)\n";
                cin>>search;
                if (search == 0)
                    break;
                else
                    search_linear_probing(Array, search);
            }
        }
//C:
//PSEUDO-RANDOM:
//using a pseudo-random sequence:
        else if (choice == 3)
        {
            init_zero(Array, n);
            
            int PseudoSequence[n];
            
            for (int i=0; i<n; i++)
                PseudoSequence[i]=i;        //initialize sequence array
            
            pseudo_random_sequence(PseudoSequence, n);          //shuffle elements into pseudo random order
            cout<<"Pseduo-random sequence:\n";
            print_array(PseudoSequence, n);
            
            for (int i=0; i<n; i++)
            {
                num = (rand()%999) + 1;
                pseudo_random_sequence_probing(Array, PseudoSequence, num);
            }
            
            cout<<"Pseudo-random probing without bucketing using a pseudo-random squence:\n";
            print_array(Array, n);
            
            while (1)
            {
                cout<<"Enter number to search (or enter 0 to quit)\n";
                cin>>search;
                if (search == 0)
                    break;
                else
                    search_pseudo_random_sequence_probing(Array, PseudoSequence, search);
            }
        }
//without using a sequence:
        else if (choice == 4)
        {
            init_zero(Array, n);
            
            for (int i=0; i<n; i++)
            {
                num = (rand()%999) + 1;
                pseudo_random_probing2(Array, num);
            }
            
            cout<<"Pseudo-random probing without bucketing using r1=2 and r2=5:\n";
            print_array(Array, n);
            
            while (1)
            {
                cout<<"Enter number to search (or enter 0 to quit)\n";
                cin>>search;
                if (search == 0)
                    break;
                else
                    search_pseudo_random_probing2(Array, search);
            }

        }
//D:
//DOUBLE HASHING:
        else if (choice == 5)
        {
            init_zero(Array, n);
            
            for (int i=0; i<n; i++)
            {
                num = (rand()%999) + 1;
                double_hashing(Array, num);
            }
            
            cout<<"Double hashing:\n";
            print_array(Array, n);
            
            while (1)
            {
                cout<<"Enter number to search (or enter 0 to quit)\n";
                cin>>search;
                if (search == 0)
                    break;
                else
                    search_double_hashing(Array, search);
            }
        }
        
//Quit
        else
            break;
    }//end while
    
    
    
    return 0;
}
