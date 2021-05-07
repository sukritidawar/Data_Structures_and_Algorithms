#include <bits/stdc++.h>
using namespace std;

//Fibo number: memoization
int fibo_mem(int n, int memo[]){ // theta(n) time, theta(n) aux space
    if(memo[n] == -1){
        int res;
        if(n == 0 || n == 1){
            res = n;
        }
        else{
            res = fibo_mem(n - 1, memo) + fibo_mem(n - 2, memo);
        }
        memo[n] = res;
    }
    return memo[n];
}

//Fibo number: tabulation
int fibo_tab(int n){ //theta(n) time, theta(n) aux space, no recursion calls
    int fibo[n + 1];
    fibo[0] = 0, fibo[1] = 1;
    for(int i = 2; i <= n; i++){
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    return fibo[n];
}
 
//Longest Common Subsequence : Memoization
int lcs(string s1, string s2, int m, int n, int memo[6][6]){ //theta(mn) time(better than naive recursion method(2^n time(exponential)))
    if(memo[m][n] != -1){
        return memo[m][n];
    }
    if(m == 0 || n == 0){
        memo[m][n] = 0;
    }
    else{
        if(s1[m - 1] == s2[n - 1]){
            memo[m][n] = 1 + lcs(s1, s2, m - 1, n - 1, memo);
        }
        else{
            memo[m][n] = max(lcs(s1, s2, m - 1, n, memo), lcs(s1, s2, m, n - 1, memo));
        }
    }
    return memo[m][n];
}

//Longest Common Subsequence: Tabulation
int lcs_tab(string s1, string s2){//theta(m*n) time, theta(m*n) aux space
    int m = s1.size(), n = s2.size();
    int dp[m + 1][n + 1];
    for(int i = 0; i <= m; i++){
        dp[i][0] = 0;
    }
    for(int j = 0; j <= n; j++){
        dp[0][j] = 0;
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

//Coin Change Combination
int coinChange_combi(int coins[], int n, int sum){
    int dp[sum + 1];
    for(int i = 0; i <= sum; i++){
        dp[i] = 0;
    }
    dp[0] = 1; //because we dont do anything to pay 0 sum, hence one way
    for(int i = 0; i < n; i++){ //coin loop
        for(int j = coins[i]; j <= sum; j++){ //dp arr loop
            dp[j] += dp[j - coins[i]];
        }
    }
    return dp[sum];
}

//Coin Change Permutation
int coinChang_per(int coins[], int n, int sum){
    int dp[sum + 1];
    for(int i = 0; i <= sum; i++){
        dp[i] = 0;
    }
    dp[0] = 1;
    for(int i = 1; i <= sum; i++){ //dp loop
        for(int j = 0; j < n; j++){ //coins loop
            if(i < coins[j]){
                dp[i] += 0;
            }
            else{
                dp[i] = dp[i] + dp[i - coins[j]];
            }
        }
    }
    return dp[sum];
}

//Climbing Stairs with 1, 2, 3 steps
int climb_123(int steps[], int n, int target){
    int dp[target + 1];
    for(int i = 0; i <= target; i++){ //not necessary with higher versions of cpp
        dp[i] = 0;
    }
    dp[0] = 1;
    for(int i = 1; i <= target; i++){ 
        if(i == 1){
            dp[i] = dp[i - 1];
        } 
        else if(i == 2){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        else{
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
    }
    return dp[target];
}

//Climbing Stairs with variable jumps
int climb_varJumps(int jumps[], int n, int target){
    int dp[target + 1];
    for(int i = 0; i <= target; i++){
        dp[i] = 0;
    }
    dp[target] = 1;
    for(int i = target - 1; i >= 0; i--){
        for(int j = 1; j <= jumps[i]; j++){
            if(i + j <= target){
                dp[i] = dp[i] + dp[i + j];
            }
        }
    }
    return dp[0];
}

//ClimbStairs_minMoves
int climbStairs_minMoves(int jumps[], int n, int target){
    int dp[target + 1];
    for(int i = 0; i <= target; i++){
        dp[i] = 0;
    }
    dp[target] = 1;
    int min_ = dp[target];
    for(int i = target - 1; i >= 0; i--){
        if(i + jumps[i] >= target){
            dp[i] = 1;
        }
        else{
            dp[i] = dp[i + jumps[i]] + 1;
        }
    }
    return dp[0];
}

//Target Sum Subset
bool targetSum(int arr[], int n, int sum){
    int dp[n + 1][sum + 1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            dp[i][j] = 0;
        }
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            if(i == 0 && j == 0){
                dp[i][j] = 1;
            }
            else if(i == 0){
                dp[i][j] = 0;
            }
            else if(j == 0){
                dp[i][j] = 1;
            }
            else{
                if(dp[i - 1][j] == 1){
                    dp[i][j] = 1;
                }
                else{
                    if(j >= arr[i - 1]){
                        if(dp[i - 1][j - arr[i - 1]] == 1){
                            dp[i][j] = 1;
                        }
                    }
                    else{
                        dp[i][j] = 0;
                    }
                }
            }
        }
    }
    return dp[n][sum];
}

//Edit Distance: Tabulation
int editDist(string s1, string s2, int m, int n){ //Time complexity:theta(m*n), Space complexity:theta(m*n)
    int dp[m + 1][n + 1];
    for(int i = 0; i <= m; i++){
        dp[i][0] = i;
    }
    for(int j = 0; j <= n; j++){
        dp[0][j] = j;
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
            }
        }
    }
    return dp[m][n];
}

//Longest Increasing Subsequence(theta(n2) solution using dp)
int longest_inc_subsequence(int arr[], int n){
    int lis[n];
    lis[0] = 1;
    for(int i = 1; i < n; i++){
        lis[i] = 1;
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]){
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    int res = 1;
    for(int i = 0; i < n; i++){
        res = max(res, lis[i]);
    }
    return res;
}

//Longest Increasing Subsequence(O(nlogn) solution using binary search)
int ceilIndex(vector<int> &tail, int x){
    int l = 0;
    int r = tail.size() - 1;
    while(r > l){
        int m = l + (r - l)/2;
        if(tail[m] >= x){
            r = m;
        }
        else{
            l = m + 1;
        }
    }
    return r;
}
int longest_inc_subsequence_binarySearch(int arr[], int n){ //O(nlogn) time, O(n) aux space
    vector<int> tail;
    int len = 1;
    tail.push_back(arr[0]);
    for(int i = 1; i < n; i++){
        if(arr[i] > tail.back()){
            tail.push_back(arr[i]);
            len++;
        }
        else{
            int c = ceilIndex(tail, arr[i]);
            tail[c] = arr[i];
        }
    }
    return len;
}

//Maximum Cuts
int max_cuts(int n, int a, int b, int c){ //theta(n) time, theta(n) aux space
    int dp[n + 1];
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = -1;
        if(i - a >= 0){
            dp[i] = max(dp[i], dp[i - a]);
        }
        if(i - b >= 0){
            dp[i] = max(dp[i], dp[i - b]);
        }
        if(i - c >= 0){
            dp[i] = max(dp[i], dp[i - c]);
        }
        if(dp[i] != -1){
            dp[i]++;
        }
    }
    return dp[n];
}

//Minimum coins to make a value
int min_coins(int coins[], int n, int val){ //theta(n*val) time, theta(val) aux space
    int dp[val + 1];
    dp[0] = 0;
    for(int i = 1; i <= val; i++){
        dp[i] = INT_MAX;
    }
    for(int i = 1; i <= val; i++){
        for(int j = 0; j < n; j++){
            if(i - coins[j] >= 0){
                int sub_res = dp[i - coins[j]];
                if(sub_res != INT_MAX){
                    dp[i] = min(dp[i], sub_res + 1);   
                }
            }
        }
    }
    return dp[val];
}

//Minimum jumps to reach end
int minJumps(int arr[], int n){
    int dp[n];
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = INT_MAX;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            if(arr[j] + j >= i){
                if(dp[j] != INT_MAX){
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
    }
    return dp[n - 1];
}

//0-1 Knapsack Problem
int KnapSack(int W, int wt[], int val[], int n){ //theta(n*W) time - sudo polynomial soln, theta(n*W) aux space
    int dp[n + 1][W + 1];
    for(int i = 0; i <= W; i++){
        dp[0][i] = 0;
    }
    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= W; j++){
            if(wt[i - 1] > j){
                dp[i][j] = dp[i][j - 1];
            }
            else{
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
        }
    }
    return dp[n][W];
}

int main(){
    int n = 5;
    int memo[n + 1];
    for(int i = 0; i <= n; i++){
        memo[i] = -1;
    }
    // cout << fibo_mem(n, memo);
    // cout << fibo_tab(n);
    int memoi[6][6];
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            memoi[i][j] = -1;
        }
    }
    // cout << lcs("AXYZ", "BAZ", memoi);
    // cout << lcs_tab("AXYZ", "BAZ");
    // int coins[] = {4, 2, 7, 1, 3};
    // cout << coinChange_combi(coins, 3, 7);
    // cout << coinChang_per(coins, 3, 7);
    int steps[] = {1, 2, 3};
    // cout << climb_123(steps, 3, 6);
    int jumps[] = {4, 2, 0, 2, 2, 3};
    // cout << climb_varJumps(jumps, 6, 6); 
    // cout << climb_varJumps(jumps, 6, 6);
    // cout << targetSum(coins, 5, 10);
    // cout << editDist("CAT", "CUT", 3, 3);
    int coins[] = {3, 4, 1};
    cout << min_coins(coins, 3, 5);
    return 0;
}