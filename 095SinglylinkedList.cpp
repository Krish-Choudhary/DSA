#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    // constructor
    node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    
    // destructor
    ~node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};

void insertAtHead(node* &head, int d){
    node* newNode = new node(d);
    newNode -> next = head;
    head = newNode;
}

// void insertAtTail(node * &tail , int d){
//     node* newNode = new node(d);
//     tail -> next = newNode;
//     tail = newNode;
// }
void insertAtTail(node * &head , int d){
    node *newNode = new node(d);
    if(head == NULL){
        // empty LL
        head = newNode;
        return;
    }
    node *temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
}

// void insertAtPosition(node* &head , node* &tail , int position , int val){
//     if(position == 1){
//         // insert at head case
//         insertAtHead(head,val);
//         return;
//     }
//     node *temp = head;
//     int currentPosition = 1;    // head is at position 1
//     while(currentPosition < position - 1){
//         temp = temp -> next;
//         currentPosition++;
//     }
//     if(temp -> next == NULL){
//         insertAtTail(tail,val);
//         return;
//     }
//     node* newNode = new node(val);
//     newNode -> next = temp -> next;
//     temp -> next = newNode;
// }

void insertAtPosition(node* &head , int position , int val){
    if(position == 1){
        // insert at head case
        insertAtHead(head,val);
        return;
    }
    node *temp = head;
    int currentPosition = 1;    // head is at position 1
    while(currentPosition < position - 1){
        temp = temp -> next;
        currentPosition++;
    }
    if(temp -> next == NULL){
        insertAtTail(head,val);
        return;
    }
    node* newNode = new node(val);
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

void deleteNode(int position, node* & head) { 
    if(position == 1) {     //deleting first or start node
        node* temp = head;
        head = head -> next;
        //memory free start node
        temp -> next = NULL;
        delete temp;
        return;
    }
    //deleting any middle node or last node
    node* curr = head;
    node* prev = NULL;
    int cnt = 1;
    while(cnt < position) {
        prev = curr;
        curr = curr -> next;
        cnt++;
    }
    prev -> next = curr -> next;
    curr -> next  = NULL;
    delete curr;
}

void print(node* &head){
    node *temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main(){
    node* node1 = new node(10);
    node *head = node1;
    node *tail = node1;
    // cout << node1 -> data << endl;
    // cout << node1 -> next << endl;      // NULL
    insertAtHead(head,54);
    // print(head);
    insertAtHead(head,4);
    print(head);
    cout << endl;
    // 4 54 10
    insertAtTail(head,45);
    print(head);    // 4 54 10 45
    cout << endl;
    insertAtPosition(head,3,3);
    print(head);    // 4 54 3 10 45
    cout << endl;
    deleteNode(3,head);
    print(head);    // 4 54 10 45
    cout << endl;
    deleteNode(4,head);
    print(head);    // 4 54 10
    cout << endl;
    return 0;
}