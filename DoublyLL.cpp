#include<iostream>
using namespace std;
// class for creating a node
class Node{
    // Node of Doubly LL contains val, next pointer & prev pointer
    public:
    int data; 
    Node* next;
    Node* prev;

    // Constructor for initializing the value
    Node(int val){
        data=val;
        next=prev=NULL;
    }
};

// Class that will actually link all the created nodes
class DoublyList{
    Node* head;
    Node* tail;
    public:
    // Constructor
    DoublyList(){
        head=tail=NULL;
    }

    // push_front func to push elements from front
    void push_front(int val){
        // Step 1 : Create a newNode first to push it
        Node* newNode = new Node(val);

        // Case1: If head is empty & Cse2: If head is not empty
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            newNode->next=head; // to establish connection
            head->prev=newNode; // to establich connection
            head=newNode; // made newnode the head
        }
    }

    // Func to print the Doubly LL
    void print(){
        Node* temp=head;
        while(temp != NULL){
            cout<<temp->data<<" <=> ";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }

    // Func to push_back elements
    void push_back(int val){
        Node* newNode= new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            newNode->prev=tail;
            tail->next=newNode;
            tail=newNode;
        }
    }

    // Func to pop_front elements
    void pop_front(){
        if(head==NULL) return;
        // Create a node temp pointing to head so that we could del that rather than head
        Node* temp = head;
        head=head->next;
        if(head!=NULL){
            head->prev=NULL;
        }
        temp->next=NULL;
        delete temp;
    }

    // Func to pop_back elements
    void pop_back(){
        if(head==NULL) return;
        Node* temp = tail;
        tail=tail->prev;
        if(tail!=NULL){
            tail->next=NULL;
        }
        temp->prev=NULL;
        delete temp;
    }
};
int main(){
    DoublyList dll;
    // dll.push_front(1);
    // dll.push_front(2);
    // dll.push_front(3);
    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);
    dll.pop_front();
    dll.pop_back();
    dll.print();
}