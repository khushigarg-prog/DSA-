#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {
    }

    // Push element onto stack
    void push(int x) {
        // Copy all elements of q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Push new element into q1
        q1.push(x);

        // Copy all elements back to q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    // Removes the element on top of the stack
    int pop() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        int ans = q1.front();
        q1.pop();
        return ans;
    }

    // Get the top element
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        return q1.front();
    }

    // Returns whether the stack is empty
    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;

    cout << "Popped: " << st.pop() << endl;
    cout << "Top after pop: " << st.top() << endl;

    st.push(40);

    cout << "Stack elements: ";
    while (!st.empty()) {
        cout << st.pop() << " ";
    }
    cout << endl;

    return 0;
}