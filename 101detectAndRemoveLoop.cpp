// https://www.codingninjas.com/studio/problems/interview-shuriken-42-detect-and-remove-loop_241049
#include <bits/stdc++.h>
using namespace std;
class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

Node* getStartOfLoop(Node* &head){
    if(head == NULL)    return NULL;
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL){
        fast = fast -> next;
        if(fast != NULL)    fast = fast -> next;
        slow = slow -> next;
        if(slow == fast){
            // loop present
            // shift slow to head and exit loop
            slow = head;
            break;
        }
    }
    if(fast == NULL){
        // no loop present
        return NULL;
    }
    else{
        // loop is present
        while(slow != fast){
            slow = slow -> next;
            fast = fast -> next;
        }
        return slow;
    }
}

Node* removeLoop(Node* &head)
{
    if(head == NULL)    return NULL;
    Node* start = getStartOfLoop(head);
    if(start == NULL)   return head;
    Node* temp = start;
    while(temp -> next != start){
        temp = temp -> next;
    }
    temp -> next = NULL;
    return head;
}