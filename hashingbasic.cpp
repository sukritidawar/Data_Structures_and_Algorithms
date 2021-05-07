#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
//Chaining
struct MyHashc{
    int BUCKET;
    list<int> *table;   //table is an arr of LL
    MyHashc(int b){
        BUCKET = b;   //Bucket size initialised to user input size
        table = new list<int> [BUCKET]; //making a new LL
    }
    int hash(int key){
        return key % BUCKET;
    }
    bool search(int key){
        int i = hash(key);
        for(auto x: table[i]){
            if(x == key){
                return true;
            }
        }
        return false;
    }
    void insert(int key){
        int i = hash(key);  //finding the LL where the key would be
        table[i].push_back(key);
    }
    void remove(int key){
        int i = hash(key);
        table[i].remove(key);
    }
};

//Open Adressing
struct MyHash{
    int *arr;
    int cap, size;
    MyHash(int c){
        arr=new int[c];
        cap = c;
        size = 0;
        for(int i = 0; i < cap; i++){
           arr[i] = -1;
        }
    }
    int hash(int key){
        return key % cap;
    }
    bool search(int key){
        int h = hash(key);
        int i = h;
        while(arr[i] != -1){
            if(arr[i] == key){return true;}
            i = (i + 1) % cap;   //for cyclic order
            if(i == h){
                return false;
            }
        }
        return false;
    }
    bool insert(int key){
        if(size == cap){return false;}
        int i = hash(key);
        while(arr[i] != -1 && arr[i] != -2 && arr[i] != key){
            i = (i + 1) % cap;
        }
        if(arr[i] == key){return false;}
        else{
            arr[i] = key;
            size++;
            return true;
        }
    }
    bool erase(int key){
        int h = hash(key);
        int i = h;
        while(arr[i] != -1){
            if(arr[i] == key){
                arr[i] = -2;
                return true;
            }
            i = (i + 1) % cap;
            if(i == h){
                return false;
            }
        }
        return false;
    }
};

//Questions on hashing
//1. Count no of distinct elements
int count_distinctelements(int arr[], int n){ //O(n) time and O(n) aux space
    unordered_set<int> s;
    for(int i = 0; i < n; i++){
        s.insert(arr[i]);
    }
    return s.size();
}

//2.Count frequencies of elements
void count_frequencies(int arr[], int n){ //O(n) time and O(n) aux space
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++){
        m[arr[i]]++;
    }
    for(auto it = m.begin(); it != m.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
    // for(int i = 0; i < n; i++){  //for printing freq of elements in same order as given in arr
    //     if(m[arr[i]] != -1){
    //         cout << arr[i] << " " << m[arr[i]] << endl;
    //         m[arr[i]] = -1;
    //     }
    // }
}

int main(){
    // MyHashc mh(7);
    // mh.insert(49);
    // mh.insert(56);
    // mh.insert(72);
    // if(mh.search(56) == true){
    //     cout << "Yes";
    // }else{
    //     cout << "No";
    // }
    // mh.remove(56);
    // if(mh.search(56)){
    //     cout << "Yes";
    // }else{
    //     cout << "No";
    // }
    
    int arr[5];
    for(int i = 0; i < 5; i++){
        cin >> arr[i];
    } 
    // cout << count_distinctelements(arr, 5);
    count_frequencies(arr, 5);
    return 0;
}