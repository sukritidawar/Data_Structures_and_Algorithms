#include <bits/stdc++.h>
using namespace std;

int index_firstOccurence(int arr[], int n, int x){ //O(logn) time
    int low = 0; 
    int high = n - 1;
    int ans;
    while(low <= high){
        int mid = (low) + (high - low)/2;
        if(arr[mid] == x){
            if(arr[mid - 1] == x && mid != 0){
                high = mid - 1;
            }
            else{
                return mid;
            }
        }
        else if(arr[mid] < x){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int index_lastOccurence(int arr[], int n, int x){ //O(logn) time
    int low = 0;
    int high = n - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] < x){
            low = mid + 1;
        }
        else if(arr[mid] > x){
            high = mid - 1;
        }
        else{
            if(mid == n - 1 || (arr[mid + 1] != x)){
                return mid;
            }
            else{
                low = mid + 1;
            }
        }
    }
    return -1;
}

int countOccurences_sortedArr(int arr[], int n, int x){ //O(logn) time
    int first = index_firstOccurence(arr, n, x);
    if(first == -1){
        return 0;
    }
    else{
        return index_lastOccurence(arr, n, x) - first + 1;
    }
}

int countOccurences_binaryArr(bool arr[], int n){ //O(logn) time, should be sorted arr
    int low = 0;
    int high = n - 1;
    int mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(arr[mid] == 0){
            low = mid + 1;
        }
        else{
            if(mid == 0 || arr[mid - 1] != arr[mid]){
                return n - mid;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return 0;
}

int SquareRoot(int x){ //O(logx) time
    if(x == 0 || x == 1){
        return x;
    }
    int low = 1;
    int high = x/2;
    int ans;
    while(low <= high){
        int mid = (low + high) / 2;
        if(mid*mid == x){
            return mid;
        }
        else if(mid*mid > x){
            high = mid - 1;
        }
        else{
            ans = mid;
            low = mid + 1;
        }
    }
    return ans;
}

//O(logn) time, O(1) aux space
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        if(n == 1){
            return 0;
        }
        while (low <= high){
            int mid = (low + high) / 2;
            if(mid == 0){
                if(nums[0] > nums[1]){
                    return 0;
                }
                else{
                    return 1;
                }
            }
            else if(mid == n - 1){
                if(nums[mid - 1] <= nums[mid]){
                    return mid;
                }
                else{
                    return mid - 1;
                }
            }
            else if(nums[mid + 1] <= nums[mid] && nums[mid - 1] <= nums[mid]){
                return mid;
            }
            else if(mid > 0 && nums[mid - 1] > nums[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return -1;
    }

int search_SortedRotatedArr(int arr[], int n, int x){ //O(logn) time, O(1) aux space
    int low = 0;
    int high = n - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == x){
            return mid;
        }
        else if(arr[low] <= arr[mid]){ //left half sorted
            if(x < arr[mid] && x >= arr[low]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{ //right half sorted
            if(x > arr[mid] && x <= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return -1;
}

bool findpair_givenSum_sortedArr(int arr[], int n, int x){ //O(n) time
    int i = 0; 
    int j = n - 1;
    while(i < j){
        if(arr[i] + arr[j] > x){
            j--;
        }
        else if(arr[i] + arr[j] < x){
            i++;
        }
        else{
            return true;
        }
    }
    return false;
}

bool findTriplet_givensum_sortedArr(int arr[], int n, int x){
    for(int i = 0; i < n - 1; i++){
        int left = i + 1;
        int right = n - 1;
        while(left < right){
            if(arr[i] + arr[left] + arr[right] == x){
                return true;
            }
            else if(arr[left] + arr[right] < x - arr[i]){
                left++;
            }
            else{
                right--;
            }
        }
    }
    return false;
}

vector<int> merge_SortedArrays(int a1[], int a2[], int n1, int n2){
    vector<int> ans;
    int i = 0, j = 0;
    while(i < n1 && j < n2){
        if(a1[i] > a2[j]){
            ans.push_back(a2[j]);
            j++;
        }
        else{
            ans.push_back(a1[i]);
            i++;
        }
    }
    while(i < n1){
        ans.push_back(a1[i]);
        i++;
    }
    while(j < n2){
        ans.push_back(a2[j]);
        j++;
    }
    return ans;
}

float median_sortedArrays(int a1[], int a2[], int n1, int n2){
    vector<int> mergedArr = merge_SortedArrays(a1, a2, n1, n2);
    float median;
    int mid = (n1 + n2 - 1)/2;
    if((n1 + n2) % 2 == 0){
        median = (mergedArr[mid] + mergedArr[mid + 1])/2;
        return median;
    }
    else{
        return mergedArr[mid];
    }
}

int main(){
    int arr[] = {2, 3, 4, 8, 9, 20, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout << index_firstOccurence(arr, n, 20);
    // cout << index_lastOccurence(arr, n, 20);
    // cout << countOccurences_sortedArr(arr, n, 20);
    bool b_arr[] = {0, 1, 0, 0, 1, 1, 1, 1};
    // cout << countOccurences_binaryArr(b_arr, 7);
    // cout << SquareRoot(7);
    // cout << peak_element(arr, n);
    // cout << search_SortedRotatedArr(arr, n, 10);
    // cout << findpair_givenSum_sortedArr(arr, n, 400);
    // cout << findTriplet_givensum_sortedArr(arr, n, 45);
    int a1[] = {10, 20, 30, 40, 50};
    int a2[] = {5, 15, 25, 35, 45};
    int n1 = sizeof(a1) / sizeof(a1[0]);
    int n2 = sizeof(a2)/ sizeof(a2[0]);
    // cout << median_sortedArrays(a1, a2, n1, n2);
    return 0;
}