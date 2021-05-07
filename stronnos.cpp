#include <bits/stdc++.h>

using namespace std;

int factorial(int n){
    int fac = 1;
    for (int i = 1; i <= n; i++){
        fac *= i;
    }
    return fac;
}

vector<int> generatestrongnos(){
    vector<int> strongnumbers;
    
    for (int i = 1; i < 10000; i++){
        int temp = i;
        int r, sum = 0;
        while (temp > 0){
            r = temp % 10;
            sum += factorial(r);
            temp /= 10;
        }
        if (sum == i){
            strongnumbers.push_back(i);
        }
    }
    
    return strongnumbers;
}

int main(int argc, char* argv[]){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    vector<int> strongnumbers = generatestrongnos();
    for (int x: strongnumbers){
        cout << x <<endl;
    }
    //cout<<"hi";
    return 0;
}
