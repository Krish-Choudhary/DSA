#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
};

void splitList(Node *head, Node **head1_ref,
                           Node **head2_ref) 
{ 
    Node *slow = head; 
    Node *fast = head; 
     
    if(head == NULL) 
        return; 
     
    /* If there are odd nodes in the circular list then 
       fast->next becomes head and for even nodes 
       fast->next->next becomes head */
    while(fast->next != head && 
          fast->next->next != head) 
    { 
        fast = fast->next->next; 
        slow = slow->next; 
    } 
     
    /* If there are even elements in list
       then move fast_ptr */
    if(fast->next->next == head) 
        fast = fast->next; 
         
    /* Set the head pointer of first half */
    *head1_ref = head; 
         
    /* Set the head pointer of second half */
    if(head->next != head) {
        // This condition is used to remove the case of LL with a single node
        *head2_ref = slow->next; 
    }
         
    /* Make second half circular */
    fast->next = slow->next; 
         
    /* Make first half circular */
    slow->next = head; 
}