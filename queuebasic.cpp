#include<bits/stdc++.h>
using namespace std;

struct Queue{ //naive implementation
    int size, cap;
    int* arr;
    Queue(int c){
        cap = c;
        size = 0;
        arr = new int[cap];
    }
    bool isEmpty(){
        return size == 0;
    }
    bool isFull(){
        return size == cap;
    }
    void enqueue(int x){
        if(isFull()){
            return;
        }
        arr[size] = x;
        size++;
    }
    void dequeue(){ //O(n) time
        if(isEmpty()){
            return;
        }
        for(int i = 0; i < size - 1; i++){
            arr[i] = arr[i + 1];
        }
        size--;
    }
    int getFront(){
        if(isEmpty()){
            return -1;
        }
        else{
            return 0;  //returning index of front
        }
    }
    int getRear(){
        if(isEmpty()){
            return -1;
        }
        else{
            return size - 1;
        }
    }
    int size_queue(){
        return size;
    }
};

// Efficient Implementation of Queue using Array
struct Queu{ //All functions take O(1) time and do not waste any space in the array
    int * arr;
    int front, cap, size;
    Queu(int c){
        arr = new int[c];
        cap = c;
        front = 0;
        size = 0;
    }
    bool isFull(){
        return cap == size;
    }
    bool isEmpty(){
        return size == 0;
    }
    int getFront(){
        if(isEmpty()){
            return -1;
        }
        else{
            return front;
        }
    }
    int getRear(){
        if(isEmpty()){
            return -1;
        }
        else{
            return (front + size - 1)%cap;
        }
    }
    void enqu(int x){
        if(isFull()){
            return;
        }
        int rear = getRear();
        rear = (rear + 1) % cap;
        arr[rear] = x;
        size++;
    }
    void dequ(){  //O(1) time
        if(isEmpty()){
            return;
        }
        front = (front + 1) % cap;
        size--;
    }
};

//Linked List implementation of queue
struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};
struct Queue_LL{
    Node *front, *rear;
    int size;
    Queue_LL(){
        front = NULL;
        rear = NULL;
        size = 0;
    }
    void enqueue(int x){
        Node *temp = new Node(x);
        size++;
        if(front == NULL){
            front = rear = temp;
            return;
        }
        rear -> next = temp;
        rear = temp;
    }
    void dequeue(){
        if(front == NULL){
            return;
        }
        size--;
        Node* temp = front;
        front = front -> next;
        if(front == NULL){ //for one node, if we delete that node then we have to set rear to null
            rear = NULL;
        }
        delete temp;
    }  
    int getsize(){
        return size;
    } 
    int getFront(){
        return front -> data;
    } 
    int getRear(){
        return rear -> data;
    }
};

int main(){
    // Queue_LL q = Queue_LL();
    // q.enqueue(5);
    // q.enqueue(10);
    // q.dequeue();
    // cout << q.getsize();
    // cout << q.getFront();

    //Queue in C++ STL
    queue<int> q;
    q.push(10);  //enqueue
    q.push(20);
    q.push(30);
    cout << q.size() << endl;
    while(q.empty() == false){
        cout << q.front() << " " << q.back() << endl;
        q.pop(); //dequeue
    }
    return 0;
}