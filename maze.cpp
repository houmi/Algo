#include <vector>
#include <iostream>

using namespace std;

bool isValid(vector<vector<int>> grid, int row, int col) {
    int rows = grid.size();
    int cols = grid[0].size();
    if (row >=0 && row < rows && col >=0 && col < cols && grid[row][col]==0) {
        return true;
    } else {
        return false;
    }
}

bool isAtEnd(vector<vector<int>> grid, int row, int col) {
    int rows = grid.size();
    int cols = grid[0].size();
    return (row == rows-1 && col == cols-1);
}


int numberOfPaths(vector<vector<int>> grid, int row, int col) {
    if (!isValid(grid, row, col)) {
        return 0;
    } else if (isAtEnd(grid, row, col)) {
        return 1;
    } else {
        return (numberOfPaths(grid, row+1, col) + numberOfPaths(grid, row, col+1));
    }
}


int main() {

    vector<vector<int>> maze = { { 0, 0, 0, 0, 0, 0, 0, 0 } ,
                                 { 0, 0, 1, 0, 0, 0, 1, 0 } ,
                                 { 0, 0, 0, 0, 1, 0, 0, 0 } ,
                                 { 1, 0, 1, 0, 0, 1, 0, 0 } ,
                                 { 0, 0, 1, 0, 0, 0, 0, 0 } ,
                                 { 0, 0, 0, 1, 1, 0, 1, 0 } ,
                                 { 0, 1, 0, 0, 0, 1, 0, 0 } ,
                                 { 0, 0, 0, 0, 0, 0, 0, 0 }};

    int paths = numberOfPaths(maze, 0, 0);
    cout << "Number of Paths: " << paths << endl;

    return 0;

}