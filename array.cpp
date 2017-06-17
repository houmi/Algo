#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>

using namespace std;

void printArray(vector<int> arr) {
    cout << "Print vector" << endl;
    string delim = "";
    for (auto num : arr) {
        cout << delim << num;
        delim = ",";
    }
    cout << endl;

}

void findPairSum(vector<int> arr, int k) {
    unordered_set<int> set;

    cout << "Find Pair Sum" << endl;

    for (auto num : arr) {
        int target = k - num;
        if (set.find(target) != set.end()) {
            cout << num << "+" << target << "=" << k << endl;
        } else {
            set.insert(num);
        }
    }
}

void removeDuplicates(vector<int> arr) {
    vector<int> arr2(arr);
    sort(arr2.begin(), arr2.end());

    int idx = 0;
    for (int i=1; i<arr2.size();i++) {
        if (arr2[i] != arr2[idx]) {
            arr2[++idx] = arr2[i];
        }
    }
    
    arr2.resize(idx);
    printArray(arr2);
}



int main() {

    vector<int> arr = {50,3,2,-9, 10,9,45,-40, 123,2,3,1,2,5,9,8,-11,25,30,10,19,3};

    printArray(arr);
    findPairSum(arr, 13);
    removeDuplicates(arr);


    
    return 0;

}