#include <bits/stdc++.h>
using namespace std;

int largestEleinArr(int arr[], int n){   //theta n
    int ans = -1;
    int max = arr[0];
    for(int i = 1; i < n; i++){
        if(max < arr[i]){
            max = arr[i];
            ans = i;
        }
    }
    return ans;
}

int secondlargestele(int arr[], int n){     //Naive approach: two traversals
    int ans = -1;
    int max1, max2;
    max1 = largestEleinArr(arr, n);
    for (int j = 0; j < n; j++)
    {
        if(arr[j] != arr[max1]){
            if(ans == -1){
                ans = j;
            }else if(arr[j] > arr[ans]){
                ans = j;
            }
        }
    }
    return ans;
}

int secondlargestEfficient(int arr[], int n){  //Efficient approach: one traversal
    int ans = -1, largest = 0;
    for(int i= 1; i < n; i++){
        if(arr[i] > arr[largest]){
            ans = largest;
            largest = i;
        }
        else if(arr[i] != arr[largest]){
            if(ans == -1 || arr[i] > arr[ans]){
                ans = i;
            }
        }
    }
    return ans;
}

int searchEle(int arr[], int n, int x){      //Time complexity: O(n)
    for(int i = 0; i < n; i++){
        if(arr[i] == x){
            return i;
        }
    }
    return -1;
}

int insertEle(int arr[],int ele,int cap, int n, int pos)       //returns size of array after inserting element
{
    if(cap <= n){
        return n;
    }
    for(int i = n - 1; i >= pos - 1; i--){
        arr[i + 1] = arr[i];
    }
    arr[pos - 1] = ele;
    return n+1;
}

int deleteEle(int arr[], int n, int ele){   //theta n
    int i;
    for( i = 0; i < n; i++){
        if(arr[i] == ele){
            break;
        }
    }
    if(i == n){
        return n;
    }
    for(int j = i; j < n - 1; j++){
        arr[j] = arr[j + 1];
    }
    return n - 1;
}

int* movezeroestotheend(int arr[], int n){   //O(n2) naive approach
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            for(int j = i + 1; j < n; j++){
                if(arr[j] != 0){
                    swap(arr[i], arr[j]);
                    break;
                }
            }
        }
    }
    return arr;
}

int* moveZeros_efficientsoln(int arr[], int n){ //O(n) time , auxiliary space:O(1)
    int count = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] != 0){
            swap(arr[i], arr[count]);     //if non zero element swap it with prev zero element
            count++;                      //prev zero element would be at index count
        }
    }
    return arr;
}

int* reverseArr(int arr[], int n){       //Time complexity: theta n
    for(int i = 0; i < n/2; i++){        //Auxiliary space: theta 1(coz we're using some extra variables only other than input arr)
        swap(arr[i], arr[n - i - 1]);
    }
    return arr;
}

int* leftrotatebyone(int arr[], int n){
    int firstele = arr[0];
    for(int i = 1; i < n; i++){
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = firstele;
    return arr;
}

int kadanesAlgorithm(int arr[], int n){
    int max_curr = arr[0], max_global = arr[0]; //max_curr is for the current maximum and max_gloabal is for the maximum subarray sum
    for(int i = 1; i < n; i++){
        max_curr = max(arr[i], max_curr + arr[i]);
        if(max_curr > max_global){
            max_global = max_curr;
        }
    }
    return max_global;
}

vector<int> maxElements(int arr[], int n1, int brr[], int n2){
    int freq1[9], freq2[9];
    for(int i = 0; i < n1; i++){
        freq1[arr[i]]++;
    }
    for(int i = 0; i < n2; i++){
        freq2[brr[i]]++;
    }
    
}

int main(){
    int arr[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int x, y, yi;
    //cin >> x;
    //cout << searchEle(arr, n, x);
    // cin >> y >> yi;
    // cout << insertEle(arr, y, 100, n, yi);
    // cin >> x;
    // cout << deleteEle(arr, n, x);
    //cout << largestEleinArr(arr, n);
    //cout << secondlargestele(arr, n);
    // cout << secondlargestEfficient(arr, n);
    // int *p = movezeroestotheend(arr, n);
    // int *p = moveZeros_efficientsoln(arr, n);
    // int *p = reverseArr(arr, n);
    // int *p = leftrotatebyone(arr, n);
    // for(int i = 0; i < n ;i++){
    //     cout << p[i] << " ";
    // }
    cout << kadanesAlgorithm(arr, n);
    cout << endl;
    return 0;
}