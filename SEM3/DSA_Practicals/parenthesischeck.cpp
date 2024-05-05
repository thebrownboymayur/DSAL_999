#include <iostream>
#define size 100
using namespace std;

class stack {
    int top = -1;
    char array[size];

public:
    void push(char val);
    int pop();
    void display();
    char peek();
    bool isempty() {
        if (top == -1) {
            return true;
        }
        else {
            return false;
        }
    }
};

void stack::push(char val) {
    if (top >= size - 1)
        cout << "Stack Overflow" << endl;
    else {
        top++;
        array[top] = val;
    }
}

int stack::pop() {
    if (top <= -1) {
        cout << "Stack Underflow" << endl;
        return -1;
    }
    else {
        cout << "The popped element is " << array[top] << endl;
        return array[top--];
    }
}

void stack::display() {
    if (top >= 0) {
        cout << "Stack elements are:";
        for (int i = top; i >= 0; i--)
            cout << array[i] << " ";
        cout << endl;
    }
    else
        cout << "Stack is empty";
}

char stack::peek() {
    return array[top];
}

int main() {
    string str;
    stack s1;
    cout << "Enter a string: ";
    cin >> str;
    int flag = 1;
    char last_st;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            s1.push(str[i]);
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (s1.isempty()) {
                flag = 0;
                break;
            }
            char last_st = s1.peek();
            if (str[i] == ')' && last_st == '(')
                s1.pop();
            else if (str[i] == '}' && last_st == '{')
                s1.pop();
            else if (str[i] == ']' && last_st == '[')
                s1.pop();
        }
    }
    if (!s1.isempty())
        flag = 0;
    if (flag == 1)
        cout << "Parentheses are Balanced";
    else
        cout << "Parentheses are not Balanced";
    return 0;
}
