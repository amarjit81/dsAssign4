#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int items[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return ((front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1)));
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        cout << "Inserted " << element << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        int data = items[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        cout << "Deleted " << data << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << items[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
        } else {
            cout << "Front element: " << items[front] << endl;
        }
    }
};

int main() {
    CircularQueue q;
    int choice, value;

    do {
        cout << "\nCircular Queue Operations Menu\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. IsEmpty\n6. IsFull\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                q.peek();
                break;
            case 5:
                cout << (q.isEmpty() ? "Queue is empty\n" : "Queue is not empty\n");
                break;
            case 6:
                cout << (q.isFull() ? "Queue is full\n" : "Queue is not full\n");
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, try again\n";
        }
    } while (choice != 7);

    return 0;
}

