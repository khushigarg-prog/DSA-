#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;

        // Step 1: Check if at least k nodes exist
        while (count < k) {
            if (temp == NULL)
                return head;
            temp = temp->next;
            count++;
        }

        // Step 2: Reverse remaining list recursively
        ListNode* prevNode = reverseKGroup(temp, k);

        // Step 3: Reverse current group
        temp = head;
        count = 0;

        while (count < k) {
            ListNode* next = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = next;
            count++;
        }

        return prevNode;
    }
};

// Function to create linked list
ListNode* createList() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n == 0)
        return NULL;

    int x;
    cout << "Enter values: ";

    cin >> x;
    ListNode* head = new ListNode(x);
    ListNode* tail = head;

    for (int i = 1; i < n; i++) {
        cin >> x;
        tail->next = new ListNode(x);
        tail = tail->next;
    }

    return head;
}

// Function to print linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = createList();

    int k;
    cout << "Enter k: ";
    cin >> k;

    Solution obj;
    head = obj.reverseKGroup(head, k);

    cout << "Linked List after reversing in groups of " << k << ": ";
    printList(head);

    return 0;
}