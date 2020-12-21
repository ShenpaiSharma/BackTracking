#include <bits/stdc++.h>
#include <vector>
using namespace std;

void print(vector<vector<char>> board){
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool CompleteltyFilled(vector<vector<char>> board,int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == '0')
                return false;
        }
    }
    return true;
}

bool CanbePlaced(vector<vector<char>> board,int row,int col,char num,int n){
    for(int i=0;i<n;i++){
        if(board[row][i] == num){
            return false;
        }
    }
    for(int i = 0; i < n; i++){
        if(board[i][col] == num)
            return false;
    }
    int r = sqrt(n);
    int rs = row-row%r;
    int cs = col - col%r;
    for(int i=rs;i<rs+r-1;i++){
        for(int j=cs;j<cs+r-1;j++){
            if(board[i][j] == num){
                return false;
            }
        }
    }
    return true;
}

bool sudoku(vector<vector<char>> &board,int n){
    if(CompleteltyFilled(board,n))
        return true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == '0'){
                for(int k = 1; k <= n; k++){
                    char ch = '0' + k;
                    if(CanbePlaced(board, i, j, ch,n)){
                        board[i][j] = ch;
                        bool flag = sudoku(board,n);
                        if(flag)
                            return true;
                        else
                            board[i][j] = '0';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool sudokuSolver(vector<vector<char>> &board,int n){
    return sudoku(board,n);
}

int main() {
    int n;
    cin>>n;
	vector<vector<char>> board(n);
    char x;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>x;
            board[i].push_back(x);
        }
    }
    bool flag = sudokuSolver(board,n);
    if(flag){
        print(board);
    }
    return 0;
}
//Input
// 9
// 3 0 6 5 0 8 4 0 0 
// 5 2 0 0 0 0 0 0 0 
// 0 8 7 0 0 0 0 3 1 
// 0 0 3 0 1 0 0 8 0 
// 9 0 0 8 6 3 0 0 5 
// 0 5 0 0 9 0 6 0 0 
// 1 3 0 0 0 0 2 5 0 
// 0 0 0 0 0 0 0 7 4 
// 0 0 5 2 0 6 3 0 0
