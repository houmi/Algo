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

void permutations(vector<string> &res, string letters, int begin) {
    if (begin == letters.size()) {
        res.push_back(letters);
        return;
    }
    
    for (int i=begin; i<letters.size();i++) {
        swap(letters[i], letters[begin]);
        permutations(res,letters,begin+1);
        swap(letters[i], letters[begin]);
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

void printvec2d(vector<vector<int>> res, string title) {
    cout << title << endl;
    for (auto v : res) {
        for (auto num : v) {
            cout << num << " ";
        }        
        cout << endl;
    }
}

void printvec(vector<int> res, string title) {
    cout << title << endl;
    for (auto num: res) {
        cout << num << " ";
    }
    cout << endl;
}

int knapSack(vector<int> val, vector<int> weight, int n, int totalW) {
    if (n == 0 || totalW == 0) {
        return 0;
    }

    int result;

    if (weight[n] > totalW) {
        result =  knapSack(val, weight, n-1, totalW);
    } else {
        int tmp1 = val[n] + knapSack(val, weight, n-1, totalW-weight[n]);
        int tmp2 = knapSack(val, weight, n-1, totalW);
        result = max(tmp1, tmp2);
    }
    return result;
}

int main() {

    vector<vector<int>> res;
    vector<int> sol;
    combinations(res, sol, 1, 4, 2);
    printvec2d(res, "Combinations (n,k): n=4, k=2" );
    cout << endl;

    res.clear();
    vector<int> nums = { 1, 2, 3};
    permutations(res, nums, 0);
    printvec2d(res, "Permutations of array 1 2 3");
    cout << endl;

    string str = "ABC";
    vector<string> res2;
    permutations(res2, str, 0);
    cout << "Permutations of " << str << endl;
    for (auto s : res2) {
        cout << s << endl;
    }
    cout << endl;

    

    cout << "Knapsack" << endl;
    vector<int> val = {0, 60, 100, 120};
    vector<int> weight = {0, 10, 20, 30 };
    printvec(val, "Cost values:");
    printvec(weight, "Weight values:");
    int ret = knapSack(val, weight, 3, 50);
    cout << "Total cost: " << ret << endl;

   
    return 0;
}