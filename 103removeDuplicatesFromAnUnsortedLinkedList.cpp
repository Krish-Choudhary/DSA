// https://www.codingninjas.com/studio/problems/remove-duplicates-from-unsorted-linked-list_1069331
#include <bits/stdc++.h> 
using namespace std;
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

Node *removeDuplicates(Node *head)
{
    if(head == NULL)    return head;
    
    unordered_map<int,bool> visited;
    // Its getting TLE with normal map
    Node* prev = head;
    Node* curr = head;
    
    while(curr != NULL){
        if(visited[curr->data] != true){
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
        else{
            prev -> next = curr -> next;
            Node* temp = curr;
            curr = curr -> next;
            delete(temp);
        }
    }
    return head;
}