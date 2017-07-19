#include <iostream>
#include <vector>



using namespace std;

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

int main() {

    vector<vector<int>> res;
    vector<int> sol;
    combinations(res, sol, 1, 4, 2);
    for (auto v : res) {
        for (auto num : v) {
            cout << num << " ";
        }        
        cout << endl;
    }
    return 0;
}