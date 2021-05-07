#include<bits/stdc++.h>
using namespace std;

//Longest Substring with k distinct characters
int findLength(const string& str, int k) {
    int maxLength = 0, winSt = 0;
    unordered_map<char, int> freq;
    for(int winEnd = 0; winEnd < str.size(); winEnd++){
      char rightch = str[winEnd];
      freq[rightch]++;
      while(freq.size() > k){
        char leftch = str[winSt];
        freq[leftch]--;
        if(freq[leftch] == 0){
          freq.erase(leftch);
        }
        winSt++;
      }
      maxLength = max(maxLength, winEnd - winSt + 1);
    }
    return maxLength;
}

//Longest substring with no repeating characters
int norepeat(string str){
    int maxLength = 0, st = 0;
    unordered_map<char, int> indexMap;
    for(int end = 0; end < str.size(); end++){
        char rightchar = str[end];
        if(indexMap.find(rightchar) != indexMap.end()){
            st = max(st, indexMap[rightchar] + 1); 
            // in the current window, we will not have any 'rightChar' after its
            // previous index and if 'windowStart' is already ahead of the last index of 'rightChar',
            // we'll keep 'windowStart'
        }
        indexMap[rightchar] = end;
        maxLength = max(maxLength, end - st + 1); 
    }
    return maxLength;
}

int main(){

    return 0;
}