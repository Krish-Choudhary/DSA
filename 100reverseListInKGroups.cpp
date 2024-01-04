// https://www.codingninjas.com/studio/problems/reverse-list-in-k-groups_983644?leftPanelTab=1
#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

Node* kReverse(Node* head, int k) {
    // base case
    if(head == NULL)    return NULL;

    // step 1: reverse first k nodes
    Node* agla = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;

    while(curr != NULL && count < k){
        count++;
        agla = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = agla;
    }

    // If the last group has < k nodes, reversing it again to get the previous order.
    if(count < k){
        curr = prev;
        prev = NULL;
        agla = NULL;
        count = 0;
        while(curr != NULL && count < k){
            agla = curr->next;
            curr->next = prev;
            prev = curr;
            curr = agla;
            count++;
        }
    }

    // step 2: Let recurssion handle
    if(agla != NULL){
        head -> next = kReverse(agla,k);
    }

    // step 3 : return head of reversed link list
    return prev;
}