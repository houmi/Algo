#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;


void findPairSum(vector<int> arr, int k) {
    unordered_set<int> set;

    for (auto num : arr) {
        int target = k - num;
        if (set.find(target) != set.end()) {
            cout << num << "+" << target << "=" << k << endl;
        } else {
            set.insert(num);
        }
    }

}

int main() {

    vector<int> arr = {50,3,2,-9, 10,9,45,-40, 123,2,3,1,2,5,9,8,-11,25,30,10,19,3};

    findPairSum(arr, 13);

    
    return 0;

}