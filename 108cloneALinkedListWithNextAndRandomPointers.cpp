// https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* arb;

    Node(int x){
        data = x;
        next = NULL;
        arb = NULL;
    }
};

class Solution
{
    // TC = O(n)
    // SC = O(1)
    // private:
    // void insertAtTail(Node* &head, Node* &tail, int val){
    //     Node* temp = new Node(val);
        
    //     if(head == NULL){
    //         head = temp;
    //         tail = temp;
    //         return;
    //     }
    //     tail -> next = temp;
    //     tail = temp;
    // }
    public:
    // Node *copyList(Node *head)
    // {
    //     // step - 1 => Create a clone LL with next pointers
    //     Node* cloneHead = NULL;
    //     Node* cloneTail = NULL;
    //     Node* temp = head;
    //     while(temp != NULL){
    //         insertAtTail(cloneHead, cloneTail, temp -> data);
    //         temp = temp -> next;
    //     }
            
    //     // step - 2 => Map
    //     unordered_map <Node*, Node*> originalToClone;
    //     temp = head;
    //     Node* temp2 = cloneHead;
    //     while(temp != NULL){
    //         // no need to check temp2 as they are same
    //         originalToClone[temp] = temp2;
    //         temp = temp -> next;
    //         temp2 = temp2 -> next;
    //     }
    //     temp = head;
    //     temp2 = cloneHead;
    //     // copy random pointers
    //     while(temp2 != NULL){
    //         // no need to check temp as they are same
    //         temp2 -> arb = originalToClone[temp -> arb];
    //         temp = temp -> next;
    //         temp2 = temp2 -> next;
    //     }
    //     return cloneHead;
        // }
    
    Node *copyList(Node *head){
        if(head == NULL)    return head;
        Node* originalNode = head;
        // step - 1 + 2 => creating clone node and adding inbetween originalNodes
        while(originalNode != NULL){
            Node* temp = new Node(originalNode -> data);
            temp -> next = originalNode -> next;
            originalNode -> next = temp;
            originalNode = temp -> next;
        }
        originalNode = head;
        Node* cloneHead = head -> next;
        // step - 3 => random pointers set
        while(originalNode != NULL){
            if(originalNode -> arb == NULL) originalNode -> next -> arb = NULL;
            else    originalNode -> next -> arb = originalNode -> arb -> next;
            originalNode = originalNode -> next -> next;
        }
        
        // step - 4 => revert changes done in step 2
        originalNode = head;
        
        while(originalNode != NULL){
            head = originalNode -> next -> next;
            if(head != NULL)    originalNode -> next -> next = head -> next;
            else    originalNode -> next -> next = NULL;
            originalNode -> next = head;
            originalNode = head;
        }
        return cloneHead;
    }

};