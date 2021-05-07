#include<bits/stdc++.h>
using namespace std;

//Min coins for a particular amount
int minCoins(int coins[], int n, int amount){
    sort(coins, coins + n, greater<int>());
    int res = 0;
    for(int i = 0; i < n; i++){
        if(coins[i] <= amount){
            int c = floor(amount/coins[i]);
            res += c;
            amount -= c*coins[i];
        }
        if(amount == 0){
            break;
        }
    }
    return res;
}

//Activity Selection Problem
void printMaxActivities(int s[], int f[], int n) 
{ 
    int i, j; 
    i = 0; 
    cout << i; 
  
    for (j = 1; j < n; j++) 
    { 
      if (s[j] >= f[i]) 
      { 
          cout << j; 
          i = j; 
      } 
    } 
} 

int main(){
    int arr[] = {5, 2, 10, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minCoins(arr, n, 52);
    return 0;
}