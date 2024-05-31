// https://www.naukri.com/code360/problems/merge-k-sorted-lists_992772
#include <bits/stdc++.h>
using namespace std;

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

class compare{
    public:
    bool operator()(Node* a, Node* b){
        return a -> data > b -> data;
    }
};

Node* mergeKLists(vector<Node*> &listArray){
    priority_queue<Node*, vector<Node*>, compare> minHeap;
    for(auto node: listArray){
        if(node != NULL)    minHeap.push(node);
    }

    Node* head = NULL;
    Node* tail = NULL;

    while(!minHeap.empty()){
        if(head == NULL){
            head = minHeap.top();
            tail = head;
        }
        else{
            tail -> next = minHeap.top();
            tail = tail -> next;
        }
        minHeap.pop();
        if(tail -> next != NULL)    minHeap.push(tail -> next);
    }
    return head;
}
