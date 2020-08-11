#include <bits/stdc++.h>

using namespace std;

void Print(int** path, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<path[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void MazeFindHelper(vector<vector<int>> maze,int** path,int x,int y,int n){
    if(x == n-1 && y == n-1){
        path[x][y] = 1;
        Print(path,n);
        return;
    }
    if(x < 0 || y < 0 || x >= n || y >= n || maze[x][y] == 0 || path[x][y] == 1){
        return;
    }
    path[x][y] = 1;
    MazeFindHelper(maze,path,x-1,y,n);
    MazeFindHelper(maze,path,x+1,y,n);
    MazeFindHelper(maze,path,x,y-1,n);
    MazeFindHelper(maze,path,x,y+1,n);
    path[x][y] = 0;
}

void MazeFinder(vector<vector<int>> maze,int n){
    int** path = new int*[n];
    for(int i=0;i<n;i++){
        path[i] = new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            path[i][j] = 0;
        }
    }
    MazeFindHelper(maze,path,0,0,n);
    delete [] path;
}

int main() {
    int n;
    cin>>n;
    vector<vector<int>> maze(n);
    int x;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>x;
            maze[i].push_back(x);
        }
    }
    MazeFinder(maze,n);
	return 0;
}
