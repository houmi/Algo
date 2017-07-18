#include <iostream>
#include <vector>

using namespace std;

void print_board(vector<vector<int>> sols) {
    for (auto board : sols) {
       for (int i=0, len = board.size(); i<len;i++) {
           for (int j=0; j<len;j++) {
               if (board[i] == j) {
                   cout << "Q";
               } else {
                   cout << ".";
               }
            }
            cout << endl;
       }
       cout << endl;
    }
}

bool isValid(vector<int> cols) {
    int len = cols.size()-1;
    for (int i=0; i<len;i++) {
        int diff = abs(cols[i] - cols[len]);
        if (diff == 0 || diff == len - i) {
            return false;
        }
    }

    return true;
}

void nQueens_gen(int row, int n, vector<int> cols, vector<vector<int>>& sols) {
    if ( row == n) {
        sols.push_back(cols);
        return;
    } 

    for (int col=0; col<n; col++) {
        cols.push_back(col);
        if (isValid(cols)) {
            nQueens_gen(row+1, n, cols, sols);
        }
        cols.pop_back();
    }
    
}

void nQeens(int n) {
    vector<int> cols;
    vector<vector<int>> sols;
    nQueens_gen(0, n, cols, sols);
    print_board(sols);
}

int main() {
    nQeens(4);
    return 0;
}