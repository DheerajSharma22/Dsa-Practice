#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class NStack
{
    int *arr;
    int *next, *top;
    int freespot;
    int size, n;

public:
    NStack(int s, int n)
    {
        this->size = size;
        this->n = n;
        
        next = new int[s];
        top = new int[n];
        arr = new int[s];

        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }

        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }

        next[s - 1] = -1;

        freespot = 0;
    }

    bool push(int data, int stackNum)
    {
        if (freespot == -1)
            return false;

        int index = freespot;
        arr[index] = data;
        freespot = next[index];
        next[index] = top[stackNum - 1];
        top[stackNum - 1] = index;

        return true;
    }

    int pop(int stackNum)
    {
        if (top[stackNum - 1] == -1)
            return -1;

        int index = top[stackNum - 1];
        int val = arr[index];
        top[stackNum - 1] = next[index];
        next[index] = freespot;
        arr[index] = -1;
        freespot = index;

        return val;
    }
};

int main()
{
}