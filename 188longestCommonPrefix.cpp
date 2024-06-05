// https://www.naukri.com/code360/problems/longest-common-prefix_2090383
#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans;
    for(int i = 0; i < arr[0].length(); i++){
        // traversing 1st string
        char ch = arr[0][i];

        for(int j = 1; j < n; j++){
            // if not match
            if(ch != arr[j][i]) return ans;
        }
        // if it comes here that means ch matches
        ans.push_back(ch);
    }
    return ans;
}
// TC = O(mn)
// SC = O(1)

/*
class trieNode{
    public:
    char ch;
    trieNode* children[26];
    int childCount;
    bool isTerminal;

    trieNode(char ch){
        this -> ch = ch;
        for(int i = 0; i < 26; i++) children[i] = NULL;
        childCount = 0;
        isTerminal = false;
    }
};

class trie{
    private:
    void insertUtil(trieNode* root, string word){
        // base case
        if(word.length() == 0){
            root -> isTerminal = true;
            return;
        }

        // assumption word will be capital
        int index = word[0] - 'a';
        trieNode* child;
        if(root -> children[index] != NULL){
            // present
            child = root -> children[index];
        }
        else{
            // absent
            child = new trieNode(word[0]);
            root -> childCount++;
            root -> children[index] = child;
        }

        // Recursion
        insertUtil(child, word.substr(1));
    }

    public:
    trieNode* root;
    
    trie(){
        root = new trieNode('\0');
    }

    void insertWord(string word){
        insertUtil(root, word);
    }

    void lcp(string str, string &ans){
        for(int i = 0; i < str.length(); i++){
            char ch = str[i];
            if(root -> childCount == 1){
                ans.push_back(ch);
                int index = ch -'a';
                root = root -> children[index];
            }
            else    return;
            if(root -> isTerminal)  return;
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    trie *t = new trie();

    for(int i = 0; i < n; i++){
        t -> insertWord(arr[i]);
    }

    string first = arr[0];
    string ans;
    t -> lcp(first, ans);
    return ans;
}
// TC = O(mn)
// SC = O(mn)
*/