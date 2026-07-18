#include<iostream>
using namespace std;
class Node{ // class to create individual nodes
    public:
    int data;
    Node* next; // stores the address of next pointer
    // now will create a constructor
    Node(int val){
        data=val;
        next=NULL;
    }
};

class List{
    // class to combine those created individual nodes to form a linked list
    // As we know head & tail are must for linked list..these can be declared as private
    Node* head;
    Node* tail;
    public:
    // Constructor
    List(){
        head=tail=NULL; // because initially node is empty
    }
    // FUNCTION TO PUSH ELEMENTS FROM FIRST
    void push_front(int val){
        Node* newNode = new Node(val); // dynamic
        if(head==NULL){
            head=tail=newNode;
            return;
        }
        else{
            newNode->next = head; // to make the connection
            head=newNode;
        }
    }
    // FUNCTION TO PUSH ELEMENTS FROM END
    void push_back(int val){
        // create a new node
        Node* newNode = new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            tail->next=newNode; // to establish connection
            tail = newNode;
        }
    }
    // FUNCTION TO POP ELEMENTS FROM FRONT
    void pop_front(){
        if(head==NULL) return; // Agr LL hi khali h toh kya hi del krenge
        Node* temp = head; // temp ko del krenge head ko aage krdenge
        head=head->next;
        temp->next=NULL;
        delete temp; //finally deleted temp
    }
    // FUNCTION TO POP ELEMENTS FROM BACK
    void pop_back(){
        if(head==NULL) return;
        Node* temp = head;
        while(temp->next != tail){
            temp=temp->next;
        }
        temp->next=NULL; //to break the connection
        delete tail;
        tail=temp;
    }
    // FUNCTION TO INSERT ELEMENTS IN BETWEEN
    void insert(int val, int pos){
        if(pos<0) return;
        if(pos==0){
            push_front(val);
            return;
        }
        Node* temp = head;
        for(int i=0; i<pos-1; i++){
            if(temp==NULL) return;
            temp=temp->next;
        }
        // now create a new node which is to be inserted
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next=newNode;
    }
    // Print the linked List
    void printLL(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"->"; // print the val
            temp=temp->next; // then move temp forward
        }
        cout<<"NULL"<<endl;
    }
    // SEARCH KEY OR ELEMENT IN A LL
    int search(int key){
        Node* temp = head;
        int idx=0;
        while(temp != NULL){
            if(temp->data == key){
                return idx;
            }
            temp=temp->next;
            idx++;
        }
        return -1;
    }
};
int main(){
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    
    // ll.push_back(4);

    // ll.pop_front();
    ll.insert(4,1);
    ll.printLL();
    cout<<ll.search(4);

    // ll.pop_back();
    // ll.printLL();
}