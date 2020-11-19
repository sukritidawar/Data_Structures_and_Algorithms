#include<bits/stdc++.h>
using namespace std;

int binarysearch(int arr[], int n, int ele){
    int low = 0, high = n - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(ele == arr[mid]){
            return mid;
        }
        else if(ele < arr[mid]){
            high = mid - 1;
        }else{
            low = mid + 1;
        } 
    }
    return -1;
}

int recursive_binarysearch(int arr[], int low, int high, int ele){
    int mid = (low + high) / 2;
    if(low > high){
        return -1;
    }
    if(arr[mid] == ele){
        return mid;
    }else if(ele < arr[mid]){
        return recursive_binarysearch(arr, low, mid - 1, ele);
    }else{
        return recursive_binarysearch(arr, mid + 1, high, ele);
    }
}

int main(){
    int arr[] = {10, 15, 20, 25, 30, 35};
    // cout << binarysearch(arr, 2, 5);
    cout << recursive_binarysearch(arr, 0, 5, 30);
    return 0;
}