#include <bits/stdc++.h>
using namespace std;

void intersection_SortedArrays(int arr1[], int arr2[], int n1, int n2){ // O(n1 + n2) time, O(1) space
    int i = 0;
    int j = 0;
    while(i < n1 && j < n2){
        if(i > 0 && arr1[i - 1] == arr1[i]){
            i++;
            continue;
        }
        if(arr1[i] == arr2[j]){
            cout << arr1[i] << " ";
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j]){
            i++;
        }
        else{
            j++;
        }
    }
}

int countAndMerge(int arr[], int l, int m, int r){ //O(nlogn) time, O(n) space
    int n1 = m - l + 1, n2 = r - m;
    int left[n1], right[n2];
    for(int i = 0; i < n1; i++){
        left[i] = arr[l + i];
    }
    for(int i = 0; i < n2; i++){
        right[i] = arr[m + 1 + i];
    }
    int res = 0, i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
            res += n1 - i;
        }
        k++;
    }
    while(i < n1){
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = right[j];
        j++;
        k++;
    }
    return res;
}

int countInv(int arr[], int l, int r){
    int res = 0;
    if(l < r){
        int m = (l) + (r - l)/2;
        res += countInv(arr, l, m); //counting inversions in left half
        res += countInv(arr, m + 1, r); //counting inversions in right half 
        res += countAndMerge(arr, l, m, r); //counting inversions when we merge
    }
    return res;
}

int minDiff(int arr[], int n, int m){
    if(m > n){
        return -1;
    }
    sort(arr, arr + n);
    int res = arr[m - 1] - arr[0];
    for(int i = 1; i + m - 1 < n; i++){
        res = min(res, arr[i + m - 1] - arr[i]);
    }
    return res;
}

void segregatenegpos(int arr[], int n){
    int i = -1;
    int j = n;
    while(true){
        do{
            i++;
        }while(arr[i] <= 0);
        do{
            j--;
        }while(arr[j] >= 0);
        if(i >= j){
            return;
        }
        swap(arr[i], arr[j]);
    }
}

int main(int argc, char** argv){
    int arr1[] = {7,3,2,4,9,12,56};
    int arr2[] = {5, 10,10,15,30};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    // intersection_SortedArrays(arr1, arr2, n1, n2);
    // cout << countInv(arr1, 0, n1 - 1);
    cout << minDiff(arr1, n1, 3);
    return 0;
}