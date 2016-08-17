//
//  functions.cpp
//  file-fix-it_codejam
//
//  Created by Tyler Blanton on 8/7/16.
//  Copyright © 2016 Tyler Blanton. All rights reserved.
//

#include "functions.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int fixFiles(ifstream& inFile)
{
    ofstream outFile("file-fixit-output.txt");
    int numOfTests;
    int numExisting, numNew, newDirs;

    inFile >> numOfTests;
    
    std::vector<string> existingPaths;
    std::vector<string> newPaths;
    
    for(int i = 0; i < numOfTests; ++i)
    {
        newDirs = 0;
        existingPaths.clear();
        newPaths.clear();
        inFile >> numExisting;
        inFile >> numNew;
        
        for(int j = 0; j < numExisting; ++j)
        {
            string temp;
            inFile >> temp;
            existingPaths.push_back(temp);
        }
        
        for(int j = 0; j < numNew; ++j)
        {
            string temp;
            inFile >> temp;
            
            //if the exact path does not already exist
            if(std::find(existingPaths.begin(), existingPaths.end(), temp) == existingPaths.end())
            {
                findClosestPath(temp, existingPaths, newDirs);
            }
        }
        cout << "case #" << i+1 << ": " << newDirs << endl;
        outFile << "case #" << i+1 << ": " << newDirs << endl;
    }
    return 0;
}


/*
//takes the path we are looking to match
//
//calculates the minimum number of new directories that need to be added, adds the new directories if necessary, and increments the newDirs variable
//
*/
string findClosestPath(string& findThis, std::vector<string>& existingPaths, int& newDirs)
{
    //vectors that just contain path names without /'s
    std::vector<string> findThisVector;
    std::vector<string> existingPathsVector;
    string temp;
    int leastDirs = 0; //keeping track of a minimum value here
    
    istringstream ssFind(findThis);
    
    getline(ssFind, temp, '/'); //this takes care of the empty string that comes before each directory in the path
    while(getline(ssFind, temp, '/'))
    {
        findThisVector.push_back(temp);
    }
    
    for(int i = 0; i < existingPaths.size(); ++i)
    {
        existingPathsVector.clear();
        istringstream ssExisting(existingPaths[i]);
        
        getline(ssExisting, temp, '/'); //gets rid of blank space
        while(getline(ssExisting, temp, '/'))
        {
            existingPathsVector.push_back(temp);
        }
        
        int p = 0;
        while(existingPathsVector[p] == findThisVector[p])
        {
            p++;
        }
        if(i==0 || p > leastDirs)
        {
            leastDirs = p;
        }
    }
    newDirs += (findThisVector.size() - leastDirs);
    
    
    //form new thing and put it in existingPaths
    string newDir = "/";
    for(int k = 0; k < findThisVector.size(); ++k)
    {
        newDir += findThisVector[k];
        if(k != findThisVector.size() - 1)
        {
            newDir += "/";
        }
    }
    existingPaths.push_back(newDir);
    
    
    return "";
}








/*
 TODO: There is a problem when nested directories have the same name as directories farther back in the path. (i.e. /tyler/cool and /cool/oherStuff)
 
 */













