#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int intersection_twoUnsortedArrays(int arr1[], int arr2[], int n1, int n2){ //O(n1 + n2) time, O(n1 + n2) space
    unordered_set<int> s1;
    unordered_set<int> in;
    for(int i = 0; i < n2; i++){
        s1.insert(arr2[i]);
    }
    for(int i = 0; i < n1; i++){
        if(s1.find(arr1[i]) != s1.end()){
            in.insert(arr1[i]);
        }
    }
    return in.size();
}

int union_twoSortedArrays(int arr1[], int arr2[], int n1, int n2){ //O(n1 + n2) time, O(n1 + n2) space
    unordered_set<int> uni;
    for(int i = 0; i < n1; i++){
        uni.insert(arr1[i]);
    }
    for(int i = 0; i < n2; i++){
        uni.insert(arr2[i]);
    }
    return uni.size();
}

bool pair_givenSum(int arr[], int n, int sum){ //O(n) time, O(n) space
    unordered_set<int> s;
    for(int i = 0; i < n; i++){
        if(s.find(sum - arr[i]) != s.end()){
            return true;
        }
        else{
            s.insert(arr[i]);
        }
    }
    return false;
}

bool Subarr_zeroSum(int arr[], int n){ //O(n) time, O(n) aux space
    unordered_set<int> s;
    int pre_sum = 0;
    for(int i = 0; i < n; i++){ //traverse the array
        pre_sum += arr[i]; //find the prefix sum
        if(s.find(pre_sum) != s.end()){ //if the prefix sum is repeating
            return true;
        }
        if(pre_sum == 0){ // or the prefix sum is 0
            return true; //then there exists a subarr with 0 sum
        }
        s.insert(pre_sum);
    }
    return false;
}

bool Subarr_givenSum(int arr[], int n, int sum){ //O(n) time, O(n) space
    unordered_set<int> s;
    int pre_sum = 0;
    for(int i = 0; i < n; i++){
        pre_sum += arr[i];
        if(s.find(pre_sum - sum) != s.end()){
            return true;
        }
        if(pre_sum == sum){
            return true;
        }
        s.insert(pre_sum);
    } 
    return false;
}

int longest_Subarr_givenSum(int arr[], int n, int sum){ //O(n) time, O(n) space
    unordered_map<int, int> m;
    int pre_sum = 0;
    int ans = 0, max_c = 0;
    for(int i = 0; i < n; i++){
        pre_sum += arr[i];
        auto it = m.find(pre_sum - sum);
        if(it != m.end()){
            int x = (it -> second);
            ans = i - x;
            max_c = max(ans, max_c);
        }
        else{
            m[pre_sum] = i;
        }
        if(pre_sum == sum){
            ans = i  + 1;
            max_c = max(ans, max_c);
        }
    }
    return max_c;
}

int longest_Subarr_equal0s_and_1s(bool arr[], int n){ //O(n) time, O(n) space
    unordered_map<int, int> m; 
    int pre_sum = 0, count = 0,max_c = INT_MIN;
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            pre_sum += -1;
        }
        else{
            pre_sum += arr[i];
        }
        if(pre_sum == 0){
            count = i + 1;
            max_c = max(count, max_c);
        }
        auto it = m.find(pre_sum);
        if(it != m.end()){
            count = i - (it -> second);
            max_c = max(count, max_c);
        }
        else{
            m[pre_sum] = i;
        }
    }
    return max_c;
}

int longestCommonSpan_sameSum(bool arr1[], bool arr2[], int n1){ //O(n)time,O(n)space
    int temp[n1];
    for(int i = 0; i < n1; i++){
        temp[i] = arr1[i] - arr2[i];
    }
    return longest_Subarr_givenSum(temp, n1, 0);
}

int longest_consecutiveSubsequence(int arr[], int n){ //O(n)time, O(n)space
    unordered_set<int> s;
    int count = 0;
    int max_c = count;
    for(int i = 0; i < n; i++){
        s.insert(arr[i]);
    }
    for(int i = 0; i < n; i++){
        if(s.find(arr[i] - 1) != s.end() || s.find(arr[i] + 1) != s.end()){
            count++;
            max_c = max(max_c, count);
        }
    }
    return max_c == 0 ? 1 : max_c;
}
 
bool checkElementinMap(unordered_map<int, int>& m, int x){
    if(m.find(x) != m.end()){
        return true;
    }
    return false;
}

void DistinctElementsinEveryWindow(int arr[], int n, int k){ //O(n) time, O(k) space
    int count = 0;
    unordered_map<int, int> m;
    for(int i = 0; i < k; i++){
        m[arr[i]]++;
    }
    cout << m.size() << " ";
    for(int i = k; i < n; i++){
        if(checkElementinMap(m, arr[i - k])){
            m[arr[i - k]]--;
        }
        if(m[arr[i - k]] == 0){
            m.erase(arr[i - k]);
        }
        if(checkElementinMap(m, arr[i])){
            m[arr[i]]++;
        }
        if(!checkElementinMap(m, arr[i])){
            m[arr[i]] = 1;
        }
        cout << m.size() << " ";
    }
}

int main(){
    int arr1[] = {10, 20, 20, 10, 30, 40, 10};
    bool arr2[] = {1, 0, 1, 0, 0, 1};
    bool arr[] = {0, 1, 0, 0, 0, 0};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout << intersection_twoUnsortedArrays(arr1, arr2, n1, n2);
    // cout << union_twoSortedArrays(arr1, arr2, n1, n2);
    // cout << pair_givenSum(arr1, n1, 10);
    // cout << Subarr_zeroSum(arr1, n1);
    // cout << Subarr_givenSum(arr1, n1, 8);
    // cout << longest_Subarr_givenSum(arr1, n1, 8);
    // cout << longest_Subarr_equal0s_and_1s(arr, n);
    // cout << longestCommonSpan_sameSum(arr, arr2, n);
    // cout << longest_consecutiveSubsequence(arr1, n);
    DistinctElementsinEveryWindow(arr1, n1, 4);
    return 0;
}