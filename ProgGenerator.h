//
//  ProgGenerator.h
//  ProgrammingPrograms
//
//  Created by Joshua Peckham on 2/2/17.
//  Copyright © 2017 Joshua Peckham. All rights reserved.
//

#ifndef ProgGenerator_h
#define ProgGenerator_h
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

class ProgGen{
public:
    void Prog(ofstream&)const; //Initial call parses through all functions untill values are returned
private:
    void Stat_List(ofstream&)const;// selects the statement list then goes stat or stat_list
    void Stat(ofstream&)const;// determines type of statement cmpd/if/iter/assign/declar
    void Cmpd_Stat(ofstream&)const; // starts over at stat_list
    void If_Stat(ofstream&)const;// variation of If statements
    void Iter_Stat(ofstream&)const;// variation of while statements
    void Assign_Stat(ofstream&)const;// calls id and equals to call exp
    void Decl_Stat(ofstream&)const;// calls type and id or type and assignment statement
    void Exp(ofstream&)const;// breaks down to different exponents and calls exp/op/id/const
    void Op(ofstream&)const;// selects sign for an expression
    void Type(ofstream&)const;// declars typ of variable
    void ID(ofstream&)const;//calls and creates string of characters
    void Const_(ofstream&)const;// calls creates string of numbers
    void Char_digit_Seq(ofstream&)const;// calls creates an empty/digit and character/ character sequance
    void Digit_Seq(ofstream&)const; // calls and creates an empty, a number, or series of numbers
    char Char_()const; //returns character
    int Digit()const;// returns digit
    int getRand(int options)const; // creates a rand number
};

#endif /* ProgGenerator_h */
