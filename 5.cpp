#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) { cout << "Stack Empty\n"; return; }
        cout << "Popped: " << q1.front() << endl;
        q1.pop();
    }

    void top() {
        if (!q1.empty()) cout << "Top: " << q1.front() << endl;
        else cout << "Stack Empty"<<endl;
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.top();
    st.pop();
    st.top();
    return 0;
}
