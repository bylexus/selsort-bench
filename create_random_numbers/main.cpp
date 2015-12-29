//
//  main.cpp
//  create_random_numbers
//
//  Created by Alexander Schenkel on 18.03.15.
//  Copyright (c) 2015 Alexander Schenkel. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, const char * argv[]) {
    srand(time(NULL));
    int size = 100000;
    string filename = "/tmp/random_numbers.txt";
    
    // Fill file with random numbers:
    ofstream file;
    file.open(filename);
    for (int i = 0; i < size; i++) {
        int nr = rand() % size;
        file << nr << endl;
    }
    file.close();
    cout << "written file." <<endl;
    return 0;
}
