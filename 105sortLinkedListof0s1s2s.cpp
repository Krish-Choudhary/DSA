// https://www.codingninjas.com/studio/problems/sort-linked-list-of-0s-1s-2s_1071937
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

/*
Node* sortList(Node *head){
    int zero = 0 , one = 0 , two = 0;
    Node* temp = head;
    while(temp != NULL){
        if(temp -> data == 0)   zero++;
        else if(temp -> data == 1)   one++;
        else if(temp -> data == 2)   two++;
        temp = temp -> next;
    }
    temp = head;
    while(temp != NULL){
        if(zero > 0){
            temp -> data = 0;
            zero--;
        }
        else if(one > 0){
            temp -> data = 1;
            one--;
        }
        else if(two > 0){
            temp -> data = 2;
            two--;
        }
        temp = temp -> next;
    }
    return head;
}
*/

/*
void insertAtTail(Node* &tail , Node* curr){
    tail -> next = curr;
    tail = curr;
}

Node* sortList(Node *head){
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    Node* curr = head;

    // Create separate lists of 0,1 and 2

    while(curr != NULL){
        int value = curr -> data;
        if(value == 0)  insertAtTail(zeroTail , curr);
        else if(value == 1)  insertAtTail(oneTail , curr);
        else if(value == 2)  insertAtTail(twoTail , curr);
        curr = curr -> next;
    }

    // Merge 3 list
    if(oneHead -> next != NULL){   // 1s list non-empty
        zeroTail -> next = oneHead -> next;
    }
    else{   // 1s list empty
        zeroTail -> next = twoHead -> next;
    }
    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;
    head = zeroHead -> next;

    // delete dummy nodes
    delete(zeroHead);
    delete(oneHead);
    delete(twoHead);
    return head;
}
*/

Node* sortList(Node *head){
    Node* curr = head -> next;
    Node* prev = head;
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp -> next;
    }
    Node* tail = temp;
    delete(temp);
    if(prev->data == 2){
        tail -> next = prev;
        head = prev -> next;
        prev -> next = NULL;
        prev = head;
        curr = curr -> next;
    }
    while(curr != NULL){
        if(curr -> data == 0){
            prev -> next = curr -> next;
            curr -> next = head;
            head = curr;
            curr = prev -> next;
        }
        else if(curr -> data == 2){
            prev -> next = curr -> next;
            tail -> next = curr;
            curr -> next = NULL;
            curr = prev -> next;
        }
        else if(curr -> data == 1){
            curr = curr -> next;
            prev = prev -> next;
        }
    }
    return head;
}