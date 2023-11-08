#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class KQueue
{
    int *arr;
    int *front;
    int *rear;
    int *next;
    int capacity, k, freespot;

public:
    KQueue(int K, int N)
    {
        this->capacity = N;
        this->k = K;
        arr = new int[capacity];
        next = new int[capacity];
        front = new int[k];
        rear = new int[k];

        freespot = 0;

        for (int i = 0; i < k; i++)
            front[i] = rear[i] = -1;

        for (int i = 0; i < capacity; i++)
            next[i] = i + 1;

        next[N - 1] = -1;
    }

    void push(int data, int qNum)
    {
        if (freespot == -1)
        {
            cout << "The queue is full.";
            return;
        }

        int index = freespot;

        freespot = next[index];

        if (front[qNum] == -1)
        {
            front[qNum] = index;
        }
        else
        {
            next[rear[qNum]] = index;
        }

        next[index] = -1;
        rear[qNum] = index;
        arr[index] = data;
    }

    int pop(int qNum)
    {
        if (front[qNum] == -1)
            return -1;

        int index = front[qNum];
        front[qNum] = next[index];
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};

int main()
{
    KQueue q(3, 5);

    q.push(5, 0);
    q.push(10, 0);
    q.push(5, 2);

    cout << q.pop(0) << endl;
    cout << q.pop(0) << endl;
}