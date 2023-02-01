#ifndef BURROWS_WHEELER_H
#define BURROWS_WHEELER_H

#include <string>
#include <iostream>
using namespace std;

class Burrows_Wheeler {
    private:
        string input;
        int size;
    public:
        Burrows_Wheeler(string str);
        void transform();
};

#endif