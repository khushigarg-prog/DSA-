#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue() {
    }

    void push(int x) {
        // Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push new element into s1
        s1.push(x);

        // Move all elements back to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        if (s1.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        int ans = s1.top();
        s1.pop();
        return ans;
    }

    int peek() {
        if (s1.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }
};

int main() {
    MyQueue q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front element: " << q.peek() << endl;

    cout << "Popped: " << q.pop() << endl;
    cout << "Front element after pop: " << q.peek() << endl;

    q.push(4);

    cout << "Queue elements: ";
    while (!q.empty()) {
        cout << q.pop() << " ";
    }
    cout << endl;

    return 0;
}