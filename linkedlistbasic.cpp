#include <bits/stdc++.h>
using namespace std;

struct Node{ //self refrential structure
    int data;
    Node *next; //since the next node would be a pointer of type node
    Node(int x){
        data = x;
        next = NULL;
    }
};

void traversingLL(Node *head){ //O(n) time and O(1) aux space
    while(head != NULL){   //this head is a copy of the head(main function's head)
        cout << head -> data << " ";
        head = head -> next;
    }
}

void recursivedisplayLL(Node *head){ //O(n) time and O(n) aux space
    if(head == NULL){
        return;
    }
    cout << head -> data << " ";
    recursivedisplayLL(head -> next);
}

int searchLL(Node *head, int x){ //O(n) time and O(1) aux space
    int idx = 1;  //indexing 1, 2, 3 etc
    while(head != NULL){
        if(head -> data == x){
            return idx;
        }
        head = head -> next;
        idx++;
    }
    return -1;
}

int search_recursive(Node *head, int x){ //O(n) time and O(n) aux space
    if(head == NULL){return -1;}
    if(head -> data == x){
        return 1;
    }
    else{
        int res = search_recursive(head -> next, x);
        if(res == -1){return -1;}
        else{return res + 1;}
    }
}

Node* insertatbeginning(Node *head, int x){  //O(1) time
    Node *temp = new Node(x);
    temp -> next = head;
    return temp;
}

Node* insertatend(Node *head, int x){ //O(n)
    Node *temp = new Node(x);
    if(head == NULL){return temp;} //when LL is empty
    Node *curr = head;
    while(curr->next != NULL){ //here, if we put curr!=NULL, then it will stop at null and we will get seg fault
        curr = curr -> next;   //but if we write curr->next not null then it will stop at last node
    }
    curr -> next = temp;
    return head;
}

Node* deleteHead(Node* head){ //O(1)
    if(head == NULL){return NULL;}
    else{
        Node *temp = head -> next;
        delete head;
        return temp;
    }
}

Node* deleteLastnode(Node* head){ //theta n time
    if(head == NULL){return NULL;}
    if(head->next == NULL){return NULL;}
    else{
        Node *curr = head;
        while(curr->next->next != NULL){
            curr = curr -> next;
        }
        delete curr->next;
        curr->next = NULL;
        return head;
    }
}

Node* insertatgivenpos(Node* head, int pos, int x){ //O(n) time
    Node *curr = head;
    Node *temp = new Node(x);
    if(pos == 1){
        temp -> next = head;
        return temp;
    }
    for(int idx = 1; idx <= pos - 2 && curr != NULL; idx++){
        curr = curr -> next;
    }  
    if(curr == NULL){return head;} //corner case, if suppose user enters 8 and we can only insert node till pos 6, so curr would become null in between..so we do not change anything in LL
    temp -> next = curr -> next;
    curr -> next = temp;
    return head;
}

Node* sortedInsertinLL(Node* head, int x){ //theta(pos) time
    Node* temp = new Node(x);
    if(head == NULL){return temp;}
    if(x < head -> data){
        temp -> next = head;
        return temp;
    }
    Node* curr = head;
    while(curr -> next != NULL && curr->next->data < x){
        curr = curr -> next;
    }
    temp -> next = curr -> next;
    curr -> next = temp;
    return head;
}

void MiddleofLL_naive(Node* head){ //two traversals of LL
    if(head == NULL){return;}
    Node* curr = head;
    int count = 0;
    while(curr != NULL){
        count++;
        curr = curr -> next;
    }
    curr = head;
    int middle = count / 2;
    for(int i = 0; i < middle; i++){
        curr = curr -> next;
    }
    cout << curr -> data;
}

void MiddleofLL_efficient(Node* head){ //one traversal of LL
    if(head == NULL){return;}
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    cout << slow -> data;
}

void nthNodefromEnd_naive(Node* head, int n){ //with calculating size, O(n) time
    if(head == NULL){return;}
    int size;
    Node* curr = head;
    for(size = 0; curr != NULL; size++){
        curr = curr -> next;
    }
    int pos = size - n; //position from beginning
    if(pos < 0){return;}
    curr = head;
    for(int i = 0; i < pos && curr!= NULL; i++){
        curr = curr -> next;
    }
    cout << curr -> data;
}

void nthNodefromEnd_efficient(Node*head, int n){//without calculating size, O(n) time
    if(head == NULL){return;}
    Node* first = head, *second = head;
    for(int i = 0; i < n; i++){
        if(first == NULL){return;}
        first = first -> next;
    }
    while(first != NULL){
        first = first -> next;
        second = second -> next;
    }
    cout << second -> data;
}

Node* reverseLL(Node* head){ //O(n) time, O(1) aux space
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL){
        Node* next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev; 
}

Node* reverseLL_recursive1(Node* head){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node* rest_head = reverseLL_recursive1(head -> next);
    Node *rest_tail = head -> next;
    rest_tail -> next = head;
    head -> next = NULL;
    return rest_head;
}

Node* reverseLL_recursive2(Node* curr, Node* prev){
    if(curr == NULL){
        return prev;
    }
    Node* next = curr -> next;
    curr-> next = prev;
    return reverseLL_recursive2(next, curr);
}

void removeDuplicatesfromLL(Node* head){
    Node* curr = head;
    while(curr != NULL && curr -> next != NULL){
        if(curr -> next -> data == curr -> data){
            Node* temp = curr -> next;
            curr -> next = curr -> next -> next;
            delete temp;
        }
        else{
            curr = curr -> next;
        }
    }
}

int getSurvivor(int n, int k){ //Josephus problem using list in STL, O(n*k) time, O(n) space
    list<int> l;
    for(int i = 0; i < n; i++){
        l.push_back(i);
    }
    list<int>::iterator it = l.begin();
    while(l.size() > 1){
        for(int count = 1; count < k; count++){
            it++;
            if(it == l.end()){
                it = l.begin();
            }
        }
        it = l.erase(it);
        if(it == l.end()){
            it = l.begin();
        }
    }
    return *l.begin();
}

int main(int argc, char** argv){
    Node *head = NULL;
    head = insertatbeginning(head, 10);
    head = insertatbeginning(head, 10);
    head = insertatend(head, 15);
    head = insertatbeginning(head, 10);
    // head = deleteHead(head);
    // head = deleteLastnode(head);
    // Node *temp1 = new Node(20);
    // Node *temp2 = new Node(30);
    // head -> next = temp1;
    // temp1 -> next = temp2;
    head = sortedInsertinLL(head, 30);
    // head = reverseLL(head);
    // head = reverseLL_recursive1(head);
    // head = reverseLL_recursive2(head, NULL);
    removeDuplicatesfromLL(head);
    traversingLL(head);
    // MiddleofLL(head);
    // MiddleofLL_efficient(head);
    // nthNodefromEnd_naive(head, 2);
    // nthNodefromEnd_efficient(head, 2);
    // recursivedisplayLL(head);
    // cout << searchLL(head, 40);
    // cout << search_recursive(head, 30);
    // cout << getSurvivor(7, 3);
    return 0;
}