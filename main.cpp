#include "burrows_wheeler.h"

int main() {
    string s = "banana";
    
    string bwt = transform(s);
    cout << bwt << endl;

    string original = invert(bwt);
    cout << original << endl;

    return 0;
}
