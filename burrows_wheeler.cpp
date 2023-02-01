#include "burrows_wheeler.h"

Burrows_Wheeler::Burrows_Wheeler(string str) {
    input = str;
    size = str.size() + 1;
}

string Burrows_Wheeler::transform() {
    input.append("$");
    int rotation = 1;
    int i, k, compare;
    string temp1, temp2, bwt;
    bool sorted;
    char temp[size];
    char matrix[size][size];

    for (i = 0; i < size; i++) {
        for (k = 0; k < size; k++) {
            matrix[i][(k+rotation)%size] = input[k];
        }
        rotation++;
    }

    do {
        sorted = 1;
        for (i = 1; i < size; i++) {
            temp1 += matrix[i];
            temp2 += matrix[i-1];
            compare = temp2.compare(temp1);
            if (compare > 0) {
                for (k = 0; k < size; k++) {
                    temp[k] = matrix[i][k];
                    matrix[i][k] = matrix[i-1][k];
                    matrix[i-1][k] = temp[k];
                }
                sorted = 0;
            }
            temp1.clear();
            temp2.clear();
        }
    } while (!sorted);

    for (k = 0; k < size; k++) {
        bwt += matrix[size-1][k];
    }

    return bwt;
}

string Burrows_Wheeler::invert(string bwt) {
    return bwt;
}
