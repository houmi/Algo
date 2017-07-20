#include <iostream>
#include <vector>



using namespace std;

void permutations(vector<vector<int>> &res, vector<int> nums, int begin) {
    if (begin == nums.size()) {
        res.push_back(nums);
        return;
    }
    
    for (int i=begin; i<nums.size();i++) {
        swap(nums[i], nums[begin]);
        permutations(res,nums,begin+1);
        swap(nums[i], nums[begin]);
    }
}

void combinations(vector<vector<int>> &res, vector<int> sol, int pos, int n, int k) {
    if (k==0) {
        res.push_back(sol);
        return;
    }

    for (int i=pos; i<=n;i++) {
        sol.push_back(i);
        combinations(res, sol, i+1, n, k-1);
        sol.pop_back();
    }

}

void printall(vector<vector<int>> res) {
     for (auto v : res) {
        for (auto num : v) {
            cout << num << " ";
        }        
        cout << endl;
    }
}

int knapSack(vector<int> val, vector<int> weight, int n, int totalW) {
    if (n == 0 || totalW == 0) {
        return 0;
    }

    if (weight[n-1] > totalW) {
        return (val, weight, n-1, totalW);
    }

    return max( val[n-1] ,
        knapSack(val, weight, n-1, totalW) + 
        knapSack(val, weight, n-1, totalW-weight[n-1]));

}

int main() {

    vector<vector<int>> res;
    vector<int> sol;
    cout << "Combinations (n,k): n=4, k=2" << endl;
    combinations(res, sol, 1, 4, 2);
    printall(res);
    cout << endl;

    res.clear();
    cout << "Permutations of array 1 2 3" << endl;
    vector<int> nums = { 1, 2, 3};
    permutations(res, nums, 0);
    printall(res);

    vector<int> val = {3, 6, 7, 9, 11, 18};
    vector<int> weight = {1, 2, 3, 5, 6, 8};
    int ret = knapSack(val, weight, 6, 15);
    cout << ret << endl;

   
    return 0;
}