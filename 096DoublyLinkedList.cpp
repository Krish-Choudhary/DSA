#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* prev = NULL;
    node* next = NULL;

    // constructor
    node(int d){
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }

    // destructor
    ~node() {
        int val = this -> data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data "<< val << endl;
    }
};

void print(node* &head){
    node *temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int getLength(node * &head){
    node *temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}

void insertAtHead(node* &head , int d){
    node* newNode = new node(d);
    if(head == NULL){   // empty LL
        head = newNode;
        return;
    }
    newNode -> next = head;
    head -> prev = newNode;
    head = newNode;
}

void insertAtTail(node* &head , int d){
    node* newNode = new node(d);
    if(head == NULL){   // empty LL
        head = newNode;
        return;
    }
    node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
    newNode -> prev = temp;
}

void insertAtPosition(node* &head , int position , int val){
    if(position == 1){      // insert at head case
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
    newNode -> prev = temp;
    temp -> next = newNode;
    newNode -> next -> prev = newNode;
}

void deleteNode(int position, node* & head) { 
    if(position == 1) {     //deleting first or start node
        node* temp = head;
        head = head -> next;
        head -> prev = NULL;
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
    curr -> prev = NULL;
    prev -> next = curr -> next;
    curr -> next = NULL;
    delete curr;
}

int main(){
    node* newNode = new node(10);
    node* head = newNode;
    print(head);
    cout << getLength(head) << endl;
    insertAtHead(head,5);   // 5 10
    print(head);
    cout << endl;
    insertAtTail(head,3);   // 5 10 3
    print(head);
    cout << endl;

    insertAtPosition(head,4,4);     // 5 10 3 4
    print(head);
    cout << endl;

    insertAtPosition(head,4,78);    // 5 10 3 78 4
    print(head);
    cout << endl;

    deleteNode(1,head);    // 10 3 78 4
    print(head);
    cout << endl;

    deleteNode(3,head);    // 10 3 4
    print(head);
    cout << endl;
    return 0;
}