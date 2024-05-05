/* ASSIGNMENT No:10
Title:Pizza parlor accepting maximum M orders. Orders are served
in first come first served basis. Order once placed cannot be
cancelled. Write C++ program to simulate the system using
circular queue using array.
Roll no...:1
*/


#include<iostream>
using namespace std;

#define max1 4

class pizzaparlor {
public:
    int count;
    int q[50], x;
    int rear;
    int front;
    pizzaparlor() {
        count = 0;
        front = 0;
        rear = -1;
    }
    void insert();
    void deleteq();
    void display();
} a;

void pizzaparlor::insert() {
    if (count == max1) {
        cout << "\n Orders are full...:";
    } else {
        cout << "\n Enter order id...:";
        cin >> x;
        rear = (rear + 1) % max1;
        q[rear] = x;
        count++;
        cout << "\n Order is placed...:";
    }
}

void pizzaparlor::display() {
    int i;
    cout << "\n Orders are..:\n";
    i = front;
    do {
        cout << q[i] << " ";
        i = (i + 1) % max1;
    } while (i != ((rear + 1) % max1));
}

void pizzaparlor::deleteq() {
    if (count == 0) {
        cout << "\n no order is placed...:";
    } else {
        front = (front + 1) % max1;
        count--;
        cout << "\n Order is delivered...:";
    }
}

int main() {
    int ch;
    do {
        cout << "\n******MENU******\n";
        cout << "\n 1) Place order";
        cout << "\n 2) Pending orders";
        cout << "\n 3) Deliver order";
        cout << "\n 4) Exit";
        cout << "\n Enter your choice....:";
        cin >> ch;
        switch (ch) {
            case 1:
                a.insert();
                break;
            case 2:
                a.display();
                break;
            case 3:
                a.deleteq();
                break;
        }
    } while (ch < 4);
    return 0;
}
