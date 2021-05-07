#include<bits/stdc++.h>
using namespace std;

//Rat in a Maze
bool maze[][4] = {{1,0,0,0}, {1,1,0,1}, {0,1,0,0}, {1,1,1,1}}, sol[4][4];
bool isSafe(int i, int j, int n){
    if(i < n && j < n && maze[i][j] == 1){
        return true;
    }
    return false;
}
bool RatMaze(int i, int j, int n){
    if(i == n - 1 && j == n - 1){
        sol[i][j] = 1;
        return true;
    }
    if(isSafe(i, j, n) == true){
        sol[i][j] = 1;
        if(RatMaze(i + 1, j, n) == true){
            return true;
        }
        else if(RatMaze(i, j + 1, n) == true){
            return true;
        }
        sol[i][j] = 0;
    }
    return false;
}
bool solveMaze(){
    if(RatMaze(0, 0, 4) == false){
        return false;
    }
    else{
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                cout << sol[i][j] << " ";
            }
            cout << "\n";
        }
        return true;
    }
}

//N queens
bool board[4][4];
bool isSafe_(int row, int col, int N){
    for(int i = 0; i < col; i++){
        if(board[row][i]){
            return false;
        }
    }
    for(int i = row, j = col; i >= 0 && j >= 0; i--,j--){
        if(board[i][j]){
            return false;
        }
    }
    for(int i = row, j = col; i < N && j >= 0; i++,j--){
        if(board[i][j]){
            return false;
        }
    }
    return true;
}
bool solveNqueens(int col, int N){
    if(col == N){
        return true;
    }
    for(int i = 0; i < N; i++){
        if(isSafe_(i, col, N) == true){
            board[i][col] = 1;
            if(solveNqueens(col + 1, N)){
                return true;
            }
            board[i][col] = 0;
        }
    }
    return false;
}
bool Nqueens(){
    if(solveNqueens(0, 4) == false){
        return false;
    }
    else{
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                board[i][j] = 0;
            }
        }
    }
    return false;
}

//Mazepath(4 -directions)
bool isSafe__(int i, int j, int m, int n){
    if(i < 0 || j < 0 || i >= m || j >= n){
        return false;
    }
    return true;
}
bool solveMazePath(int i, int j, int matrix[4][4]){
    if(i == 3 && j == 3){
        return true;
    }
    if(isSafe__(i, j, 4, 4)){
        if(isSafe__(i, j + 1, 4, 4) && matrix[i][j + 1] == 0){
            if(solveMazePath(i, j + 1, matrix)){
                return true;
            }
        }
        if(isSafe__(i + 1, j, 4, 4) && matrix[i + 1][j] == 0){
            if(solveMazePath(i + 1, j, matrix)){
                return true;
            }
        }
        if(isSafe__(i, j - 1, 4, 4) && matrix[i][j - 1] == 0){
            if(solveMazePath(i, j - 1, matrix)){
                return true;
            }
        }
        if(isSafe__(i - 1, j, 4, 4) && matrix[i - 1][j] == 0){
            if(solveMazePath(i - 1, j, matrix)){
                return true;
            }
        }
    }
    return false;
}
bool Mazepath(){
    int matrix[4][4] = {{0,0,0,0}, {0,-1,-1,0}, {-1,0,0,0}, {0,0,0,0}};
    if(solveMazePath(0, 0, matrix)){
        return true;
    }
    return false;
}

//Mazepath(2- directions)
vector<string> ans;

void getMazePaths(int sr, int sc, int dr, int dc, string temp) {
    if(sr == dr && sc == dc){
        ans.push_back(temp);
        return;
    }
    if(sc < dc){
        getMazePaths(sr, sc + 1, dr, dc, temp + 'h');
    }
    if(sr < dr){
        getMazePaths(sr + 1, sc, dr, dc, temp + 'v');
    }
}

//FloofFill
void floodfill(vector<vector<int>> maze, int sr, int sc,int dr, int dc, string ans, vector<vector<bool>> visited){
    if(sr == dr && sc == dc){
        cout << ans << endl;
        return;
    }
    if(sr < 0 || sr > dr || sc < 0 || sc > dc||maze[sr][sc] == 1 || visited[sr][sc] == true){
        return;
    }
    visited[sr][sc] = true;
    floodfill(maze,sr - 1,sc,dr,dc,ans + 't',visited);
    floodfill(maze,sr,sc - 1,dr,dc,ans + 'l',visited);
    floodfill(maze, sr + 1, sc,dr,dc,ans + 'd',visited);
    floodfill(maze,sr,sc + 1,dr,dc,ans + 'r',visited);
    visited[sr][sc] = false;
}

//Knights Tour
void knightsTour(vector<vector<int>> &chess, int row, int col, int move){
    if(row < 0 || col < 0 || row >= chess.size() || col >= chess[0].size() || chess[row][col] > 0){
        return;
    }
    else if(move == chess.size() * chess[0].size()){
        chess[row][col] = move;
        // displayBoard(chess);
        chess[row][col] = 0;
        return;
    }
    
    chess[row][col] = move;
    knightsTour(chess, row - 2, col + 1, move + 1);
    knightsTour(chess, row - 1, col + 2, move + 1);
    knightsTour(chess, row + 1, col + 2, move + 1);
    knightsTour(chess, row + 2, col + 1, move + 1);
    knightsTour(chess, row + 2, col - 1, move + 1);
    knightsTour(chess, row + 1, col - 2, move + 1);
    knightsTour(chess, row - 1, col - 2, move + 1);
    knightsTour(chess, row - 2, col - 1, move + 1);
    chess[row][col] = 0;
}

//Word Break
void wordBreak(unordered_set<string> words, string s, string ans){
    if(s == ""){
        cout << ans << endl;
        return;
    }
    string q = "";
    for (int i = 0; i < s.size(); i++) {
        q += s[i];
        if(words.find(q) != words.end()){
            wordBreak(words, s.substr(i + 1), ans + q + ' ');
        }
    }
}

int main(){
    // cout << solveMaze();
    // cout << Nqueens();
    cout << Mazepath();
    return 0;
}