#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> s){ //not the actual method, just prints the elements in reverse order
    if(s.empty()){
        return;
    }
    int x = s.top();
    s.pop();
    reverseStack(s);
    cout << x << " ";
}

bool matching(char a, char b){
    if((a == '{' && b == '}') || (a == '(' && b == ')') || (a == '[' && b == ']')){
        return true;
    }
    return false;
}

bool checkBalancedParanthesis(string s){
    stack<char> st;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '{' || s[i] == '[' || s[i] == '('){
            st.push(s[i]);
        }
        else{
            if(st.empty() == true){
                return false;
            }
            else if(matching(st.top(), s[i]) == false){
                return false;
            }
            else{
                st.pop();
            }
        }
    }
    return st.empty() == true;
}

int PostfixtoInfix(string s){
    int n = s.size();
    stack<int> st;
    for(int i = 0; i < n; i++){
        if(s[i] != ' '){
            int x = s[i] - '0';
            if(isdigit(x)){
              st.push(x);
            }
            else{
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            switch(s[i]){
                case '*' : st.push(op1 * op2);
                           break;
                case '/' : st.push(op1/op2);
                           break;
                case '^' : st.push(op2 ^ op1);
                           break;
                case '+' : st.push(op1 + op2);
                           break;
                case '-' : st.push(op1 - op2);
                           break;
            }
            } 
        }
    }
    return st.top();
}

void previous_greater_element(int arr[], int n){
    int ans[n];
    stack<int> st;
    for(int i = 0; i < n; i++){
        if(st.empty()){
            ans[i] = -1;
        }
        else{
            if(arr[i] > st.top()){
                ans[i] = -1;
            }
            else{
                while(st.empty() == false && st.top() <= arr[i]){
                    st.pop();
                }
                ans[i] = st.top();
            }
        }
        st.push(arr[i]);
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
}

int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    reverseStack(st);
    /*cout << st.size() << endl;
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl; */

    // cout << checkBalancedParanthesis("{}");
    // cout << PostfixtoInfix("10 2 * 3 5 * + 9 -");
    // int arr[] = {15, 10, 18, 12, 4, 6, 2, 8};
    // int n = sizeof(arr) / sizeof(int);
    // previous_greater_element(arr, n);
    return 0;
}