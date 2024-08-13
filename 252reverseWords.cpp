// https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1
#include <bits/stdc++.h>
using namespace std;

string reverseWords(string S){ 
    string ans = "", temp = "";
    int n = S.length();
    for(int i = n - 1; i >= 0; i--){
        if(S[i] == '.'){
            reverse(temp.begin(), temp.end());
            ans += temp;
            ans.push_back('.');
            temp = "";
        }
        else    temp.push_back(S[i]);
    }
    // last word
    reverse(temp.begin(), temp.end());
    ans += temp;
    return ans;
} 