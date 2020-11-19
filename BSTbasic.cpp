#include<iostream>
using namespace std;

struct Node{
    int key;
    Node *left, *right;
    Node(int k){
        key = k; 
        left = right = NULL;        
    }
};

bool search(Node* root, int val){ //Time: O(h), aux space(recursive):O(h), aux space by iterative:O(1) (here we're talking about normal BST)
    if(root == NULL){
        return false;
    }
    if(root -> key == val){
        return true;
    }
    else if(root -> key < val){
        return search(root -> right, val);
    }
    else{
        return search(root -> left, val);
    }
}

Node* insert(Node* root, int x){ //Time : O(h), Aux.space = O(1)
    Node *temp = new Node(x);
    Node* curr = root;
    Node* parent = NULL;
    while(curr != NULL){
        parent = curr;
        if(curr -> key == x){
            return root;
        }
        else if(curr -> key < x){
            curr = curr -> right; 
        }
        else{
            curr = curr -> left;
        }
    }
    if(parent == NULL){
        return temp;
    }
    if(parent -> key < x){
        parent -> right = temp;
    }
    else {
        parent -> left = temp;
    }
    return root;
}

Node* insertRecursive(Node* root, int x){//Time: O(h), Aux.space:O(h)
    if(root == NULL){
        return new Node(x);
    }
    else if(root -> key < x){
        root -> right = insertRecursive(root -> right, x);
    }
    else{
        root -> left = insertRecursive(root -> left, x);
    }
    return root; 
}

void preorderTraversal(Node* root){
    if(root != NULL){
        cout << root -> key << " ";
        preorderTraversal(root -> left);
        preorderTraversal(root -> right);
    }
}

Node* getSuccessor(Node* curr){ //works only when right child of a node is not empty
    curr = curr -> right;
    while(curr != NULL && curr -> left != NULL){ //closest value is the leftmost leaf of the right child
        curr = curr -> left;
    }
    return curr; 
}

Node* delNode(Node* root, int x){ //Time: O(h), aux.space = O(h)
    if(root == NULL){
        return root;
    }
    if(root -> key < x){
        root -> right = delNode(root -> right, x);
    }
    else if(root -> key > x){
        root -> left = delNode(root -> left, x);
    }
    else{
        if(root -> left == NULL){ //if there is only right child present or both children are not there
            Node* temp = root -> right;
            delete root;
            return temp;
        }
        else if(root -> right == NULL){ //if there is only left child present
            Node* temp = root -> left;
            delete root;
            return temp;
        }
        else{ //if both children are present
            Node* succ = getSuccessor(root);
            root -> key = succ -> key;
            root -> right = delNode(root -> right, succ -> key);
        }
    }
    return root;
}

int main(){
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 5);
    root = insertRecursive(root, 30);
    root = delNode(root, 10);
    preorderTraversal(root);
    // cout << search(root, 20);
    return 0;
}