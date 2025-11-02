#include <iostream>
#define MAX 5
using namespace std;

class Queue {
    int arr[MAX], front, rear;
public:
    Queue() { front = -1; rear = -1; }

    bool isEmpty() { return front == -1; }
    bool isFull() { return (rear + 1) % MAX == front; }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is Full\n";
            return;
        }
        if (isEmpty()) front = 0;
        rear = (rear + 1) % MAX;
        arr[rear] = x;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        if (front == rear) { front = rear = -1; }
        else front = (front + 1) % MAX;
    }

    void display() {
        if (isEmpty()) { cout << "Queue is Empty\n"; return; }
        int i = front;
        cout << "Queue: ";
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }

    void peek() {
        if (!isEmpty()) cout << "Front element: " << arr[front] << endl;
        else cout << "Queue is Empty\n";
    }
};

int main() {
    Queue q;
    int choice, val;
    do {
        cout << "\n1.Enqueue 2.Dequeue 3.Display 4.Peek 5.Exit\n";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: q.display(); break;
            case 4: q.peek(); break;
        }
    } while (choice != 5);
    return 0;
}
