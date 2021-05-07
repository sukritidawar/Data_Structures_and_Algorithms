#include <bits/stdc++.h>
using namespace std;

void checkKthbitIsSet(int n, int k){
    if(n & (1 << (k - 1)) != 0){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}

int countSetbits_naive(int n){ //theta(total bits in n)
    int res = 0;
    while(n > 0){
        if(n & 1 == 1){
            res++;
        }
        n = n >> 1;
    }
    return res;
}

int countsetbits_BrionKerningamAlgo(int n){
    int res = 0;
    while(n > 0){
        n = (n &(n - 1));
        res++;
    }
    return res;
}

int main(){
    // checkKthbitIsSet(5, 3);
    // cout << countSetbits_naive(5);
    cout << countsetbits_BrionKerningamAlgo(40);
    return 0;
}