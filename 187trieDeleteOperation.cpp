// https://www.naukri.com/code360/problems/trie-delete-operation_1062663
#include <bits/stdc++.h> 
using namespace std;
class TrieNode {                        //Definition of TrieNode class
public:
    TrieNode * children[26];
    bool isEnd;
    TrieNode()
    {
        isEnd=false;
        for(int i=0;i<26;i++)
            children[i]=NULL;
    }

};
bool haveNoChild(TrieNode* root){
    for(int i = 0; i < 26; i++){
        if(root -> children[i] != NULL) return false;
    }
    return true;
}
void deletionUtil(TrieNode* root, string word){
        if(word.length() == 0){
            if(root -> isEnd == false){
                return;
            }
            else{
                root -> isEnd = false;
                if(haveNoChild(root))   delete root;
                return;
            }
        }
        int index = word[0] - 'a';
        TrieNode* child;

        if(root -> children[index] != NULL){
            // present
            child = root -> children[index];
        }
        else{
            return;
        }
        deletionUtil(child, word.substr(1));
        if(haveNoChild(root))   delete root;
    }

TrieNode* deleteWord(TrieNode* root, string word) {
  deletionUtil(root, word);
  return root;
}

