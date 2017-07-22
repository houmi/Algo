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

int numberOfPaths(vector<vector<int>> grid, int row, int col, vector<vector<int>> paths) {
    if (!isValid(grid, row, col)) {
        return 0;
    } else if (isAtEnd(grid, row, col)) {
        return 1;
    } else if (paths[row][col] == 0) {
        paths[row][col] = numberOfPaths(grid, row+1, col) + numberOfPaths(grid, row, col+1);
    }
    
    return paths[row][col];
    
}

bool findPaths(vector<vector<int>> grid, int row, int col, vector<vector<int>> sol, vector<vector<vector<int>>>& grids) {
    if (isAtEnd(grid, row, col)) {
        sol[row][col]=1;
        grids.push_back(sol);
        return true;
    }

    if (isValid(grid, row, col)) {

        sol[row][col]=1;

        if (isValid(grid, row+1, col)) {
            return (findPaths(grid, row+1, col, sol, grids));
        }
        
        if (isValid(grid, row, col+1)) {
            return (findPaths(grid, row, col+1, sol, grids));
        }

        sol[row][col]=0;
    }

    return false;
}

void printMaze(vector<vector<int>> grid) {

    for (auto row : grid) {
        for (auto num : row) {
            cout << num;
        }
        cout << endl;
    }
    cout << endl;

}

void printMazes(vector<vector<vector<int>>> grids) {
    for (auto grid : grids) { 
        for (auto row : grid) {
            for (auto num : row) {
                cout << num;
            }
            cout << endl;
        }
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
    cout << "Maze:" << endl;
    printMaze(maze);

    vector<vector<int>> paths(8, vector<int>(8,0));
    
    int numpaths;
    
    numpaths = numberOfPaths(maze, 0, 0);
    cout << "Number of Paths: " << numpaths << endl;

    numpaths = numberOfPaths(maze, 0, 0, paths);
    cout << "Number of Paths (with memorization): " << numpaths << endl;

    vector<vector<vector<int>>> grids;
    findPaths(maze, 0, 0, paths, grids);
    cout << "Find Path:" << endl;
    printMazes(grids);

    return 0;

}