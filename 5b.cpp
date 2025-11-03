#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q;
public:
    void push(int x) {
        int n = q.size();
        q.push(x);
        for (int i = 0; i < n; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) { cout << "Stack Empty"<<endl; return; }
        cout << "Popped: " << q.front() << endl;
        q.pop();
    }

    void top() {
        if (!q.empty()) cout << "Top: " << q.front() << endl;
        else cout << "Stack Empty"<<endl;
    }
};

int main() {
    Stack st;
    st.push(5);
    st.push(15);
    st.top();
    st.pop();
    st.top();
    return 0;
}
