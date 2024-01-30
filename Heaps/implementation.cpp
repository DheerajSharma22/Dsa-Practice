#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Heap
{
    int arr[100];
    int size;

public:
    Heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int data)
    {
        size++;
        int index = size;
        arr[index] = data;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[index] > arr[parent])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
                return;
        }
    }

    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "The heap is empty" << endl;
            return;
        }

        arr[1] = arr[size--];

        int index = 1;
        while (index < size)
        {
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;

            if (leftIndex <= size && arr[leftIndex] > arr[index])
            {
                swap(arr[leftIndex], arr[index]);
                index = leftIndex;
            }
            else if (rightIndex <= size && arr[rightIndex] > arr[index])
            {
                swap(arr[rightIndex], arr[index]);
                index = rightIndex;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

void heapify(int arr[], int n, int index)
{
    int largest = index;
    int left = 2 * index;
    int right = 2 * index + 1;

    if (left <= n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right <= n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int size = n;

    while (size > 1)
    {
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, size, 1);
    }
}

int main()
{
    int arr[] = {-1, 10, 5, 6, 2, 12, 7, 9};

    int n = 7;

    for (int i = n / 2; i > 0; i--)
        heapify(arr, n, i);

    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // heapSort(arr, n);

    // for (int i = 1; i <= n; i++)
    //     cout << arr[i] << " ";
    // cout << endl;
}