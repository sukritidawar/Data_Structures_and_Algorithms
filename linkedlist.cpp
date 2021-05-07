#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next;
};

void insert_at_beginning(node **pointertohead, int x){ //** for getting address, for derefrencing this, use *(** is pointer to pointer)
    node *temp = new node(); 
    temp -> data = x;
    //temp ->next = NULL;
    //if(head != NULL){temp -> next = head;}
    temp -> next = *pointertohead;
    *pointertohead = temp;
}

void insert_at_nthposition(node **pointertohead, int x, int n){
    node *temp1 = new node();
    temp1 -> data = x;
    temp1 -> next = NULL;
    if(n == 1){
        temp1 -> next = *pointertohead;
        *pointertohead = temp1;
        return;
    }
    node *temp2 = *pointertohead;
    for(int i = 0; i < n - 2; i++){  // to calculate address of n-1 th node
        temp2 = temp2 ->next;
    }
    temp1 -> next = temp2 -> next;
    temp2 -> next = temp1;
}

void delete_at_nthposition(node **pointertohead, int n){
    node *temp1 = *pointertohead; // temp1 points to first node 
    if(n == 1){
        *pointertohead = temp1 -> next;
        delete temp1;
        return;
    }
    for(int i = 0; i < n - 2; i++){ 
        temp1 = temp1 -> next;
    }
    //temp1 points to (n-1)th node
    node *temp2 = temp1 -> next; //nth node
    temp1 -> next = temp2 -> next; //n-1th node connected to n+1th node
    delete temp2; 
}

void reverse_linkedlist(node **pointertohead){
    node *current = *pointertohead;
    node *prev, *nextnode;
    prev = NULL;
    while(current != NULL){
       nextnode = current -> next;
       current -> next = prev;
       prev = current;
       current = nextnode; 
    }
    *pointertohead = prev;
}

void reverse_linkedlist_recursion(node **pointertohead, node *p){
    if(p->next == NULL){
       *pointertohead = p;
       return;
    }
    reverse_linkedlist_recursion(pointertohead, p->next);
    node *q = p -> next;
    q -> next = p;
    p -> next = NULL;
}

void print_all_elements(node* head){
    // (when head is global)node *temp = head; //if we modify head, then we will lose the reference of the first node
    cout << "List is: ";
    while(head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
}

void print_forward_recursively(node* head){
    if(head == NULL){
        return;
    }
    cout << head -> data;
    print_forward_recursively(head -> next);
}

void print_reverse_recursively(node* head){
    if(head == NULL){
        return;
    }
    print_reverse_recursively(head -> next);
    cout << head -> data;
}

int getNthFromLast(node *head, int n)
{
       node *temp = head;
       int len = 0;
       while(temp-> next != NULL){
           len++;
           temp = temp->next;
       }
       if(len < n){
           return -1;
       }
       temp = head;
       for(int i=1; i < len-n+1;i++){
           temp = temp->next;
       }
       return temp->data;
}

int getNthFromLastrecursive(node *head, int n)
{
       int i = 0;
       getNthFromLastrecursive(head->next, n);
       i++;
       if(i == n){
           return head->data;
       }
}

int length_of_linkedlist(node *head){
    if(head == NULL){
        return 0;
    }
    return 1 + length_of_linkedlist(head->next);
}

int main(int argc, char* argv[]){
    node* head = NULL; //empty list
    int n, x;  //n is the number of elements you want to insert
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << "Enter the number";
        cin >> x; //x is element
        insert_at_beginning(&head, x);
        print_all_elements(head);//prints elements after every number inserted
    }
    // insert_at_nthposition(&head, 5, 2);
    // delete_at_nthposition(&head, 2);
    // print_all_elements(head);
    // reverse_linkedlist(&head);
    // print_all_elements(head);
    // print_forward_recursively(head);
    // cout << endl;
    // print_reverse_recursively(head);
    //reverse_linkedlist_recursion(&head, head);
    //print_all_elements(head);
    cout << length_of_linkedlist(head);
    return 0;
}