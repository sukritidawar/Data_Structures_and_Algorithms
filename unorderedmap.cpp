#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// 1. Data Structure for storing balance 
unordered_map<int, int> m;
void set_userId(int userId, int balance){ //O(1) time
    m[userId] = balance;
}
int get_balance(int userId){ //O(1) time
    return m[userId];
}

// 2. Freq of array elements
void print_freq_of_array_elements(int arr[], int n){ //O(n) because of printing
    unordered_map<int, int> freq;
    for(int i = 0; i < n; i++){
        freq[arr[i]]++;
    }
    // for(auto x : freq){
    //     cout << x.first << " " << x.second << endl;
    // }
    for(int i = 0; i < n; i++){  
        if(freq[arr[i]] != -1){
            cout<< arr[i] << " " << freq[arr[i]] << endl;
            freq[arr[i]] = -1; 
        }
    }
}

//3.Winner of an election
string winnerofelection(string arr[], int n){ //O(n * max_len)
    unordered_map<string, int> m;
    for(int i = 0; i < n; i++){
        m[arr[i]]++;
    }
    int max_freq = 0;
    string winner;
    for(auto x : m){
        if(x.second > max_freq){
            max_freq = x.second;
            winner = x.first;
        }else if(x.second == max_freq && x.first < winner){
            winner = x.first;
        }
    }
    return winner;
}

//4. Count distinct elements in every window
void CountDist(int arr[], int n, int k){  //O(n) time and O(n) aux space
    unordered_map<int, int> freq;
    for(int i = 0; i < k; i++){
        freq[arr[i]]++;
    }
    cout << freq.size() << " ";
    for(int i = k; i < n; i++){
        freq[arr[i - k]]--;
        if(freq[arr[i - k]] == 0){
            freq.erase(arr[i - k]);
        }
        freq[arr[i]]++;
        cout << freq.size() << " ";
    }
}

int main(int argc, char** argv){
    // set_userId(1000345, 500);
    // cout << get_balance(1000345);
    int arr[] = {10, 20, 10, 10, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]); 
    // print_freq_of_array_elements(arr, n);
    // string arr[] = {"abc", "xyz", "abc", "def"};
    // int n = sizeof(arr)/ sizeof(arr[0]);
    // cout << winnerofelection(arr, n);
    CountDist(arr, n, 4);
    return 0;
}