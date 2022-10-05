#include<iostream>
#include<map>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

// delete the loop
    ~Node(){
        int val = this -> data;
        if(this -> next != NULL){
            delete next;
            next = NULL;
        }
        cout << "memory is free for node with data" << this -> data << endl;
    }
};
// place the data at element given

void insertNode(Node* &tail, int element, int data){
    if(tail == NULL){
        Node* temp = new Node(data);
        tail -> next = temp;
        tail = temp;
        return; 
    }else{
        Node* curr = tail;
        while(curr -> data != element){
            curr = curr -> next;
        }

        // element found and cur is pointing on the element
        Node* temp = new Node(data);
        temp -> next = curr -> next;
        curr -> next = temp;

    }
}

// pure circular ie head to head

bool iscircular(Node* head){
    // NULL Linked List
    if(head == NULL){
        return true;
    }

   
    Node* temp = head -> next;
    while(temp != head && temp != NULL) {
        temp = temp -> next;   
    }

    if(temp == head) {
        return true ;
    }

    return false;

}

void print(Node* tail){

    Node* temp = tail;

    if(tail == NULL){
        cout << "empty linked list" << endl; 
    }

    do{
        cout << tail -> data << " ";
        tail = tail -> next;
    }while(tail != temp);
    cout << endl;
}

void deleteNode(Node* &tail, int value) {
    // NULL pointer
    if(tail == NULL){
        cout << "it is a NULL pointer" << endl;
    }else{

        Node* pre = tail;
        Node* curr = tail -> next;

        while(curr -> data != value){
            pre = pre -> next;
            curr = curr -> next;
        }
        pre -> next = curr -> next;
// for 1 linked list
        if(curr == pre){
            tail = NULL;
        }
// >2 linked list
        if(tail == curr){
            tail = pre;
        }
        curr -> next = NULL;
        delete curr;
    }
}

// https://www.geeksforgeeks.org/floyds-cycle-finding-algorithm/

bool floydcycle(Node* tail) {

    if(tail == NULL){
        return false ;
    }
    Node* fast = tail;
    Node* slow = tail;
    while(fast != NULL || slow != NULL ) {
        fast = fast -> next;

        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow ->next;

        if(slow == fast) {
            return true ;
        }
    }

    if(fast == slow) {
        return true;
    }

    return false;
}

// takes the head and if slow and fast meet then loop is present
Node* floydDetectLoop(Node* tail) {
    
    if(tail == NULL){
        return NULL ;
    }
    Node* fast = tail;
    Node* slow = tail;
    while(fast != NULL || slow != NULL ) {
        fast = fast -> next;

// condition to check for SGMFAULT
        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow ->next;

// every time they will meet at junction si not true
        if(slow == fast) {
            return slow ;
        }
    }
    return NULL;
}

void removeLoop(Node* head) {
    if(head == NULL) {
        return;
    }

    Node* StartingOfLoop = getStarting(head);
    Node* temp = StartingOfLoop;

    while(temp -> next != StartingOfLoop) {
        temp = temp -> next;
    }
    temp -> next = NULL;
    return;
}


Node* getStarting(Node* head) {

    if(head == NULL){
        return NULL;
    }
// there is an algo which states that one node starting from head and other from floyd intersection meets at a place where loop begin...
    Node* interaction =  floydDetectLoop(head);
    Node* slow = head;

    while(slow != interaction) {
        slow = slow -> next;
        interaction = interaction -> next;
    }

    return slow;
} 

// DETECT DUPLICATE ELEMENT CYCLE
bool detectLoop(Node* tail) {
    if(tail == NULL)
        return false;

    Node* temp = tail;
    map<Node*, bool> visited;

    while(temp != NULL) {
        if(visited[temp] == true) {
            return true;  //1
        }
        visited[temp] = true;
        temp = temp -> next;
    }
    return false;  //0
}

int main(){

    Node* tail = NULL;

    insertNode(tail, 5 ,5);
    print(tail);
    insertNode(tail, 5 ,15);
    print(tail);
    insertNode(tail, 5 ,16);
    print(tail);
    insertNode(tail, 5 ,17);
    print(tail);
    insertNode(tail, 5 ,18);
    print(tail);

    deleteNode(tail, 5);
    print(tail);

    if(iscircular(tail)){
        cout << "its circular" << endl;
    }

    if(detectLoop(tail)){
        cout << "Loop Detected" << endl;
    }

    if(floydcycle(tail)){
        cout << "Loop Detected by floyds method" << endl;
    }

    Node* start = getStarting(tail);

    cout << "starting at  " << start -> data << endl;

    

    return 0;
}