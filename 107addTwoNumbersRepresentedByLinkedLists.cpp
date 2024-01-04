// https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution
{
    private:
    struct Node* reverse(struct Node* head){
        Node* curr = head;
        Node* prev = NULL;
        Node* next1 = NULL;
        while(curr != NULL){
            next1 = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next1;
        }
        return prev;
    }
    
    void insertAtTail(struct Node* &head, struct Node* &tail, int val){
        Node* temp = new Node(val);
        if(head == NULL){
            head = temp;
            tail = temp;
        }
        else{
            tail -> next = temp;
            tail = temp;
        }
    }
    
    struct Node* add(struct Node* first, struct Node* second){
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        int carry = 0;
        while(first != NULL || second != NULL || carry != 0){
            int val1 = 0, val2 = 0;
            if(first != NULL){
                val1 = first -> data;
                first = first -> next;
            }
            if(second != NULL){
                val2 = second -> data;
                second = second -> next;
            }
            int sum = carry + val1 + val2;
            carry = sum / 10;
            // create Node and add in ans LL
            insertAtTail(ansHead, ansTail, sum % 10);
        }
        return ansHead;
    }
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        // step - 1 => reverse LL
        first = reverse(first);
        second = reverse(second);
        
        // step - 2 => add LL
        Node* ans = add(first, second);
        
        // step -3 => reverse ans;
        return reverse(ans);
        
    }
};