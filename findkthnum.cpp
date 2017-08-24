#include <iostream>
#include <vector>

#include "assert.h"

using namespace std;

// based on two sorted arrays, fine the kth element



// with external array
int findKthBruteForce(vector<int> a, vector<int> b, int k) {
    vector<int> c;
    auto it1 = a.begin();
    auto it2 = b.begin();

    while(it1 != a.end() && it2 != b.end()) {
        if (*it1 < *it2) {
            c.push_back(*it1++);
        } else {
            c.push_back(*it2++);
        }
    }

    while(it1 != a.end()) {
        c.push_back(*it1++);
    }

    while(it2 != b.end()) {
        c.push_back(*it2++);
    }

    return c[k];

}

// w/o external array
int findKthBruteForce2(vector<int> a, vector<int> b, int k) {

    auto it1 = a.begin();
    auto it2 = b.begin();

    int num;

    while(it1 != a.end() && it2 != b.end() && k-->=0) {
        if (*it1 < *it2) {
            num = *it1++;
        } else {
            num = *it2++;
        }
    }

    while(it1 != a.end() && k-->=0) {
        num = *it1++;
    }

    while(it2 != b.end() && k-->=0) {
        num = *it2++;
    }

    return num;

}


int main() {
    vector<int> a = {1, 3, 5, 7, 9};
    vector<int> b = {2, 4, 6, 8, 10, 12, 14};
    assert (findKthBruteForce(a, b, 5) == 6);
    assert (findKthBruteForce2(a, b, 5) == 6);


    return 0;
}