//
//  main.cpp
//  LearnCpp
//
//  Created by Alexander Schenkel on 15.03.15.
//  Copyright (c) 2015 Alexander Schenkel. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <sys/time.h>

using namespace std;

template<class T>
void selectionsort(vector<T>& arr) {
    size_t sIndex = 0;
    unsigned long size = arr.size();
    unsigned long smallestIndex = 0;
    T tmp;
    while (sIndex < size) {
        smallestIndex = sIndex;
        for(unsigned long i = sIndex; i < size;i++) {
            if (arr[i] < arr[smallestIndex]) {
                smallestIndex = i;
            }
        }
        if (sIndex < smallestIndex) {
            tmp = arr[smallestIndex];
            arr[smallestIndex] = arr[sIndex];
            arr[sIndex] = tmp;
        }
        sIndex++;
    }
}

void selectionsort_arr(int arr[], size_t size) {
    size_t sIndex = 0;
    size_t smallestIndex = 0;
    int tmp;
    while (sIndex < size) {
        smallestIndex = sIndex;
        for(size_t i = sIndex; i < size;i++) {
            if (arr[i] < arr[smallestIndex]) {
                smallestIndex = i;
            }
        }
        if (sIndex < smallestIndex) {
            tmp = arr[smallestIndex];
            arr[smallestIndex] = arr[sIndex];
            arr[sIndex] = tmp;
        }
        sIndex++;
    }
}

/*
template<class T>
long binsearch(int search, vector<T>& arr, unsigned long leftBound, unsigned long rightBound) {

    unsigned long center = (rightBound + leftBound) / 2;
    if (search == arr[center]) return center;
    if (leftBound == rightBound) return -1;

    if (search < arr[center])
        return binsearch(search, arr, leftBound, max(center-1,leftBound));
    else
        return binsearch(search, arr, min(center+1,rightBound), rightBound);
}
 */

int main(int argc, const char * argv[]) {
    timeval start, after_read, after_sort;

    string inputfile = "/Users/alex/temp/random_numbers.txt";

    vector<int> data = vector<int>();

    // start
    gettimeofday(&start, NULL);
    cout << "Start: " << start.tv_sec + start.tv_usec/1000000.0 << endl;

    // Fill vector:
    ifstream file (inputfile);
    string line;
    int nr;

    while (getline(file, line)) {
        stringstream(line) >> nr;
        data.push_back(nr);
    }
    gettimeofday(&after_read, NULL);

    // sort vector:
    selectionsort_arr(&data[0],data.size());

    gettimeofday(&after_sort, NULL);

    double fill_duration = (after_read.tv_sec + after_read.tv_usec/1000000.0) - (start.tv_sec + start.tv_usec/1000000.0);
    double sort_duration = (after_sort.tv_sec + after_sort.tv_usec/1000000.0) - (after_read.tv_sec + after_read.tv_usec/1000000.0);
    cout << "Fill time: " << fill_duration << endl;
    cout << "Sort time: " << sort_duration << endl;

    cout << "First nr: " << data[0] << ", last nr: " << data[data.size()-1] << endl;

    // search a certain number:
    //search = binsearch(55, data, 0, data.size()-1);

    // Out:
    /*for (i = 0; i < data.size();i++) {
        cout << data[i] << ", ";
    }*/

    /*
    if (search < ULONG_MAX) {
        cout << "\nFound 55 at position: " << search << endl;
    } else {
        cout << "\n55 not found. sad." <<endl;
    }
     */



    // int found = binsearch(search, data,0,(int)data.size()-1);

    //cout << "Found " << search << " at pos " << found << endl;
    return 0;
}
