#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }

    void push(int x)
    {
        if (rear == size - 1)
        {
            cout << "Queue is full" << endl;
            return;
        }

        if (front == -1)
        {
            arr[++rear] = x;
            front++;
            return;
        }
        arr[++rear] = x;
    }

    int pop()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int elm = arr[front];
        front++;
        if (front == rear + 1)
            front = rear = -1;
        return elm;
    }

    int getFront()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
};

class DQueue
{
    int *arr;
    int front;
    int rear;
    int capacity;
    int size;

public:
    DQueue(int N)
    {
        this->capacity = N;
        this->size = 0;

        arr = new int[capacity];

        front = -1;
        rear = capacity;
    }

    void push_front(int x)
    {
        if (size == capacity)
        {
            cout << "The queue is full." << endl;
            return;
        }

        arr[++front] = x;
        size++;
    }

    void push_back(int x)
    {
        if (size == capacity)
        {
            cout << "The queue is full." << endl;
            return;
        }

        arr[--rear] = x;
        size++;
    }

    int pop_back()
    {
        if (size == 0)
        {
            rear = capacity;
            cout << "The queue is empty." << endl;
            return -1;
        }

        int elm = arr[rear];
        size--;
        arr[rear++] = -1;
        return elm;
    }

    int pop_front()
    {
        if (size == 0)
        {
            front = -1;
            cout << "The queue is empty." << endl;
            return -1;
        }

        int elm = arr[front];
        arr[front--] = -1;
        size--;
        return elm;
    }

    void print()
    {
        for (int i = 0; i < capacity; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    DQueue q(5);
    q.push_back(10);
    q.push_back(15);
    q.push_back(20);
    q.push_front(25);
    q.push_front(30);

    cout << q.pop_back() << endl;
    cout << q.pop_front() << endl;

    q.push_front(30);
    q.print();

    // cout << q.pop() << endl;
    // cout << q.pop() << endl;
    // cout << q.pop() << endl;

    // q.push(30);
    // q.push(10);
    // q.push(15);
    // q.push(20);
    // q.push(25);
}