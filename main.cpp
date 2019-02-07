//
//  main.cpp
//  ProgrammingPrograms
//
//  Created by Joshua Peckham on 1/23/17.
//  Copyright © 2017 Joshua Peckham. All rights reserved.
//

#include "ProgGenerator.h"

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;


int main() {
    ofstream outFile;      // file containing output
    string outFileName;    // output file external name
    
    cout << "Enter name of output file; press return." << endl;
    cin  >> outFileName;
    outFile.open(outFileName);
    if(outFile.is_open())
        cout << "Success" << endl;
    else
        cout << "fail" << endl;
    ProgGen Start;
    Start.Prog(outFile);
    
    
    
    return 0;
}
