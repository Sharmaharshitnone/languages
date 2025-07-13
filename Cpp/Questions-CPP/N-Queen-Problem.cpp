#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<string> &board, int row, int col, int n){
    for(int i = 0; i < n; i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }
    
    // for(int j = 0; j < n; j++){
    //     if(board[row][j] == 'Q'){
    //         return false;
    //     }
    // }

    for(int i = row, j = col; i >= 0 && j >= 0; i--,j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    for(int i = row, j = col; i >= 0 && j < n; i--,j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}

void solveNQueens(vector <string> &board, int row, int n, vector<vector<string>> &ans){
    if(row == n){
        ans.push_back(board);
        return;
    }

    for(int j = 0; j < n; j++){
        if(isSafe(board,row,j,n)){
            board[row][j] = 'Q';
            solveNQueens(board, row+1, n,ans);
            board[row][j] = '.';
        }
    }
}

vector<vector<string>> NQueens(int n){
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;

    solveNQueens(board,0,n,ans);

    cout << ans.size() << endl;

    return ans;
}



int main()
{

    int n;
    cin >> n;

    vector<vector<string>> ans = NQueens(n);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << endl;
        }
        cout << endl;
    }

    
    return 0;
}