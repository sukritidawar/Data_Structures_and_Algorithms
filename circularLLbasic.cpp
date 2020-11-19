#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

void traverse_circularLL(Node* head){ //O(n) time
    if(head == NULL){
        return;
    }
    Node *p = head;
    do{
        cout << p -> data << " ";
        p = p -> next;
    }while(p != head);
}

Node* insertAtBeginning_naive(Node* head, int x){ //O(n) time
    Node* temp = new Node(x);
    if(head == NULL){
        temp -> next = temp;
    }
    else{
        Node* curr = head;
        while(curr -> next != head){
            curr = curr -> next;
        }
        curr -> next = temp;
        temp -> next = head;
    }
    return temp;
}

Node* insertAtBeginning_efficient(Node* head, int x){ //O(1) time
    Node* temp = new Node(x);
    if(head == NULL){
        temp -> next = temp;
        return temp;
    } 
    else{
        temp -> next = head -> next;
        head -> next = temp;
        int t = temp -> data;
        temp -> data = head -> data;
        head -> data = t;
        return head;
    }
}

Node* insertAtend_naive(Node*head, int x){ //theta(n) time
    Node* temp = new Node(x);
    if(head == NULL){
        temp -> next = temp;
        return temp;
    }
    else{
        Node* curr = head;
        while(curr -> next != head){
            curr = curr -> next;
        }
        curr -> next = temp;
        temp -> next = head;
        return head;
    }
}

Node* insertatend_efficient(Node* head, int x){ //O(1) time
    Node* temp = new Node(x);
    if(head == NULL){
        temp -> next = temp;
        return temp;
    }
    else{
        temp -> next = head -> next;
        head -> next = temp;
        int t = temp -> data;
        temp -> data = head -> data;
        head -> data = t;
        return temp;
    }
}

Node* delete_headNaive(Node* head){ //theta(n) time
    if(head == NULL){
        return NULL;
    }
    if(head -> next == head){
        delete head;
        return NULL;
    }
    Node* curr = head;
    while(curr -> next != head){
        curr = curr -> next;
    }
    curr -> next = head -> next;
    delete head;
    return curr -> next;
}

Node* delete_headEfficient(Node* head){
    if(head == NULL){
        return NULL;
    }
    if(head -> next == head){
        delete head;
        return NULL;
    }
    Node* temp = head -> next;
    head -> data = temp -> data;
    head -> next = temp -> next;
    delete temp;
    return head;
}

Node* delete_kthNode(Node* head, int k){ //O(1) time
    if(head == NULL){
        return head;
    }
    if(k == 1){
        return delete_headEfficient(head);
    }
    Node* curr = head;
    for(int i = 0; i < k - 2; i++){ //k - 2 because we want our curr to stop at (k - 1)th node 
        curr = curr -> next;
    }
    curr -> next = curr -> next -> next;
    delete curr -> next;
    return head;
}

int main(int argc, char** argv){
    // Node* head = new Node(10);
    // head = new Node(20);
    Node* head = NULL;
    head = insertAtBeginning_efficient(head, 10);
    head = insertAtBeginning_efficient(head, 20);
    head = insertAtend_naive(head, 30);
    head = insertatend_efficient(head, 15);
    // head = delete_kthNode(head, 2);
    // head = delete_headNaive(head);
    // head = delete_headEfficient(head);
    traverse_circularLL(head);
    return 0;
}