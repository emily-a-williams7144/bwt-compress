#include "burrows_wheeler.h"

Burrows_Wheeler::Burrows_Wheeler(string str) {
    input = str;
    size = str.size() + 1;
}

void Burrows_Wheeler::transform() {
    input.append("$");
    int rotation = 1;
    int i, k;
    string temp1;
    string temp2;
    bool sorted;
    char temp[size];
    int compare;
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

    for (int i = 0; i < size; i++) {
        for (int k = 0; k < size; k++) {
            cout << matrix[i][k];
        }
        cout << endl;
    }
}