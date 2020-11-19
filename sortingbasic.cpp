#include <bits/stdc++.h>
using namespace std;

int* bubblesort(int arr[], int n){    //theta(n2)
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){   //because the last i elements are already sorted
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return arr;
}

int* bubblesortoptimised(int arr[], int n){  //linear time in some cases, or O(n2)
    bool swapped;
    for(int i = 0; i < n - 1; i++){
        swapped = false;
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if(swapped == false){
            return arr;
        }
    }
    return arr;
}

int* selectionsort(int arr[], int n){  //theta(n2)
    for (int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[i]){
                swap(arr[i], arr[j]);
            }
        }
    }
    return arr;
}

int* insertionsort(int arr[], int n){  //best case: linear time(already sorted array)
    for(int i = 1; i < n; i++){        //worst case: theta(n2) (reverse sorted array)
        int key = arr[i];              //use insertion sort for small sized arrays
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return arr;
}

void mergetwoSortedArrays(int a[], int b[], int m, int n){  //O(m + n) time complexity , aux space:O(m+n)//if we store it in another array
    int i = 0, j = 0;
    while(i < m && j < n){         //will work when both arrays has elements, but won't work when
        if(a[i] > b[j]){           //one array has no elements, so we have to print the rest of the 
            cout << b[j] << " ";   //elements (leftover)
            j++;
        }else{
            cout << a[i] << " ";
            i++;
        }
    }
    while(i < m){
        cout << a[i] << " ";
        i++;
    }
    while(j < n){
        cout << b[j] << " ";
        j++; 
    }
}

int* merge(int arr[], int l, int m, int h){ //time complexity: O(n), aux space: O(n)
    int size_left = m - l + 1, size_right = h - m;
    int left[size_left], right[size_right];
    for(int i = 0; i < size_left; i++){
        left[i] = arr[i];
    } 
    for(int j = 0; j < size_right; j++){
        right[j] = arr[m + j + 1];
    }
    int i = 0, j =0, k = l;
    while(i < size_left && j < size_right){
        if(left[i] <= right[j]){   //<= sign very imp for stability in merge sort, because if the ele is first in left arr it should be first in final arr also
            arr[k++] = left[i++];  //arr[k++] can also be written as arr[k] and in next line k++
        }else{
            arr[k++] = right[j++];
        }
    }
    while(i < size_left){
        arr[k++] = left[i++];
    }
    while(j < size_right){
        arr[k++] = right[j++];
    }
    return arr;
}

int* mergeSort(int arr[], int l, int r){    //To check that there are atleast two elements in arr
    int *p;
    if(r > l){
        int m = l + (r - l)/2; //same as (r+l)/2, but to prevent overflow, we used this 
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        p = merge(arr, l, m, r);
    }  
    return p; 
}

int partition_naive(int arr[], int l, int h, int p){ // time complexity: O(n) with three traversals
    int temp[h - l + 1], idx = 0;                     // aux space: O(n)
    for(int i = l; i <= h; i++){
        if(arr[i] <= arr[p]){
            temp[idx] = arr[i];
            idx++;
        }
    }
    for(int i = l; i <= h; i++){
        if(arr[i] > arr[p]){
            temp[idx] = arr[i];
            idx++;
        } 
    }
    for(int i = l; i <= h; i++){
        arr[i] = temp[i - l];
    }
    return idx;
}

int lomieto_partition(int arr[], int l, int h){ //one traversal, O(1) extra space
    int i = l - 1, pivot = arr[h];
    for(int j = l; j <= h - 1; j++){
        if(arr[i] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return i + 1;
}

int hoare_partition(int arr[], int l, int h){ //O(1) space, one traversal, works better than lomieto partition
    int i = l - 1, j = h + 1;
    int pivot = arr[l];
    while(true){
        do{
            i++;
        }while(arr[i] < pivot);
        do{
            j--;
        }while(arr[j] > pivot);
        if(i >= j){
            return j;
        }
        swap(arr[i], arr[j]);
    }
    return j;
}

int* quickSort_lomieto(int arr[], int l, int h){
    if(l < h){
        int p = lomieto_partition(arr, l, h);
        quickSort_lomieto(arr, l, p - 1);
        quickSort_lomieto(arr, l, p + 1);
    }
    return arr;
}

int* quicksort_hoare(int arr[], int l, int h){
    if(l < h){
        int p = hoare_partition(arr, l, h);
        quicksort_hoare(arr, l, p); //here it is p and not p-1 because hoare's partition does not fix any element at its correct position
        quicksort_hoare(arr, p + 1, h);
    }
    return arr;
}

void maxHeapify(int arr[], int n, int i){
    int largest = i, left = 2*i+1, right = 2*i+2;
    if(left < n && arr[largest] < arr[left]) largest = left;
    if(right < n && arr[largest] < arr[right]) largest = right;
    if(largest != i){
        swap(arr[largest], arr[i]);
        maxHeapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n){   //O(n)
    for(int i = (n - 2)/2; i >= 0; i--){
        maxHeapify(arr, n, i);
    }
}

int main(){
    int arr[] = {2, 10, 8, 7};
    // int *p = bubblesort(arr, 4);
    // int *p = bubblesortoptimised(arr, 4);
    // int *p = selectionsort(arr, 4);
    // int *p = insertionsort(arr, 4);
    // int a[] = {10, 15, 20, 40};
    // int b[] = {5, 6, 6, 10, 15};
    // mergetwoSortedArrays(a, b, 4, 5);
    // int *p = mergeSort(arr, 0, 3);
    // int p = hoare_partition(arr, 0, 3);
    // int *p = partition_naive(arr, 0, 3, 3);
    int *p = quicksort_hoare(arr, 0, 3);
    for(int i = 0; i < 4; i++){
        cout << p[i] << " ";
    }
    cout << endl;
    return 0;
}