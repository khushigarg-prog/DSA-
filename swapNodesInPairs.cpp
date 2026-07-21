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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        // Three pointers
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* prev = NULL;

        while (first != NULL && second != NULL) {

            // Store address of remaining list
            ListNode* third = second->next;

            // Swap
            second->next = first;
            first->next = third;

            // Connect previous pair
            if (prev != NULL) {
                prev->next = second;
            }
            else {
                head = second;
            }

            // Update pointers
            prev = first;
            first = third;

            if (third != NULL)
                second = third->next;
            else
                second = NULL;
        }

        return head;
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
        if (head->next != NULL)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = createList();

    cout << "\nOriginal Linked List:\n";
    printList(head);

    Solution obj;
    head = obj.swapPairs(head);

    cout << "\nLinked List after swapping pairs:\n";
    printList(head);

    return 0;
}