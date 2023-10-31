#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int top;
    int *arr;
    int size;
    int length;

public:
    Stack(int size)
    {
        this->size = size;
        this->top = -1;
        arr = new int[size];
        length = 0;
    }

    void push(int data)
    {
        if (length == this->size)
        {
            cout << "Stack Overflow..." << endl;
            return;
        }

        arr[++top] = data;
        length++;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty..." << endl;
            return;
        }

        length--;
        top--;
    }

    int getTop()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return arr[top];
    }

    int getLength() { return length; }

    bool isEmpty()
    {
        return length == 0;
    }
};

int main()
{
    Stack s(5);
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);
    s.push(25);
    // s.push(30);

    while (s.getLength() > 0)
    {
        cout << s.getTop() << " ";
        s.pop();
    }

    if (s.isEmpty())
        cout << "Stack is empty" << endl;
}