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