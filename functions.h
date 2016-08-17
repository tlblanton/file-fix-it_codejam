//
//  functions.hpp
//  file-fix-it_codejam
//
//  Created by Tyler Blanton on 8/7/16.
//  Copyright © 2016 Tyler Blanton. All rights reserved.
//

#ifndef functions_hpp
#define functions_hpp
#pragma once

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int fixFiles(ifstream&);

string findClosestPath(string&, std::vector<string>&, int&);

#endif /* functions_h */
