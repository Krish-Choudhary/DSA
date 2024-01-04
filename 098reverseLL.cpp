#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/reverse-linked-list_920513

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };
        


void reverse(Node* &head , Node* curr , Node* prev){
  if (curr == NULL) {
    head = prev;
    return;
  }
  Node* forward = curr -> next;
  reverse(head, forward, curr);
  curr -> next = prev;
}

Node* reverse1(Node* head){
    if(head == NULL || head -> next == NULL){       // base case empty or 1 node LL
        return head;
    }
    Node *chotaHead = reverse1(head -> next);   // recurssively reverse the LL and return head of reversed LL
    head -> next -> next = head;
    head -> next = NULL;
    return chotaHead;
}

Node* reverseLinkedList(Node *&head)
{
    return reverse1(head);
    /*Node* prev = NULL;
    Node* curr = head;
    reverse(head, curr, prev);
    return head;*/



    /* if(head == NULL || head -> next == NULL){       // empty or 1 node LL
        return head;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    while(curr != NULL){
        forward = curr -> next; 
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;*/
    
}
