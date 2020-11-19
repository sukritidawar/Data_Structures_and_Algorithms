#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
    Node(int x){
        data = x;
        next = prev = NULL;
    }
};

Node* insertatBeginning(Node* head, int data){ //O(1) time
    Node* temp = new Node(data);
    if(head == NULL){
        return temp;
    }
    head -> prev = temp;
    temp -> next = head;
    return temp;
}

void TraverseDLL(Node* head){ //O(n) time
    while(head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
}

Node* insertAtend(Node* head, int data){ //O(n) time
    Node* temp = new Node(data);
    if(head == NULL){
        return temp;
    }
    Node* curr = head;
    while(curr -> next != NULL){
        curr = curr -> next;
    }
    curr -> next = temp;
    temp -> prev = curr;
    return head;
}

Node* reverseDLL(Node* head){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node *prev = NULL;
    Node* curr = head;
    while(curr != NULL){
        prev = curr -> prev;           //swapping
        curr -> prev = curr -> next;
        curr -> next = prev;
        curr = curr -> prev;
    }
    return prev;
}

Node* deleteHead(Node* head){ //theta 1 time
    if(head == NULL || head -> next == NULL){
        return NULL;
    }
    Node* temp = head;
    head = head -> next;
    head -> prev = NULL;
    delete temp;
    return head;
}

Node* deleteLastNode(Node* head){ //O(n), to reduce this complexity, we can maintain a tail pointer, but then for every operation like insert, etc we have to see that tail pointer is updated properly.
    if(head == NULL || head -> next == NULL){
        return NULL;
    }
    Node* curr = head;
    while(curr -> next != NULL){
        curr = curr -> next;
    }
    curr -> prev -> next = NULL;
    delete curr;
    return head;
}

/* Inserting at beginning of a circular LL
Node* insertAtHead_circularDLL(Node* head, int data){ //O(1)
    Node* temp = new Node(data);
    if(head == NULL){
        temp -> next = temp;
        temp -> prev = temp;
        return temp; 
    }
    temp -> prev = head -> prev;
    temp -> next = head;
    head -> prev -> next = temp;
    head -> prev = temp;
    return temp;
}
*/

int main(){
    Node* head = NULL;
    head = insertatBeginning(head, 5);
    head = insertatBeginning(head, 10);
    head = insertAtend(head, 15);
    // head = deleteHead(head);
    head = deleteLastNode(head);
    // head = reverseDLL(head);
    TraverseDLL(head);
    return 0;
}