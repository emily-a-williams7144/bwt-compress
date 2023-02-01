#include "burrows_wheeler.h"

int main() {
    string s = "banana";
    Burrows_Wheeler bwt = Burrows_Wheeler(s);

    string transformed = bwt.transform();
    cout << transformed << endl;
    
    string original = bwt.invert(transformed);
    cout << original << endl;

    return 0;
}