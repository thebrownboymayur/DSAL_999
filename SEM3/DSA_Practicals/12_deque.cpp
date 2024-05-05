/*
A double-ended queue (deque) is a linear list in which additions
and deletions may be
made at either end. Obtain a data representation mapping a deque
into a onedimensional array. Write C++ program to simulate deque
with functions to add and delete elements from either end of the
deque.
*/

#include<iostream>
using namespace std;

#define SIZE 5

class dequeue {
public: 
    int a[SIZE], front, rear;

    dequeue() {
        front = -1;
        rear = -1;
    }

    int isempty() {
        if (front == -1 && rear == -1)
            return 1;
        else
            return 0;
    }

    int isfull() {
        if ((front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1)))
            return 1;
        else
            return 0;
    }

    void enqueue_front(int);
    void enqueue_rear(int);
    void delete_fr_front();
    void delete_fr_rear();
    void display();
};

void dequeue::enqueue_front(int item) {
    if (isfull())
        cout << "\nInsertion is not possible, overflow!!!";
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        a[front] = item;
    } else {
        front = (front - 1 + SIZE) % SIZE;
        a[front] = item;
    }
}

void dequeue::enqueue_rear(int item) {
    if (isfull())
        cout << "\nInsertion is not possible, overflow!!!";
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        a[rear] = item;
    } else {
        rear = (rear + 1) % SIZE;
        a[rear] = item;
    }
}

void dequeue::display() {
    int i;
    if (isempty()) {
        cout << "Queue is empty";
    } else {
        i = front;
        cout << "Elements in deque are : ";
        while (i != rear) {
            cout << a[i] << " ";
            i = (i + 1) % SIZE;
        }
        cout << a[rear];
    }
}

void dequeue::delete_fr_front() {
    if (isempty()) {
        cout << "Deletion is not possible: Dequeue is empty";
        return;
    } else {
        if (front == rear) {
            front = rear = -1;
            return;
        }
        cout << "The deleted element is " << a[front];
        front = (front + 1) % SIZE;
    }
}

void dequeue::delete_fr_rear() {
    if (isempty()) {
        cout << "Deletion is not possible: Dequeue is empty";
        return;
    } else {
        if (front == rear) {
            front = rear = -1;
        }
        cout << "The deleted element is " << a[rear];
        rear = (rear - 1 + SIZE) % SIZE;
    }
}

int main() {
    int c, item;
    dequeue d1;
    do {
        cout << "\n\n****DEQUEUE OPERATION****\n";
        cout << "\n1-Insert at beginning";
        cout << "\n2-Insert at end";
        cout << "\n3-Display";
        cout << "\n4-Deletion from front";
        cout << "\n5-Deletion from rear";
        cout << "\n6-Exit";
        cout << "\nEnter your choice : ";
        cin >> c;
        switch (c) {
            case 1:
                cout << "Enter the element to be inserted:";
                cin >> item;
                d1.enqueue_front(item);
                break;
            case 2:
                cout << "Enter the element to be inserted:";
                cin >> item;
                d1.enqueue_rear(item);
                break;
            case 3:
                d1.display();
                break;
            case 4:
                d1.delete_fr_front();
                break;
            case 5:
                d1.delete_fr_rear();
                break;
            case 6:
                exit(1);
                break;
            default:
                cout << "Invalid choice";
                break;
        }
    } while (c != 6);
    return 0;
}
