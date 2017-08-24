#include <iostream>
#include <vector>

using namespace std;

// given vector of integers, find combinations where their sum is equal to k
void findCombinationSums(vector<int> arr, int i, int sum, vector<int> sol, vector<vector<int>> & res) {
    if (sum == 0) {
        res.push_back(sol);
        return;
    }

    if (sum < 0) {
        return;
    }

    for (int j=i; j<arr.size(); j++) {
        sol.push_back(j);
        findCombinationSums(arr, j+1, sum-arr[j], sol, res); 
        sol.pop_back();
    }
}


int main() {
    vector<int> arr = {10, 10, 20, 10, 30, 10 };
    vector<vector<int>> res;
    vector<int> sol;
    findCombinationSums(arr,0,30,sol,res);
    for (auto list : res) {
        for (auto num : list) {
            cout << arr[num] << "(" << num << ") ";
        }
        cout << endl;
    }
    
    return 0;
}