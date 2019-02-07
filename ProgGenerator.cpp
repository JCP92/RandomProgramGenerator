//
//  ProgGenerator.cpp
//  ProgrammingPrograms
//
//  Created by Joshua Peckham on 2/2/17.
//  Copyright © 2017 Joshua Peckham. All rights reserved.
//

#include "ProgGenerator.h"
#include <fstream>

void ProgGen::Prog(ofstream& outFile)const{
    srand(time(0));
    outFile << "int main() {\n\t";
    Stat_List(outFile);
    outFile << "\n return 0\n}" << endl;
}
void ProgGen::Stat_List(ofstream& outFile)const{
    int chose = (int)rand() % 100 + 1;
    if ( chose <= 50){
        Stat(outFile);
        outFile << endl;
    }
    else{
        Stat_List(outFile);
        outFile << endl;
        Stat(outFile);
    }
}
void ProgGen::Stat(ofstream& outFile)const{
    int chose = getRand(5);
    switch(chose){
        case 1:
            Cmpd_Stat(outFile);
            break;
        case 2:
            If_Stat(outFile);
            break;
        case 3:
            Iter_Stat(outFile);
            break;
        case 4:
            Assign_Stat(outFile);
            break;
        case 5:
            Decl_Stat(outFile);
            break;
    }
}
void ProgGen::Cmpd_Stat(ofstream& outFile)const{
    outFile << "{\t";
    Stat_List(outFile);
    outFile << "\t}";
}
void ProgGen::If_Stat(ofstream& outFile)const{
    int chose = getRand(6);
    switch(chose){
        case 1:
            outFile << "\n\tIf (";
            Exp(outFile);
            outFile << "){" << endl << "\t\t";
            Stat(outFile);
            outFile << endl << "\t}";
            break;
        case 2:
            outFile << "\n\tIf (";
            Exp(outFile);
            outFile << "){" << endl << "\t\t";
            Cmpd_Stat(outFile);
            outFile << endl << "\t}";
            break;
        case 3:
            outFile << "\n\tIf (";
            Exp(outFile);
            outFile << "){" << endl << "\t\t";
            Stat(outFile);
            outFile << "\n\t}" << endl << "\t\n\tElse{";
            Stat(outFile);
            outFile << endl << "\t}";
            break;
        case 4:
            outFile << "\n\tIf (";
            Exp(outFile);
            outFile << "){" << endl << "\t\t";
            Cmpd_Stat(outFile);
            outFile << "\n\t}" << endl << "\t\n\tElse{";
            Stat(outFile);
            outFile << endl << "\t}";
            break;
        case 5:
            outFile << "\n\tIf (";
            Exp(outFile);
            outFile << "){" << endl << "\t\t";
            Stat(outFile);
            outFile << "\n\t}" << endl << "\t\n\tElse{";
            Cmpd_Stat(outFile);
            outFile << endl << "\t}";
            break;
        case 6:
            outFile << "\n\tIf (";
            Exp(outFile);
            outFile << "){" << endl << "\t\t";
            Cmpd_Stat(outFile);
            outFile << "\n\t}" << endl << "\t\n\tElse{";
            Cmpd_Stat(outFile);
            outFile << endl << "\t}";
    }
}
void ProgGen::Iter_Stat(ofstream& outFile)const{
    int chose = (int)rand() % 100 + 1;
    if(chose <= 50){
        outFile << "\n\twhile (";
        Exp(outFile);
        outFile << "){" << endl << "\t\t";
        Stat(outFile);
        outFile << endl << "\t}";
    }
    else{
        outFile << "\n\twhile (";
        Exp(outFile);
        outFile << "){" << endl << "\t\t";
        Cmpd_Stat(outFile);
        outFile << endl << "\t}";
    }
}
void ProgGen::Assign_Stat(ofstream& outFile)const{
    ID(outFile);
    outFile << " = " ;
    Exp(outFile);
    outFile << ";";
}
void ProgGen::Decl_Stat(ofstream& outFile)const{
    int chose = (int)rand() % 100 + 1;
    if(chose <= 50){
        Type(outFile);
        outFile << "";
        ID(outFile);
        outFile << ";";
    }
    else{
        Type(outFile);
        outFile << "";
        Assign_Stat(outFile);
    }
}
void ProgGen::Exp(ofstream& outFile)const{
    int chose = (int)rand() % 100 + 1;
    if(chose <= 30){
        Exp(outFile);
        outFile << "";
        Op(outFile);
        outFile << "";
        Exp(outFile);
    }
    else if (chose <= 60 ){
        ID(outFile);
    }
    else{
        Const_(outFile);
    }
    
}
void ProgGen::Op(ofstream& outFile)const{
    int chose = (int)rand() % 4 + 1;
    if(chose <= 1){
        outFile << " + ";
    }
    else if (chose <= 2 ){
        outFile << " / ";
    }
    else if ( chose == 3){
        outFile << " - ";
    }
    else{
        outFile << " * ";
    }
}
void ProgGen::Type(ofstream& outFile)const{
    int chose = (int)rand() % 2 + 1;
    if(chose <= 1){
        outFile << "int ";
    }
    else{
        outFile << "double ";
    }
}
void ProgGen::ID(ofstream& outFile)const{
    outFile << Char_();
    Char_digit_Seq(outFile);
}
void ProgGen::Const_(ofstream& outFile)const{
    outFile << Digit();
    Digit_Seq(outFile);
}
void ProgGen::Char_digit_Seq(ofstream& outFile)const{
    int chose = (int)rand() % 20 + 1;
    if(chose <= 6){
        outFile << "";
    }
    else if(chose <= 12){
        ID(outFile);
    }
    else{
        Const_(outFile);
    }
}

void ProgGen::Digit_Seq(ofstream& outFile)const{
    int chose = (int)rand() % 10 + 1;
    if(chose <= 5){
        outFile << "";
    }
    else{
        Const_(outFile);
    }
}
char ProgGen::Char_()const{
    int chose = (int)rand() % 2 + 1;
    int letter = (int)rand() % 26;
    char c;
    if (chose == 1){
        c = (char)(letter+65);
    }
    else if (chose == 2){
        c = (char)(letter+97);
    }
    else{
        c = '_';
    }
    return c;
}
int ProgGen::Digit()const{
    return ((int)rand() % 9 + 1);
}
int ProgGen::getRand(int option)const{
    if (option == 5){
        int chose = (int)rand() % 100 + 1;
        if( chose <= 25)
            return 1;
        else if ( chose <= 35)
            return 2;
        else if ( chose <= 45)
            return 3;
        else if ( chose <= 75)
            return 4;
        else
            return 5;
    }
    else if (option == 6){
        int chose = (int)rand() % 100 + 1;
        if( chose <= 45)
            return 1;
        else if ( chose <= 60)
            return 2;
        else if ( chose <= 70)
            return 3;
        else if ( chose <= 80)
            return 4;
        else if (chose <= 90)
            return 5;
        else
            return 6;
    }
    return 0;
}
