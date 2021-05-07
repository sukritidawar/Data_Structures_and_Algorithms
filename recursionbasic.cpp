#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    if(n == 0){
        return 1;
    }
    else{
        return n * fact(n - 1);
    }
}

int nthFiboNo(int n){
    if(n == 0 || n == 1){
        return n;
    }else{
        return nthFiboNo(n - 1) + nthFiboNo(n - 2);
    }
}

float nCr(int n, int r){
    if(r == 0 || r == n){
        return 1.0;
    }
    float ans = nCr(n, r - 1);
    return (n - r + 1)*ans/r;
}

void printNto1(int n){
    if(n == 0){
        return;
    }
    cout << n << " ";
    printNto1(n - 1);
}

void print1toN(int n){
    if(n == 0){
        return;
    }
    print1toN(n - 1);
    cout << n << " ";
}

bool isPalllindrome(string str, int start, int end){
    if(start >= end){
        return true;
    }
    if(str[start] != str[end]){
        return false;
    }else{
        return isPalllindrome(str, start + 1, end - 1);
    }
}

int sumofdigits(int num, int sum = 0){
    if(num == 0){
        return sum;
    }
    return sumofdigits(num/10, sum + num%10);
}

int maxCuts(int n, int a, int b, int c){
    if(n < 0){
        return -1;
    }
    if(n == 0){
        return 0;
    }
    int res = max(maxCuts(n - a, a, b, c), max(maxCuts(n - b, a, b, c), maxCuts(n - c, a, b, c)));
    if(res == -1) return -1;  //for handling cases like 5,2,4,6 when there is no piece possible it should return -1
    return res + 1;
}

void printSubsequences(string str, string curr="", int idx = 0){
    if(idx == str.size()){
        cout << curr << " ";
        return; 
    }
    printSubsequences(str, curr, idx + 1);
    printSubsequences(str, curr + str[idx], idx + 1);
}

void TOH(int n, char A, char B, char C){  //source, helper, dest
    if(n == 1){
        cout << "Move disc 1 from " << A << " to " << C << endl;
        return;
    }
    TOH(n - 1, A, C, B);
    cout << "Move disc " << n << " from " << A << " to " << C << endl;
    TOH(n - 1, B, A, C);
}

int Josephus_problem(int n, int k){
    if(n == 1){
        return 0;
    }
    int x = Josephus_problem(n - 1, k);
    int y = (x + k) % n;
    return y;
}

int atoi_recursive(string str, int n){
    if(n == 1){
        return str[0] - '0';
    }
    return 10*atoi_recursive(str, n - 1) + str[n - 1] - '0';
}

//Edit distance
int editDist(string s1, string s2, int m, int n){
    if(m == 0){
        return n;
    }
    if(n == 0){
        return m;
    }
    if(s1[m - 1] == s2[n - 1]){
        return editDist(s1, s2, m - 1, n - 1);
    }
    else{
        return 1 + min(editDist(s1, s2, m - 1, n), min(editDist(s1, s2, m, n - 1), editDist(s1, s2, m - 1, n - 1)));
    }
}

int main(){
    // cout << fact(5) << " ";
    // cout << nthFiboNo(4);
    // printNto1(5);
    // print1toN(5);
    // cout << isPalllindrome("geek", 0, 4);
    // cout << sumofdigits(2);
    // cout << maxCuts(5, 2, 4, 6);
    // printSubsequences("ABC");
    // TOH(3, 'A', 'B', 'C');
    // cout << nCr(5, 5);
    // cout << Josephus_problem(5, 3);
    // cout << atoi_recursive("113", 3);
    cout << editDist("CAT", "CUT", 3, 3);
    return 0;
}