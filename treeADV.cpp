#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
    Node(int k){
        key = k;
        left = right = NULL;
    }
};

void LevelOrderTraversal_linebyline(Node *root){ //O(n) time, O(n) space or theta(width) space
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size() > 1){
        Node* curr = q.front();
        q.pop();
        if(curr == NULL){
            cout << "\n";
            q.push(NULL);
            continue;
        }
        cout << curr -> key << " ";
        if(curr -> left != NULL){
            q.push(curr -> left);
        }
        if(curr -> right != NULL){
            q.push(curr -> right);
        }
    }
}

void PrintNodes_distK(Node* root, int k){ //Worst case: theta(n), Best case: theta(1),   O(h) space
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout << root -> key << " ";
    }
    else{
        PrintNodes_distK(root -> left, k - 1);
        PrintNodes_distK(root -> right, k - 1);
    }
}

void printLeftView(Node* root){
    if(root == NULL){
        return;
    }
    cout << root -> key << " ";
        if(root -> left != NULL){
            printLeftView(root -> left);
        }
        else{
            printLeftView(root -> right);
        }
}

int main(){
    Node *root = new Node(10);
    root -> left = new Node(20);
    root -> right = new Node(30);
    root -> right -> left = new Node(40);
    root -> right -> right = new Node(50);
    // LevelOrderTraversal_linebyline(root);
    // PrintNodes_distK(root, 2);
    printLeftView(root);
    return 0;
}