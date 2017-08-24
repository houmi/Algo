#include <iostream>
#include <vector>

using namespace std;

// given vector of times in seconds, find combinations where their sum is equal to k
// return indices of these numbers in the array in vectors
bool findCombinationSums(vector<int> arr, int i, int sum, int k, vector<int> sol, vector<vector<int>> & res) {
    if (sum == k) {
        res.push_back(sol);
        return true;
    }

    for (int j=i; j<arr.size(); j++) {
        if (arr[j]+sum > k) {
            continue;
        }

        sum += arr[j];
        cout << "adding " << arr[j] << " at index " << j << " -- sum:" << sum << endl;
        sol.push_back(j);
        if (findCombinationSums(arr, i+1, sum, k, sol, res)) {
            return true;
        }

        cout << "removing " << arr[j] << " at index " << j << endl;

        sol.pop_back();
    }

    return false;


}




int main() {
    vector<int> arr = {10, 10, 10, 20, 20, 20, 30, 30, 30, 40, 50, 60 };
    vector<vector<int>> res;
    vector<int> sol;
    bool ret = findCombinationSums(arr,0,0,60,sol,res);
    if (ret) {
        for (auto list : res) {
            for (auto num : list) {
                cout << arr[num] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}