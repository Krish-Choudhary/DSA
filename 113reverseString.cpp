#include <bits/stdc++.h>
using namespace std;

// reverse a string using stack

int main(){
    string s;
    cin >> s;
    stack<char> st;

    for(int i = 0; i < s.length(); i++){
        st.push(s[i]);
    }

    string ans = "";

    while (!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    
    cout << ans;

    return 0;
}