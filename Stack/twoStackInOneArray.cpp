#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int *arr;
    int top1;
    int top2;
    int size;

public:
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void push1(int data)
    {
        if (top2 - top1 <= 1)
        {
            cout << "Stack Overflow" << endl;
        }

        arr[++top1] = data;
    }

    void push2(int data)
    {
        if (top2 - top1 <= 1)
        {
            cout << "Stack Overflow" << endl;
        }
        arr[--top2] = data;
    }

    void pop1()
    {
        if (top1 == -1)
        {
            cout << "Stack is empty" << endl;
            return;
        }

        top1--;
    }

    void pop2()
    {
        if (top2 == size)
        {
            cout << "Stack is empty" << endl;
            return;
        }

        top2++;
    }

    int peek1()
    {
        if (top1 == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return arr[top1];
    }
    int peek2()
    {
        if (top2 == size)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return arr[top2];
    }


};

int main()
{

    Stack st(5);
    st.push1(1);
    st.push1(2);
    st.push1(3);
    st.push2(4);
    st.push2(5);

    cout << st.peek1() << endl; 
    cout << st.peek2() << endl; 
}