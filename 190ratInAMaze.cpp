// https://www.naukri.com/code360/problems/rat-in-a-maze_1215030
#include <bits/stdc++.h>
using namespace std;
bool isSafe(int x, int y, vector<vector<bool>> &visited, vector<vector<int>> arr, int n){
    return x >= 0 && x < n && y >= 0 && y < n && !visited[x][y] && arr[x][y];
}

void solve(int x, int y, vector<vector<int>> arr, int n, vector<string> &ans, vector<vector<bool>> &visited, string path){
    if(x == n - 1 && y == n - 1){
        ans.push_back(path);
        return;
    }
    // alphabetical order: DLRU

    visited[x][y] = true;       // common in all if

    // D
    if(isSafe(x + 1, y, visited, arr, n))
        solve(x + 1, y, arr, n, ans, visited, path + 'D');

    // L
    if(isSafe(x, y - 1, visited, arr, n))
        solve(x, y - 1, arr, n, ans, visited, path + 'L');

    // R
    if(isSafe(x, y + 1, visited, arr, n))
        solve(x, y + 1, arr, n, ans, visited, path + 'R');

    // U
    if(isSafe(x - 1, y, visited, arr, n))
        solve(x - 1, y, arr, n, ans, visited, path + 'U');

    visited[x][y] = false;      // backtracking, common in all if
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    string path = "";
    if(arr[0][0] == 0)  return ans;
    solve(0, 0, arr, n, ans, visited, path);
    return ans;
}