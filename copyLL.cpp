#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        unordered_map<Node*, Node*> mp;

        Node* curr = head;
        Node* prev = NULL;
        Node* newHead = NULL;

        // Step 1: Create copy of each node
        while (curr != NULL) {
            Node* temp = new Node(curr->val);

            mp[curr] = temp;

            if (newHead == NULL) {
                newHead = temp;
                prev = newHead;
            } else {
                prev->next = temp;
                prev = temp;
            }

            curr = curr->next;
        }

        // Step 2: Assign random pointers
        curr = head;
        Node* newCurr = newHead;

        while (curr != NULL) {
            if (curr->random == NULL)
                newCurr->random = NULL;
            else
                newCurr->random = mp[curr->random];

            curr = curr->next;
            newCurr = newCurr->next;
        }

        return newHead;
    }
};

// Function to print list
void printList(Node* head) {
    while (head != NULL) {
        cout << "Node Value = " << head->val;

        if (head->random)
            cout << ", Random = " << head->random->val;
        else
            cout << ", Random = NULL";

        cout << endl;

        head = head->next;
    }
}

int main() {

    // Creating original linked list
    Node* n1 = new Node(7);
    Node* n2 = new Node(13);
    Node* n3 = new Node(11);
    Node* n4 = new Node(10);
    Node* n5 = new Node(1);

    // Next pointers
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    // Random pointers
    n1->random = NULL;
    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;

    cout << "Original List:\n";
    printList(n1);

    Solution obj;
    Node* copiedHead = obj.copyRandomList(n1);

    cout << "\nCopied List:\n";
    printList(copiedHead);

    return 0;
}