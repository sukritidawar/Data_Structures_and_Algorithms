#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

//Sorting an array using priority queue
void sorting(int arr[], int n){
    priority_queue<int, vector<int>, greater<int> > pq(arr, arr + n); //making min heap 
    while(pq.empty() == false){
        cout << pq.top() << " ";
        pq.pop();
    }
}

//Print k largest elements in array
//MaxHeap approach
void kLargest(int arr[], int n, int k){ //O(n + klogn)
    priority_queue<int> pq(arr, arr + n);
    for(int i = 0; i < k; i++){ 
        cout << pq.top() << " ";
        pq.pop();
    }
}
//MinHeap approach
void printKLargest(int arr[], int n, int k){ //O(k + (n - k)*logk) + O(k*logk) time
    priority_queue<int, vector<int>, greater<int> > pq(arr, arr + k);
    for(int i = k; i < n; i++){
        if(arr[i] > pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    while(pq.empty() == false){
        cout << pq.top() << " ";
        pq.pop();
    }    
}

//Purchasing maximum items
int maxItems(int arr[], int n, int sum){
    priority_queue<int, vector<int>, greater<int> > pq(arr, arr + n);
    int res = 0;
    while(sum >= 0 && pq.empty() == false && pq.top() <= sum){
        sum -= pq.top();
        pq.pop();
        res++;
    }
    return res;
}

//Printing k most frequent items 
struct myCmp{  //in priority queue constructor we expect a class template hence we use structure
    bool operator () (pair<int, int> p1, pair<int, int> p2){
        if(p1.second == p2.second){
            return p1.first > p2.first;  
        }
        return p1.second < p2.second;
    }
};
void kmostFrequent(int arr[], int n, int k){ //O(n + klogn)
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++){ //O(n)
        m[arr[i]]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int> >, myCmp > pq(m.begin(), m.end()); //O(n)
    for(int i = 0; i < k; i++){ //O(klogn)
        cout << pq.top().first << " ";
        pq.pop();
    }
}

//Printing k most frequent items in linear time
//No order of elements
void kMost_bigOn(int arr[], int n, int k){
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++){
        m[arr[i]]++;
    }
    vector<vector<int> > freq(n + 1);
    for(auto x : m){  
        freq[x.second].push_back(x.first); //Storing the elements at freq index
    }
    /*for(int i = 0; i < n; i++){ //for order of elements in a way that first element occurs first while printing
        int f = m[arr[i]];
        if(f != -1){
            freq[f].push_back(arr[i]);
            m[arr[i]] = -1;
        }
    }*/
    int count = 0;
    for(int i = n; i >= 0; i--){
        for(int x : freq[i]){
            cout << x << " ";
            count++;
            if(count == k){
                return;
            }
        }
    }
}

int main(int argc, char** argv){
    int arr[] = {10, 5, 15, 35, 70, 10, 20, 20};
    int n = sizeof(arr)/ sizeof(int);
    // sorting(arr, n);
    // kLargest(arr, n, 3);
    // printKLargest(arr, n, 3);
    // cout << maxItems(arr, n, 30);
    // kmostFrequent(arr, n, 3);
    kMost_bigOn(arr, n, 3);
    return 0;
}