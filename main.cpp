#include "burrows_wheeler.h"

int main() {
    string s = "banana";
    Burrows_Wheeler bwt = Burrows_Wheeler(s);
    bwt.transform();

    return 0;
}