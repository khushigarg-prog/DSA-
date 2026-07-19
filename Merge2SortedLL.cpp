#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if (head1 == NULL)
            return head2;

        if (head2 == NULL)
            return head1;

        // If head1 is smaller
        if (head1->val <= head2->val) {
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        }
        // If head2 is smaller
        else {
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
    }
};

// Function to insert a node at the end
void insertAtEnd(ListNode*& head, int value) {
    ListNode* newNode = new ListNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    ListNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head1 = NULL;
    ListNode* head2 = NULL;

    // First sorted list: 1 -> 2 -> 4
    insertAtEnd(head1, 1);
    insertAtEnd(head1, 2);
    insertAtEnd(head1, 4);

    // Second sorted list: 1 -> 3 -> 4
    insertAtEnd(head2, 1);
    insertAtEnd(head2, 3);
    insertAtEnd(head2, 4);

    cout << "First Linked List: ";
    printList(head1);

    cout << "Second Linked List: ";
    printList(head2);

    Solution obj;
    ListNode* mergedHead = obj.mergeTwoLists(head1, head2);

    cout << "Merged Linked List: ";
    printList(mergedHead);

    return 0;
}