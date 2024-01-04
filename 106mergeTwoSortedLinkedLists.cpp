// https://www.codingninjas.com/studio/problems/merge-two-sorted-linked-lists_800332?leftPanelTabValue=PROBLEM
#include <bits/stdc++.h>
using namespace std;

template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

Node<int>* solve(Node<int>* small, Node<int>* large){
    Node<int>* curr1 = small;
    Node<int>* next1 = small -> next;
    Node<int>* curr2 = large;

    // if only 1 element in first list
    if(small -> next == NULL){
        small -> next = large;
    }

    while(next1 != NULL && curr2 != NULL){
        if((curr2 -> data <= next1 -> data) && (curr2 -> data >= curr1 -> data)){
            curr1 -> next = curr2;
            curr2 = curr2 -> next;
            curr1 -> next -> next = next1;
            curr1 = curr1 -> next;
        }
        else{
            curr1 = curr1 -> next;
            next1 = next1 -> next;

            if(next1 == NULL){
                curr1 -> next = curr2;
                return small;
            }
        }
    }
    return small;
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first == NULL)   return second;
    if(second == NULL)  return first;

    if(first -> data <= second -> data) return solve(first,second);
    else return solve(second,first);


}
