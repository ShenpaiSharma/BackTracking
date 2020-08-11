#include <iostream>
using namespace std;

void printSolution(int** chess,int n) 
{ 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) 
            cout<<chess[i][j]<<" ";
        cout<<endl; 
    } 
} 

bool isSafe(int** chess,int n,int row,int col){
    int i,j;
    for (i = 0; i < row; i++) 
        if (chess[i][col]) 
            return false; 
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (chess[i][j]) 
            return false; 
    for (i = row, j = col; j >= 0 && i < n; i++, j--) 
        if (chess[i][j]) 
            return false; 
    return true;
}

bool NQueenSolver(int** chess,int n,int row){
    if(row >= n){
        return true;
    }
    for(int i=0;i<n;i++){
        if(isSafe(chess,n,row,i)){
            chess[row][i] = 1;
            if(NQueenSolver(chess,n,row+1)){
                return true;
            }
            chess[row][i] = 0;
        }
    }
    return false;
}

int main() {
    int n;
    cin>>n;
	int** chess = new int*[n];
    for(int i=0;i<n;i++){
        chess[i] = new int[n];
    }
    int x;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            chess[i][j] = 0;
        }
    }
    if(NQueenSolver(chess,n,0)){
        printSolution(chess,n);
    }
    delete [] chess;
	return 0;
}
