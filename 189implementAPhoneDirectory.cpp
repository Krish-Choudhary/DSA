// https://www.naukri.com/code360/problems/implement-a-phone-directory_1062666

#include <bits/stdc++.h>
using namespace std;

class trieNode{
    public:
    char data;
    trieNode* children[26];
    bool isTerminal;

    trieNode(char ch){
        data = ch;
        for(int i = 0; i < 26; i++) children[i] = NULL;
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

    void printSuggestions(trieNode* curr, vector<string> &temp, string prefix){
        if(curr -> isTerminal){
            temp.push_back(prefix);
        }

        for(char ch = 'a'; ch <= 'z'; ch++){
            trieNode* next = curr -> children[ch - 'a'];

            if(next != NULL){
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string str){
        trieNode* prev = root;
        vector<vector<string>> output;
        string prefix;
        for(int i = 0; i < str.length(); i++){
            char lastch = str[i];
            prefix.push_back(lastch);

            // check for lastch
            trieNode* curr = prev -> children[lastch - 'a'];

            // if not found
            if(curr == NULL)    break;
            // if found
            vector<string> temp;
            printSuggestions(curr, temp, prefix);

            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }
    
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    trie *t = new trie();

    for(int i = 0; i < contactList.size(); i++) t -> insertWord(contactList[i]);

    return t -> getSuggestions(queryStr);
}
// TC = O(NM^2)
// SC = O(NM)