//
//  add-ons.h
//  asst8-B
//
//  Created by Jad Wahab on 12/3/14.
//  Copyright (c) 2014 Jad Wahab. All rights reserved.
//

#pragma once



//LOCATION OF WORD
class location
{
    string file;
    int sentence;
    
public:
    location(string f=" ", int s=0)
    {
        file = f;
        sentence = s;
    }
    void setFile(string f) { file = f; }
    void setSentence(int s) { sentence = s; }
    friend ostream& operator<<(ostream& o, location l)
    {
        o << "File: " << l.file << "\nSentence : " << l.sentence;
        return o;
    }
};


//CLASS TO STORE WORD, ID, AND LOCATION
class word
{
    string w;
    int ID;
    int frequency;
    LList<location> locations;
    
public:
    word(string s=" ")
    {
        w = s;
    }
    word(string s, location l, int idd)
    {
        w = s;
        newLocation(l);
        ID = idd;
    }
    string getWord() {return w;}
    int getFrequency() {return frequency;}
    int getID() { return ID; }
    void setWord(string s) { w = s; }
    void setID(int idd) { ID = idd; }
    void setFrequency(int freq) {frequency = freq;}
    void incFrequency() {frequency++;}  //incrememnt frequency
    
    void newLocation(location& l) { locations.append(l); }
    friend ostream& operator<<(ostream& o, word w1)
    {
        o <<w1.w;
        return o;
    }
};




//COMPARATORS:
class stringCompare
{
public:
    static bool eq(string s1, string s2)    {return s1 == s2;}
    static bool lt(string s1, string s2)    {return s1 < s2;}
    static bool gt(string s1, string s2)    {return s1 > s2;}
};

class wordCompare
{
public:
    static bool lt(word w1, word w2) { return (w1.getWord() < w2.getWord()); }
    static bool eq(word w1, word w2) { return (w1.getWord() == w2.getWord()); }
    static bool gt(word w1, word w2) { return (w2.getWord() > w2.getWord()); }
};


class frequencyCompare
{
public:
    static bool lt(word w1, word w2) { return (w1.getFrequency() < w2.getFrequency()); }
    static bool eq(word w1, word w2) { return (w1.getFrequency() == w2.getFrequency()); }
    static bool gt(word w1, word w2) { return (w2.getFrequency() > w2.getFrequency()); }
};





