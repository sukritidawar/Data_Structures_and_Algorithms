#include <iostream>
#include <deque>
using namespace std;

//Data structure with min/max operations in O(1) time
struct MyDS{
    deque<int>dq;
    void insertMin(int x){
        dq.push_front(x);
    }
    void insertMax(int x){
        dq.push_back(x);
    }
    int getMin(){
        return dq.front();
    }
    int getMax(){
        return dq.back();
    }
    void extractMin(){
        dq.pop_front();
    }
    void extractMax(){
        dq.pop_back();
    }
};

//Sliding Window Maximum
void PrintMaxk(int arr[], int n, int k){
    deque<int> dq;
    
}

int main(){
    // deque<int> dq;
    // dq.push_front(5);
    // dq.push_back(50);
    // // for(auto x : dq){ //Traversing dq
    // //     cout << x << " ";
    // // }
    // // cout << dq.front() << " " << dq.back() << " " << dq.size();
    // auto it = dq.begin();
    // it++;
    // dq.insert(it, 20);
    // dq.pop_front();
    // for(auto x : dq){ 
    //     cout << x << " ";
    // }
    MyDS ds;
    ds.insertMin(15);
    ds.insertMax(20);
    cout << ds.getMax();
    ds.extractMax();
    cout << ds.getMin();
    return 0;
}