//
//  main.cpp
//  asst8-B
//
//  Created by Jad Wahab on 12/1/14.
//  Copyright (c) 2014 Jad Wahab. All rights reserved.
//

int DefaultListSize = 10;

#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include "SLList.h"
#include "add-ons.h"
using namespace std;




int main()
{
    ifstream inData;
    int nbOfFiles=2;        //number of text files
    int lineNumber;
    char period;    //just to get rid of period after number
    word insertedWord;
    location loc;
    string file, fileNumber, w;
    SLList<word, wordCompare> wordList;
    
    for (int i=1; i <= nbOfFiles; i++)          //for each file
    {
        fileNumber = to_string(i);
        file = ( "file" + fileNumber + ".txt");
        
        inData.open(file);

        if (!inData)
        {
            cout<<file <<" was not found...\n";
        }
        
        inData>>lineNumber;
        while (!inData.eof())
        {
            inData>>lineNumber >>period;
            
            while ( (inData.peek() != '\n')&&(!inData.eof()) )      //each line
            {
                inData>>w;
                insertedWord.setWord(w);    
                loc.setFile(file);
                loc.setSentence(lineNumber);
                insertedWord.newLocation(loc);
                wordList.insert(insertedWord);
                
            }
        }
        
        inData.close();
        inData.clear();
        
        wordList.print();
        
    } //end for loop for each file
    

    cout<<endl;
    return 0;
}
