// https://www.codingninjas.com/studio/problems/mergesort-linked-list_630514

#include <bits/stdc++.h>
using namespace std;

class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };

node* findMid(node* head){
    node* slow = head;
    node* fast =head -> next;
    while(fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
}

node* merge(node* left, node* right){
    if(left == NULL)    return right;
    if(right == NULL)   return left;

    node* ans = new node(-1);
    node* temp = ans;

    while(left != NULL && right != NULL){
        if(left -> data <= right -> data){
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else{
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }
    while(left != NULL){
        temp -> next = left;
        temp = left;
        left = left -> next;
    }
    while(right != NULL){
        temp -> next = right;
        temp = right;
        right = right -> next;
    }
    return ans -> next;
}

node* mergeSort(node *head) {
    // base case
    if(head == NULL || head -> next == NULL)    return head;

    // finding mid
    node* mid = findMid(head);

    // defining left and right halves
    node* left = head;
    node* right = mid -> next;

    // break both halves
    mid -> next = NULL;

    // recurssive calls to sort halves
    left = mergeSort(left);
    right = mergeSort(right);

    // merging two sorted arrays
    return merge(left, right);
}
