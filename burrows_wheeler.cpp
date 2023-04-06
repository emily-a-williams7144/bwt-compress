#include "burrows_wheeler.h"

string transform(string input) {
    input.append("$");
    string bwt, copy = input;
    int size = input.size();
    int i, j, k = 0;
    list<string> table;
    list<int> LF;

    for (i = 0; i < size; i++) {
        table.push_back(copy);
        copy.erase(0,1);
    }
    table.sort();

    for (string s : table) {
        LF.push_back(size - s.size());
    }

    for (int j : LF) {
        if (j == 0) bwt += input[size-1];
        else bwt += input[j-1];
    }

    return bwt;
}

string invert(string bwt) {
    string original, sorted = bwt;
    int i, j, count = 0, size = bwt.size();
    map<char, int> occurrence;
    map<char, int> char_count;
    list<int> LF;

    sort(sorted.begin(), sorted.end());

    for (i = 0; i < size; i++) {
        if (i == 0) char_count[sorted[i]] = count;
        else if (sorted[i] != sorted[i-1]) char_count[sorted[i]] = count;
        count++; 
    }

    for (j = 0; j < size; j++) {
        occurrence[bwt[j]] += 1;
        LF.push_front(char_count[bwt[j]] + occurrence[bwt[j]]);
    }

    for (int k : LF) {
        if (bwt[size-k] != '$') original += bwt[size-k];
    }

    return original;
}
