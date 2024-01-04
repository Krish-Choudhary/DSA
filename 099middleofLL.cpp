// https://www.codingninjas.com/studio/problems/middle-of-linked-list_973250
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



Node *findMiddle(Node *head) {
    if(head == NULL || head -> next == NULL)    return head;
    Node* slow = head;
    Node* fast = head -> next;
    while(fast != NULL){
        slow = slow -> next;
        fast = fast -> next;
        if(fast != NULL){   // Even number of elements vala case
            fast = fast -> next;
        }
    }
    return slow;
}




// Node *findMiddle(Node *head) {

//     // Write your code here

//     int count=0;

//    Node* temp=head;

//    if(head==NULL) return NULL;

//    if(head->next==NULL) return head;

//     while(temp!=NULL){

//        count++;

//        temp=temp->next;

//     }

//     int mid=(count/2);

//     temp=head;

//     for(int i=1;i<=mid;i++){

//         temp=temp->next;

//     }

//   return temp;

// }

