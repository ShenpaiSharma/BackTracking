#include <iostream>
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

bool CompleteltyFilled(vector<vector<char>> board){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(board[i][j] == '0')
                return false;
        }
    }
    return true;
}

bool CanbePlaced(vector<vector<char>> board,int row,int col,char num){
    for(int i=0;i<9;i++){
        if(board[row][i] == num){
            return false;
        }
    }
    for(int i = 0; i < 9; i++){
        if(board[i][col] == num)
            return false;
    }
    int rs = row-row%3;
    int cs = col - col%3;
    for(int i=rs;i<rs+2;i++){
        for(int j=cs;j<cs+2;j++){
            if(board[i][j] == num){
                return false;
            }
        }
    }
    return true;
}

bool sudoku(vector<vector<char>> &board){
    if(CompleteltyFilled(board))
        return true;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(board[i][j] == '0'){
                for(int k = 1; k <= 9; k++){
                    char ch = '0' + k;
                    if(CanbePlaced(board, i, j, ch)){
                        board[i][j] = ch;
                        bool flag = sudoku(board);
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

bool sudokuSolver(vector<vector<char>> &board){
    return sudoku(board);
}

int main() {
	vector<vector<char>> board(9);
    char x;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>x;
            board[i].push_back(x);
        }
    }
    bool flag = sudokuSolver(board);
    if(flag){
        print(board);
    }
    return 0;
}
