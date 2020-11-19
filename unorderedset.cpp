#include<bits/stdc++.h>
#include<unordered_set>
using namespace  std;

void print_distinct_elements(int arr[], int n){ //O(n) time
    unordered_set<int> s;
    for(int i = 0; i < n; i++){
        s.insert(arr[i]);
    }
    for(auto it = s.begin(); it != s.end(); it++){
        cout << *it << " ";
    }
    // for(int i = 0; i < n; i++){      //for printing distinct elements in the same order as they were in the array //O(n) time 
    //     if(s.find(arr[i]) == s.end()){
    //         cout << arr[i] << " ";
    //         s.insert(arr[i]);
    //     }
    // }
}

void print_repeating_elements(vector<int> arr){ //O(n) time and O(n) aux space
    unordered_set<int> s;
    for(int i = 0; i < arr.size(); i++){
        if(s.find(arr[i]) == s.end()){
            s.insert(arr[i]);
        }else{
            cout << arr[i] << " ";
        }
    }
}

bool findPairwithgivenSum(int arr[], int n, int sum){ //O(n) time and O(n) aux space
    unordered_set<int> s;
    for(int i = 0; i < n; i++){
        if(s.find(sum - arr[i]) != s.end()){
            s.insert(arr[i]);
        }else{
            return true;
        }
    }
    return false;
}

void printIntersectionelements(int arr1[], int n1, int arr2[], int n2){ //O(n1 + n2) time , O(n) aux space
    unordered_set<int> s;
    for(int i = 0; i < n2; i++){
        s.insert(arr2[i]);
    }
    for(int i = 0; i < n1; i++){
        if(s.find(arr1[i]) != s.end()){
            cout << arr1[i] << " ";
        }
    }
}

int maxTypesofElements(int arr[], int n, int k){ //O(n) time and O(n) aux space
    unordered_set<int> s;
    int d = 0;
    for(int i = 0; i < n; i++){
        if(s.find(arr[i]) == s.end()){
            s.insert(arr[i]);
            d++;
        }
    }
    int nbyk = n / k;
    if(d >= nbyk){return nbyk;}
    else{return d;}
}

int getLongestSubsequence(int arr[], int n){
    int res = 0;
    unordered_set<int> s;
    for(int i = 0; i < n; i++){
        s.insert(arr[i]);
    }
    for(int i = 0; i < n; i++){
        if(s.find(arr[i] - 1) == s.end()){
            int curr = 1;
            while(s.find(arr[i] + curr) != s.end()){
                curr++;
            }
            res = max(res, curr);
        }
    }
    return res;
}

bool subarrwithZeroSum(int arr[], int n){ //O(n) time and O(n) aux space
    unordered_set<int> s;
    int pre_sum = 0;
    for(int i = 0; i < n; i++){
        pre_sum += arr[i];
        if(s.find(pre_sum) != s.end()){
            return true;
        }
        if(pre_sum == 0){
            return true;
        }
        s.insert(pre_sum);
    }
    return false;
}

int main(int argc, char** argv){
    int arr[] = {1, 5, 7, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    // print_distinct_elements(arr, n);
    // vector<int> arr(5, 0);
    // for(int i = 0; i < arr.size(); i++){
    //     cin >> arr[i];
    // }
    // print_repeating_elements(arr);
    cout << findPairwithgivenSum(arr, n, 2);
    int arr2[] = {10, 10, 5, 2};
    // printIntersectionelements(arr, n, arr2, 4);
    // cout << maxTypesofElements(arr, n, 2);
    // cout << getLongestSubsequence(arr, n);
    return 0;
}