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
    public:
    trieNode* root;

    trie(){
        root = new trieNode('\0');
    }

    void insertUtil(trieNode* root, string word){
        // base case
        if(word.length() == 0){
            root -> isTerminal = true;
            return;
        }

        // assumption word will be capital
        int index = word[0] - 'A';
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

    void insertWord(string word){
        insertUtil(root, word);
    }
    
    bool searchUtil(trieNode* root, string word){
        if(word.length() == 0){
            return root -> isTerminal;  // true if terminal node else false
        }

        int index = word[0] - 'A';
        trieNode* child;

        if(root -> children[index] != NULL){
            // present
            child = root -> children[index];
        }
        else{
            // absent
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word){
        return searchUtil(root, word);
    }

    bool haveNoChild(trieNode* root){
        for(int i = 0; i < 26; i++){
            if(root -> children[i] != NULL) return false;
        }
        return true;
    }

    void deletionUtil(trieNode* root, string word){
        if(word.length() == 0){
            if(root -> isTerminal == false){
                cout << "word not present" << endl;
                return;
            }
            else{
                root -> isTerminal = false;
                if(haveNoChild(root))   delete root;
                cout << "Word deleted" << endl;
                return;
            }
        }
        int index = word[0] - 'A';
        trieNode* child;

        if(root -> children[index] != NULL){
            // present
            child = root -> children[index];
        }
        else{
            cout << "word not present" << endl;
            return;
        }
        deletionUtil(child, word.substr(1));
    }

    void deletion(string word){
        deletionUtil(root, word);
    }
    
};

int main(){

    trie *t = new trie();
    t -> insertWord("ABCD");
    t -> insertWord("HELLO");
    t -> insertWord("HIVE");
    cout << "Is \"AB\" present: " << t -> searchWord("AB") << endl;
    cout << "Is \"ABCD\" present: " << t -> searchWord("ABCD") << endl;
    cout << "Is \"HIVE\" present: " << t -> searchWord("HIVE") << endl;
    t -> deletion("HIVE");
    cout << "Is \"HIVE\" present: " << t -> searchWord("HIVE") << endl;

    return 0;
}





// https://www.naukri.com/code360/problems/implement-trie_631356?leftPanelTabValue=PROBLEM
/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

/*
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

class Trie {

public:
    trieNode* root;
    // Initialize your data structure here. 
    Trie() {
        root = new trieNode('\0');
    }

    // Inserts a word into the trie. 
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
    void insert(string word) {
        insertUtil(root, word);
    }

    // Returns if the word is in the trie. 
    bool searchUtil(trieNode* root, string word){
        if(word.length() == 0){
            return root -> isTerminal;  // true if terminal node else false
        }

        int index = word[0] - 'a';
        trieNode* child;

        if(root -> children[index] != NULL){
            // present
            child = root -> children[index];
        }
        else{
            // absent
            return false;
        }

        return searchUtil(child, word.substr(1));
    }
    bool search(string word) {
        return searchUtil(root, word);
    }

    // Returns if there is any word in the trie that starts with the given prefix. 


    bool startsWithHelp(trieNode* root, string word){
        if(word.length() == 0){
            return true;
        }

        int index = word[0] - 'a';
        trieNode* child;

        if(root -> children[index] != NULL){
            // present
            child = root -> children[index];
        }
        else{
            // absent
            return false;
        }

        return startsWithHelp(child, word.substr(1));
    }
    bool startsWith(string prefix) {
        return startsWithHelp(root, prefix);
    }
};
*/