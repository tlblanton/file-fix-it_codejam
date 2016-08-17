//
//  main.cpp
//  file-fix-it_codejam
//
//  Created by Tyler Blanton on 8/7/16.
//  Copyright © 2016 Tyler Blanton. All rights reserved.
//
//
//solution to problem found here: https://code.google.com/codejam/contest/635101/dashboard#s=p0


#include <iostream>
#include <fstream>
#include "functions.h"
using namespace std;

int main()
{
    ifstream inFile("A-small-practice.in.txt");
    if(inFile)
    {
        fixFiles(inFile);
    }
    else
    {
        cerr << "Could not locate file. Program terminated." << endl;
    }
 
    
    
    return 0;
}