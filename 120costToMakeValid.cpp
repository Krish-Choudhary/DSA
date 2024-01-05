// https://www.codingninjas.com/studio/problems/minimum-cost-to-make-string-valid_1115770
#include <bits/stdc++.h>
using namespace std;

int findMinimumCost(string str) {
  int n = str.length();
  if(n % 2 == 1)  return -1;
  stack<char> st;
  for(int i = 0; i < n; i++){
    char ch = str[i];
    if (!st.empty() && st.top() == '{' && ch == '}')  st.pop();
    else  st.push(ch);
  }

  int a = 0, b = 0;
  while(!st.empty()){
    if(st.top() == '{') a++;
    else  b++;
    st.pop();
  }
  return ((a + 1) / 2) + ((b + 1) / 2);
}