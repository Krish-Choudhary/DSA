// https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		string FirstNonRepeating(string A){
		    unordered_map<char, int> count;
		    queue<char> q;
		    string ans;
		    int n = A.length();
		    for(int i = 0; i < n; i++){
		        char ch = A[i];
		        count[ch]++;
		        if(count[ch] == 1)  q.push(ch);
		        while(!q.empty()){
		            if(count[q.front()] > 1)    q.pop();
		            else{
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        if(q.empty())   ans.push_back('#');
		    }
		    return ans;
		}

};