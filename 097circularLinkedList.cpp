#include <iostream>
#include <map>
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

void insertNode(node* &tail , int element, int d){
    if(tail == NULL){       // empty LL
        node* newNode = new node(d);
        tail = newNode;
        newNode -> next = tail;
        return;
    }
    // non-empty LL
    node* curr = tail;
    while(curr -> data != element){
        curr = curr -> next;
    }
    // element present at curr
    node* newNode = new node(d);
    newNode -> next = curr -> next;
    curr -> next = newNode;
}

void print(node* &tail){
    node *temp = tail;
    do{
        cout << temp -> data << " ";
        temp = temp -> next;
    }while(temp != tail);
    
    cout << endl;
}

void deleteNode(node* &tail, int value) {

    if(tail == NULL) {      //empty list
        cout << " List is empty, please check again" << endl;
        return;
    }
    //non-empty
    //assuming that "value" is present in the Linked List
    node* prev = tail;
    node* curr = prev -> next;

    while(curr -> data != value) {
        prev = curr;
        curr = curr -> next;
    }

    prev -> next = curr -> next;

    //1 Node Linked List
    if(curr == prev) {
        tail = NULL;
    }

    //>=2 Node linked list
    else if(tail == curr ) {
        tail = prev;
    }

    curr -> next = NULL;
    delete curr;

}

bool detectLoop(node* head){
    if(head == NULL)    return false;
    map<node* , bool> visited;
    node* temp = head;
    while(temp != NULL || visited[temp] == false){
        if(visited[temp] == true)   return true;
        visited[temp] = true;
        temp = temp -> next;
    }
    return false;
}

bool floydDetectLoop(node* head){
    if(head == NULL)    return false;
    node* slow = head;
    node* fast = head;
    while(fast != NULL){
        fast = fast -> next;
        if(fast != NULL)    fast = fast -> next;
        slow = slow -> next;
        if(slow == fast)    return true;
    }
    return false;
}

node* getStartOfLoop(node* head){
    if(head == NULL)    return NULL;
    node* slow = head;
    node* fast = head;
    while(fast != NULL){
        fast = fast -> next;
        if(fast != NULL)    fast = fast -> next;
        slow = slow -> next;
        if(slow == fast){
            // loop present
            // shift slow to head and exit loop
            slow = head;
            break;
        }
    }
    if(fast == NULL){
        // no loop present
        return NULL;
    }
    else{
        // loop is present
        while(slow != fast){
            slow = slow -> next;
            fast = fast -> next;
        }
        return slow;
    }
}

void removeLoop(node* head){
    if(head == NULL)    return;
    node* start = getStartOfLoop(head);
    node* temp = start;
    while(temp -> next != start){
        temp = temp -> next;
    }
    temp -> next = NULL;
}

int main(){
    node* tail = NULL;
    insertNode(tail , 0 , 2);   // empty LL
    print(tail);
    insertNode(tail , 2 , 8);
    print(tail);
    insertNode(tail , 2 , 87);
    print(tail);
    return 0;
}