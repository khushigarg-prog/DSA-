#include<iostream>
using namespace std;
// Class for creating a node
class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next = NULL;
    }
};

// Class for creating a circular LL from nodes
class CircularList{
    Node* head;
    Node* tail;
    public:
    CircularList(){
        head=tail=NULL;
    }

    // Func to insert element at head
    void insertAtHead(int val){
        // To insert first create h node which is to be inserted
        Node* newNode = new Node(val);
        // Then check for the cases that if head==null or there is an element present there
        if(head==NULL){
            head=tail=newNode;
            tail->next=head; // kyuki tail head se bhi connected hoti h circular ll m
        }
        else{
            newNode->next=head; // for making connection
            head=newNode; 
            tail->next=head; // to connect head and tail
        }
    }

    // Func for printing ll
    void print(){
        if(head==NULL) return;
        cout<<head->data<<"->";
        // phir ek temp ptr lo to keep head preserve
        Node* temp = head->next;
        while(temp!=head){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<temp->data<<endl;
    }

    // Func for insert element at tail
    void insertAtTail(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head=tail=newNode;
            tail->next=head;
        }
        else{
            newNode->next=head;
            tail->next= newNode;
            tail=newNode;
        }
    }

    // Func for del element from head
    void deleteAtHead(){
        if(head==NULL) return;
        // if there is only single element in LL
        else if(head==tail){
            delete head;
            head=tail=NULL;
        }
        else{
            Node* temp = head;
            head=head->next;
            tail->next=head;
            temp->next=NULL;
            delete temp;
        }
    }

    // Func for delete element from tail
    void deleteAtTail(){
        if(head==NULL) return;
        else if(head==tail){
            delete head;
            head=tail=NULL;
        }
        else{
            Node* temp = tail;
            Node* prev = head;
            while(prev->next != tail){
                prev=prev->next;
            }
            tail=prev;
            tail->next=head;
            temp->next=NULL;
            delete temp;
        }
    }
};

int main(){
    CircularList cll;
    cll.insertAtTail(1);
    cll.insertAtTail(2);
    cll.insertAtTail(3);
    // cll.deleteAtHead();
    cll.deleteAtTail();
    cll.print();

}