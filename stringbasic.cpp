#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int fact(int n){
    if(n == 0 || n == 1){
        return n;
    }
    return n * fact(n - 1);
}

bool checkAnagrams(string s1, string s2){
    if(s1.size() != s2.size()){
        return false;
    }
    int count[256] = {0};
    for(int i = 0; i < s1.size(); i++){
        count[s1[i]]++;
    }
    for(int i = 0; i < s2.size(); i++){
        count[s2[i]]--;
    }
    for(int i = 0; i < 256; i++){
        if(count[i] != 0){
            return false;
        }
    }
    return true;
}

int leftmost_repeating_character(string s){ //O(n2)
    for(int i = 0; i < s.size(); i++){
        string s1 = s.substr(i + 1, s.size()- i - 1);
        if(s1.find(s[i]) != -1){
            return i;
        }
    }
    return -1;
}

int leftmost_repeatingchar_optimized(string s){  //O(n) with one traversal
    int res = numeric_limits<int>::max();  //initialising res to infinity
    int fi[256] = {0};                    //fi is storing first indices of str elements
    for(int i=0; i < 256;i++){
        fi[i] = -1;
    }
    for(int i = 0; i < s.size(); i++){
        if(fi[s[i]] == -1){
            fi[s[i]] = i;
        }else{
            res = min(res, fi[s[i]]);
        }
    }
    return (res == numeric_limits<int>::max())?-1:res;
}

int leftmost_nonrepeating_char(string s){  //One string traversal soln
    int res = numeric_limits<int>::max(); 
    int fi[256] = {0};
    for(int i=0; i < 256;i++){
        fi[i] = -1;
    }
    for(int i = 0; i < s.size(); i++){
        if(fi[s[i]] == -1){
            fi[s[i]] = i;
        }else{
            fi[s[i]] = -2;
        }
    }
    for(int i = 0; i < 256; i++){
        if(fi[i] >= 0){
            res = min(res, fi[i]);
        }
    }
    return (res == numeric_limits<int>::max()) ? -1 : res;
}

int lexicographical_rank(string s){   //O(n) assuming that the j loop takes const time
    int rank = 1;     //the string itself
    int count[256] = {0};
    int mul = fact(s.size());
    for(int i = 0; i < s.size(); i++){ //storing freq of characters
        count[s[i]]++;
    }
    for(int i = 1; i < 256; i++){  //calculating cumulative freq(i.e how many characters smaller than current char)
        count[i] += count[i - 1];
    }
    for(int i = 0; i < s.size(); i++){
        mul = mul/(s.size() - i);
        rank += count[s[i] - 1] * mul;
        for(int j = s[i]; j < 256; j++){
            count[j]--;           //because for elements after ith pos, we have to reduce the freq of ith ele coz we'll not be using that
        }
    }
    return rank;
}

bool areSame(int c_txt[], int c_pat[]){
    for(int i = 0; i < 256; i++){
        if(c_pat[i] != c_txt[i]){
            return false;
        }
    }
    return true;
}

bool checkRotations(string s1, string s2){ //O(n)
    if(s1.size() != s2.size()){
        return false;
    }
    s1 += s1;
    return (s1.find(s2) != string::npos);
}

void patSearch_naive(string txt, string pat){
    int n = txt.length(), m = pat.length();
    int j;
    for(int i = 0; i <= n - m; i++){
        for(j = 0; j < m; j++){
            if(txt[i + j] != pat[j]){
                break;
            }
        }
        if(j == m){
            cout << i;
        }
    }
}

void computelpsarray(string pat, int *lps, int m){
    for(int i = 0; i < m; i++){
        lps[i] = 0;
    }
    int len = 0, i = 1;
    while(i < m){
        if(pat[i] == pat[len]){
            lps[i] = len + 1; //including the element itself
            len++;
            i++;
        }else{
            if(len != 0){
                len = lps[len - 1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmpsearch(string pat, string txt){ //O(2*n) time
    int n = txt.length(), m = pat.length();
    int lps[m];
    computelpsarray(pat, lps, m);
    int i = 0, j = 0;
    while(i < n){
        if(txt[i] == pat[j]){
            i++;
            j++;
        }else{
            if(j != 0){
              j = lps[j - 1];
            }else{
                i++;
            }
        }if(j == m){
            cout << i - j;
            j = lps[j - 1];
        }
    }
}

bool areSame(unordered_map<char, int> freq1, unordered_map<char, int> freq2){
    for(auto x : freq1){
        if(freq2.find(x.first) == freq2.end()){
            return false;
        }
        else if(freq2[x.first] < x.second){
            return false;
        }
    }
    return true;
}

bool anagramSearch(string txt, string pat){
    unordered_map<char, int> freq1;
    unordered_map<char, int> freq2;
    for(int i = 0; i < pat.size(); i++){
        freq1[txt[i]]++;
        freq2[pat[i]]++;
    }
    for(int i = pat.size(); i < txt.size(); i++){
        if(areSame(freq1, freq2)){
            return true;
        }
        freq1[txt[i]]++;
        freq1[txt[i - pat.size()]]--;
    }
    return false;
}

int longestSubstring_distinctCharacters(string s){
    unordered_map<char, int> m;
    if(s.size() == 0){
        return 0;
    }
    int start = 0;
    int len = 0;
    for(int i = 0; i < s.size(); i++){
        if(m.find(s[i]) != m.end()){
            m[s[start]]--;
            start++;
        }
        else{
            m[s[i]]++;
            len = max(len, i - start + 1);
        }
    }
    return len;
}

int main(){
    // cout << checkAnagrams("geeks", "ekges");
    // cout << leftmost_repeating_character("abbcd");
    // cout << leftmost_repeatingchar_optimized("smcncj");
    // cout << leftmost_nonrepeating_char("geeksg");
    // cout << lexicographical_rank("STRING");
    // cout << searchAnagrams("geeks", "eegkd");
    // cout << checkRotations("abcd", "abaa");
    // patSearch_naive("ABCABCDFABCD", "ABCD");
    // kmpsearch("aaaa", "aaaab");
    // cout << anagramSearch("geeksforgeeks", "frog");
    cout << longestSubstring_distinctCharacters("aaaaa");
    return 0;
}