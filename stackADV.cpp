#include <bits/stdc++.h>
using namespace std;

class TwoStacks{
    int *arr;
    int cap, top1, top2;
    TwoStacks(int n){
        cap = n;
        arr = new int[n];
        int top1 = -1;
        int top2 = cap;
    }
    void push1(int x){
        if(top1 < top2 - 1){
            top1++;
            arr[top1] = x;
        }
    }
    void push2(int x){
        if(top1 < top2 - 1){
            top2--;
            arr[top2] = x;
        }
    }
    int pop1(){
        if(top1 >= 0){
            int x = arr[top1];
            top1--;
            return x;
        }
        else{
            exit(1);
        }
    }
    int pop2(){
        if(top2 < cap){
            int x = arr[top2];
            top2++;
            return x;
        }
        else{
            exit(1);
        }
    }
    int size1(){
        return top1;
    }
    int size2(){
        return cap - top2;
    }
};

struct kStacks{
    int *arr, *top, *next;
    int k, freeTop, cap;
    kStacks(int k1, int n){
        k = k1, cap = n;
        arr = new int[n];
        top = new int[k];
        next = new int[n];
        for(int i = 0; i < n; i++){
            top[i] = -1;
        }
        freeTop = 0;
        for(int i = 0; i < cap - 1; i++){
            next[i] = i + 1;
        }
        next[cap - 1] = -1;
    }
    void push(int x, int sn){ //sn is stack number
        int i = freeTop;
        freeTop = next[i];
        next[i] = top[sn];
        top[sn] = i;
        arr[i] = x;
    }
    int pop(int sn){
        int i = top[sn];
        top[sn] = next[i];
        next[i] = freeTop;
        freeTop = i;
        return arr[i];
    }
};

void StockSpan(int arr[], int n){ //O(n) time, O(n) space
    stack<int> s;
    s.push(0); //Push indices to stack
    cout << "1 ";
    for(int i = 1; i < n; i++){
        while(s.empty() == false && arr[s.top()] <= arr[i]){
            s.pop();
        }
        int span = s.empty() ? i + 1 : i - s.top();
        cout << span << " ";
        s.push(i);
    }
}

void PreviousGreaterElement(int arr[], int n){ //O(n) time, because we're inserting and popping items only once from the stack, O(n) space
    stack<int> s;
    s.push(arr[0]);
    cout << "-1 ";
    for(int i = 1; i < n; i++){
        while(s.empty() == false && arr[i] >= s.top()){
            s.pop();
        }
        int prevGreater = s.empty() ? -1 : s.top();
        cout << prevGreater << " ";
        s.push(arr[i]);
    }
}

int main(int argc, char** argv){
    int arr[] = {15,10,18,12,4,6,2,8};
    int n = sizeof(arr) / sizeof(arr[0]);
    // StockSpan(arr, n);
    PreviousGreaterElement(arr, n);
    return 0;
}