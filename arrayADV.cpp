#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

void leftrotatebyd(vector<int> &arr, int d){ //theta(n) time, theta(d) space
    int n = arr.size();
    d = d % n;
    vector<int> temp;
    for(int i = 0; i < d; i++){
        temp.push_back(arr[i]);
    }
    for(int i = d; i < n; i++){
        arr[i - d] = arr[i];
    }
    for(int i = 0; i < d; i++){
        arr[n - d + i] = temp[i];
    }
}

//Left rotate by d efficient
void reverse(vector<int> &arr, int low, int high){
    while(low < high){
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}
void leftRotateD(vector<int> &arr, int n, int d){ //theta n time, theta 1 space
    reverse(arr, 0, d - 1); //first d elements
    reverse(arr, d, n - 1); //remaining n-d elements
    reverse(arr, 0, n - 1); //whole array
}

void leaders_in_Arr(int arr[], int n){  //theta n time, theta 1 space
    int curr_leader = arr[n - 1];
    cout << curr_leader << " ";
    for(int i = n - 2; i >= 0; i--){
        if(curr_leader < arr[i]){
            curr_leader = arr[i];
            cout << curr_leader << " ";
        }
    }
}

int maximum_difference(int arr[], int n){ //theta n time, theta 1 space
    int diff = arr[1] - arr[0], minval = arr[0];
    for(int j = 1; j < n; j++){
        diff = max(diff, arr[j] - minval);
        minval = min(arr[j], minval);
    }
    return diff;
}

//Stock buy and sell problem
int maxProfit_naive(int price[], int start, int end){
    if(end <= start){
        return 0;
    }
    int profit = 0;
    for(int i = start; i < end; i++){
        for(int j = i + 1; j <= end; j++){
            if(price[j] > price[i]){
                int curr_profit = price[j] - price[i] + maxProfit_naive(price, start, i - 1) + maxProfit_naive(price, j + 1, end);
                profit = max(profit, curr_profit);
            }
        }
    }
    return profit;
}

int maxProfit_efficient(int price[], int n){ //theta n time, theta 1 space
    int profit = 0;
    for(int i = 1; i < n; i++){
        if(price[i] > price[i - 1]){
            profit += (price[i] - price[i - 1]);
        }
    }
    return profit;
}
 
//Trappping rain water problem
int getWater_naive(int arr[], int n){ //theta(n2)
    int res = 0;
    for(int i = 1; i < n - 1; i++){ //traversing through the middle bars
        int lmax = arr[i];
        for(int j = 0; j < i; j++){
            lmax = max(lmax, arr[j]);
        }
        int rmax = arr[i];
        for(int j = i + 1; j < n; j++){
            rmax = max(rmax, arr[j]);
        }
        res += (min(lmax, rmax) - arr[i]);
    }
    return res;
}

int getWater_efficient(int arr[], int n){ //theta n time, theta n aux space
    int res = 0;
    int lmax[n], rmax[n];
    lmax[0] = arr[0];
    for(int i = 1; i < n; i++){
        lmax[i] = max(arr[i], lmax[i - 1]);
    }
    rmax[n - 1] = arr[n - 1];
    for(int i = n - 2; i >= 0; i--){
        rmax[i] = max(arr[i], rmax[i + 1]);
    }
    for(int i = 1; i < n - 1; i++){
        res += min(lmax[i], rmax[i]) - arr[i];
    }
    return res;
}

//Maximum consecutive 1s in a binary array
int max_1s(int arr[], int n){ //theta n time, theta 1 aux space
    int max_count = 0, count = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            count = 0;
        }
        if(arr[i] == 1){
            count++;
        }
        max_count = max(count, max_count);
    }
    return max_count;
}

//Maximum sum subarray/ Kadane's algorithm
int maxSum_subarray(int arr[], int n){
    int max_curr, max_global;
    max_curr = max_global = arr[0];
    for(int i = 1; i < n; i++){
        max_curr = max(max_curr + arr[i], arr[i]);
        max_global = max(max_curr, max_global);
    } 
    return max_global;
}

int maxlength_evenoddSubarr(int arr[], int n){
    int curr_length, max_length;
    curr_length = 1;
    max_length = 0;
    bool flag = 1;
    if(arr[0] % 2 == 0){
        flag = 0;
    }
    for(int i = 1; i < n; i++){
        if((arr[i] % 2 == 0 && flag == 1) || (arr[i] % 2 != 0 && flag == 0)){
            curr_length++;
        }
        if(arr[i] % 2 == 0){
            flag = 0;
        }
        else if(arr[i] % 2 != 0){
            flag = 1;
        }
        max_length = max(max_length, curr_length);
    }
    return max_length;
}

int max_circularSubarr_sum(int arr[], int n){ //O(n) time, O(1) aux space
    int max_curr, max_global;
    max_curr = max_global = arr[0];
    int normal_max, circular_max;
    for(int i = 1; i < n; i++){ //calculating max subarr sum
        max_curr = max(max_curr + arr[i], max_curr);
        max_global = max(max_curr, max_global);
    }
    normal_max = max_global;
    int min_global, min_curr, overall_sum;
    overall_sum = 0;
    min_global = min_curr = arr[0];
    for(int i = 0; i < n; i++){ //calculating overall sum
        overall_sum += arr[i]; 
    }
    for(int i = 1; i < n; i++){ //calculating min subarr sum
        min_curr = min(min_curr + arr[i], min_curr);
        min_global = min(min_curr, min_global);
    }
    circular_max = overall_sum - min_global; //calculating circular max
    return max(circular_max, normal_max);
}

int mostRepeating_element(int arr[], int n){
    unordered_map<int, int> freq;
    unordered_map<int, int> index;
    for(int i = 0; i < n; i++){
        freq[arr[i]]++;
        index[arr[i]] = i;
    }
    int max_ = 0;
    int y;
    for(auto x : freq){
        if(x.second > max_){
            max_ = x.second;
            y = x.first;
        }
    }
    auto it = index.find(y);
    if(it != index.end()){
        return it -> second;
    }
    return -1;
}

int majority_element(int arr[], int n){
    int res = 0, count = 1;
    for(int i = 1; i < n; i++){ //To find a candidate for majority element
        if(arr[res] == arr[i]){
            count++;
        }
        else{
            count--;
        }
        if(count == 0){
            res = i;
            count = 1;
        }
    }
    count = 0;
    for(int i = 0; i < n; i++){ //To check if the candidate is actually a majority
        if(arr[res] == arr[i]){
            count++;
        }
    }
    if(count <= (n / 2)){
        res = -1;
    }
    return res;
}

void printGroups(bool arr[], int n){//one traversal, O(n) time, O(1) aux space
    for(int i = 1; i < n; i++){
        if(arr[i] != arr[i - 1]){
            if(arr[i] != arr[0]){
                cout << "From " << i << "to ";
            }
            else{
                cout << i - 1 << endl;
            }
        }
    }
    if(arr[n - 1] != arr[0]){ //If the last element is at the end of a group and is supposed to be flipped
        cout << n - 1 << endl;
    }
}

int window_sliding_technique(int arr[], int n, int k){ //O(n) time
    int curr_sum = 0;
    for(int i = 0; i < k; i++){
        curr_sum += arr[i];
    }
    int max_sum = curr_sum;
    for(int i = k; i < n; i++){
        curr_sum += (arr[i] - arr[i - k]);
        max_sum = max(curr_sum, max_sum);
    }
    return max_sum;
}

//Smallest subarr with given sum
int findMinSubArray(int S, const vector<int>& arr) {
    int sum = arr[0];
    int ans = numeric_limits<int>::max();
    int j = 0;
    for(int i = 1; i < arr.size(); i++){
      sum += arr[i];
      while(sum >= S){
         ans = min(ans, i - j + 1);
         sum = sum - arr[j];
         j++;
      }
    }
    return ans == numeric_limits<int>::max() ? 0 : ans;
}

int prefix_sum(int arr[], int n, int l, int r){
    int cum_sum[n];
    int init_sum = 0;
    for(int i = 0; i < n; i++){
        cum_sum[i] = init_sum + arr[i];
        init_sum = cum_sum[i];
    }
    if(l != 0){
        return cum_sum[r];
    }
    return cum_sum[r] - cum_sum[l - 1];
}

bool equilibrium_point(int arr[], int n){
    int overall_sum = 0;
    for(int i = 0; i < n; i++){
        overall_sum += arr[i];
    }
    int l_sum = 0, r_sum = 0;
    for(int i = 0; i < n; i++){
        r_sum = overall_sum - arr[i];
        if(l_sum == r_sum){
            return true;
        }
        l_sum += arr[i];
        overall_sum -= arr[i];
    }
    return false;
}

int maximumAppearingelement_Nranges(int L[], int R[], int n){
    vector<int> arr(1000); // we made a vector because we want elements to be zero initially
    for(int i = 0; i < n; i++){
        arr[L[i]]++;
        arr[R[i] + 1]--; //to mark the ending of a range
    }
    int max_ = arr[0], res = 0;
    for(int i = 1; i < 1000; i++){
        arr[i] += arr[i - 1]; 
        if(max_ > arr[i]){
            max_ = arr[i];
            res = i;
        }
    }
    return res;
}

void segregatePosveAndNegve(int arr[], int n){
    if(n == 0){return;}
    int p = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] > 0){
            p++;
            swap(arr[i], arr[p]);
        }
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

int main(int argc, char** argv){
    int arr1[] = {4, 2, 2, -3, 5, -11, 10, 9, -8, -7};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    vector<int> arr;
    for(int i = 0; i < n; i++){
        arr.push_back(arr1[i]);
    }
    // leftrotatebyd(arr, 2);
    // leftRotateD(arr, n, 2);
    // cout << maximum_difference(arr1, n);
    // leaders_in_Arr(arr1, n);
    // cout << maxProfit_naive(arr1, 0, n - 1);
    // cout << maxProfit_efficient(arr1, n);
    // cout << getWater_naive(arr1, n);
    // cout << getWater_efficient(arr1, n);
    // cout << max_1s(arr1, n);
    // cout << maxSum_subarray(arr1, n);
    // cout << maxlength_evenoddSubarr(arr1, n);
    // cout << max_circularSubarr_sum(arr1, n);
    // cout << mostRepeating_element(arr1, n);
    // cout << majority_element(arr1, n);
    // printGroups(arr1, n);
    // cout << window_sliding_technique(arr1, n, 3);
    // cout << prefix_sum(arr1, n, 0, 3);
    int L[] = {1, 2, 3};
    int R[] = {3, 5, 7};
    // cout << maximumAppearingelement_Nranges(L, R, 3);
    segregatePosveAndNegve(arr1, n);
    // cout << equilibrium_point(arr1, n);
    // for(int x : arr){
    //     cout << x << " ";
    // }
    return 0;
}