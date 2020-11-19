#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left; //for left child
    Node *right; //for right child
    Node(int k){
        key = k;
        left = right = NULL;
    }
};

void inorder(Node* root){
    if(root != NULL){
        inorder(root -> left);
        cout << root -> key << " ";
        inorder(root -> right);
    }
}

void preorder(Node* root){
    if(root != NULL){
        cout << root -> key << " ";
        preorder(root -> left);
        preorder(root -> right);
    }
}

void postorder(Node* root){
    if(root != NULL){
        postorder(root -> left);
        postorder(root -> right);
        cout << root -> key << " ";
    }
}

int sizeofBinaryTree(Node* root){// time : O(n), aux.space: O(h)
    if(root == NULL){
        return 0;
    }
    else{
        return 1 + sizeofBinaryTree(root -> left) + sizeofBinaryTree(root -> right);
    }
}

int maximumBT(Node* root){ // time: O(n), aux.space: O(h)
    if(root == NULL){
        return INT_MIN;
    }
    else{
        return max(root -> key, max(maximumBT(root -> left), maximumBT(root -> right)));
    }
}

int heightBT(Node* root){ //Time: O(n), Aux.Space : O(h)
    if(root == NULL){
        return 0;
    }
    else{
        return 1 + max(heightBT(root -> left) , heightBT(root -> right));
    }
}

void inorderIterative(Node* root){ //time: theta(n), aux.space: O(h)
    stack<Node*> st;
    Node* curr = root;
    while(curr != NULL || st.empty() == false){
        while(curr != NULL){ //for printing left subtree nodes
            st.push(curr);
            curr = curr -> left; 
        }
        curr = st.top();
        st.pop();
        cout << curr -> key << " ";
        curr = curr -> right;
    }
}

void preorderIterative(Node* root){ //O(n) time, O(h) aux.space
    stack<Node*> st;
    Node* curr = root;
    while(curr != NULL || st.empty() == false){
        while(curr != NULL){
            st.push(curr);
            cout << curr -> key << " ";
            curr = curr -> left;
        }
        curr = st.top();
        st.pop();
        curr = curr -> right;
    }
}

int main(){
    Node *root = new Node(10);
    root -> left = new Node(20);
    root -> right = new Node(30);
    root -> right -> left = new Node(40);
    root -> right -> right = new Node(50);
    // inorder(root);
    // cout << endl;
    // preorder(root);
    // cout << endl;
    // postorder(root);
    // cout << sizeofBinaryTree(root);
    // cout << maximumBT(root);
    // cout << heightBT(root);
    // inorderIterative(root);
    preorderIterative(root);
    return 0;
}