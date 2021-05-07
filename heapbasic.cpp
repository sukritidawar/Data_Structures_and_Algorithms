#include <iostream>
#include <climits>
using namespace std;

//To implement our own minheap
class MinHeap{
    int *arr;
    int size;
    int capacity;
    public:
    MinHeap(int c){
        arr = new int[c];
        size = 0;
        capacity = c;
    }
    int left(int i){
        return (2*i + 1);
    }
    int right(int i){
        return (2*i + 2);
    }
    int parent(int i){
        return (i - 1)/2;
    }
    void insert(int value){ //Time complexity: O(log(size)) or O(height of BT)
        if(size < capacity){
            size++;
            int i = size - 1;
            arr[i] = value;
            while(arr[parent(i)] > arr[i] || i != 0){
                swap(arr[parent(i)], arr[i]);
                i = parent(i);
            }
        }
        else{
            cout << "cannot be inserted";
        }
    }

    void minHeapify(int i){ //O(logn) time and O(logn) aux space(due to recursion stack)
        int lt = left(i);
        int rt = right(i);
        int smallest = i;
        if(lt < size && arr[lt] < arr[i]){
            smallest = lt;
        }
        if(rt < size && arr[rt] < arr[i]){
            smallest = rt;
        }
        if(smallest != i){
            swap(arr[i], arr[smallest]);
            minHeapify(smallest);
        }
    }

    int ExtractMin(){ // O(logn) time
        if(size == 0){
            return INT_MAX;
        }
        if(size == 1){
            size--;
            return arr[0];
        }
        swap(arr[0], arr[size - 1]);
        size--;
        minHeapify(0);
        return arr[size];
    }
    
    void decreaseKey(int i, int x){ //O(logn) time
        arr[i] = x;
        while(arr[parent(i)] > arr[i] || i != 0){
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }
     
    void deleteKey(int i){ //O(logn) time
        decreaseKey(i, INT_MIN);
        ExtractMin();
    } 

    void buildHeap(){
        for(int i = (size - 2)/2; i >= 0; i--){
            minHeapify(i);
        }
    }

};


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

int main(int argc, char** argv){
    int c;
    cin >> c;
    MinHeap mh(c);
        

    return 0;
}