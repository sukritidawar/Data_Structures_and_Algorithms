#include <bits/stdc++.h>
using namespace std;

void print_SnakePattern(int arr[][4], int n, int m){
    // int n = arr.size();
    // int m = arr[0].size();
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            for(int j = 0; j < m; j++){
                cout << arr[i][j] << " ";
            }
        }
        else{
            for(int j = m - 1; j >= 0; j--){
                cout << arr[i][j] << " ";
            }
        }
    }
}

void print_Boundary_elements(int arr[4][4], int r, int c){
    if(r == 1){
        for(int i = 0; i < c; i++){
            cout << arr[i] << " ";
        }
    }
    else if(c == 1){
        for(int i = 0; i < r; i++){
            cout << arr[i] << " ";
        }
    }
    else{
        for(int j = 0; j < c; j++){
            cout << arr[0][j] << " ";
        }
        for(int i = 1; i < r - 1; i++){
            cout << arr[i][c - 1] << " ";
        }
        for(int j = c - 1; j >= 0; j--){
            cout << arr[r - 1][j] << " ";
        }
        for(int i = r - 1; i > 0; i--){
            cout << arr[i][0] << " ";
        }
    }
}

void transposeMatrix(int arr[4][4], int r, int c){
    for(int i = 0; i < r; i++){
        for(int j = i + 1; j < c; j++){
            swap(arr[i][j], arr[j][i]);
        }
    }
    // return arr;
}

void rotateMatrix90(int arr[4][4], int r, int c){ //naive O(n2)
    for(int j = c - 1; j >= 0; j--){
        for(int i = 0; i < r; i++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void rotateMatrix90_efficient(int arr[4][4], int r, int c){
    transposeMatrix(arr, 4, 4); //transpose the matrix
    for(int i = 0; i < r; i++){
        int low = 0, high = r - 1;
        while(low < high){
            swap(arr[low][i], arr[high][i]);
            low++;
            high--;
        }
    }
}

void printSpiralform(int arr[4][4], int r, int c){
    int top = 0, bottom = r - 1, left = 0, right = c - 1;
    int elements = r*c;
    while(elements > 0){
        for(int i = 0; i <= right && elements > 0; i++){
            cout << arr[top][i] << " ";
            elements--;
        }
        top++;
        for(int i = top; i <= bottom && elements > 0; i++){
            cout << arr[i][right] << " ";
            elements--;
        }
        right--;
        for(int i = right; i >= left && elements > 0; i--){
            cout << arr[bottom][i] << " ";
            elements--;
        }
        bottom--;
        for(int i = bottom; i > top && elements > 0; i--){
            cout << arr[i][left] << " ";
            elements--;
        }
        left++;
    }
}

void searchInRowColumnSortedMatrix(int arr[4][4], int r, int c, int x){ //O(r + c) time
    int i = 0, j = c - 1;
    while(i < r && j >= 0){
        if(arr[i][j] == x){
            cout << "Found at " << i << "," << j << endl;
            return;
        }
        else if(arr[i][j] > x){
            j--;
        }
        else{
            i++;
        }
    }
    cout << "Not found.";
}

int main(){
    int arr[4][4] = {{10, 20, 30, 40},{15, 25, 35, 45},{27, 29, 37, 48},{32, 33, 39, 50}};
    // vector<vector<int> > arr(4, vector<int>(4, 0));
    // for(int i = 0; i < )
    // print_SnakePattern(arr, 4, 4);
    // print_Boundary_elements(arr, 4, 4);
    // transposeMatrix(arr, 4, 4);
    // rotateMatrix90(arr, 4, 4);
    // rotateMatrix90_efficient(arr, 4, 4);
    // printSpiralform(arr, 4, 4);
    searchInRowColumnSortedMatrix(arr, 4, 4, 29);
    // for(int i = 0; i < 4; i++){
    //     for(int j = 0; j < 4; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // return 0;
}