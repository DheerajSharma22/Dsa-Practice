#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertNode(Node *&tail, int data, int element)
{
    if (tail == NULL)
    {
        tail = new Node(data);
        tail->next = tail;
        return;
    }

    // Finding the element.
    // Assuming that the element presents in linked list.
    Node *temp = tail;
    while (temp->data != element)
        temp = temp->next;

    // Create a new node.
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(Node *&tail, int element)
{
    if (tail == NULL)
    {
        cout << "The list is empty." << endl;
        return;
    }

    // Finding the element.
    // Assuming that the element presents in linked list.
    Node *temp = tail;
    while (temp->next->data != element)
        temp = temp->next;

    // Create a new node.
    Node *temp2 = temp->next;
    temp->next = temp2->next;
    temp2->next = NULL;
    delete temp2;
}

void print(Node *tail)
{
    Node *temp = tail;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
}

int main()
{
    Node *tail = NULL;
    insertNode(tail, 5, 5);
    insertNode(tail, 10, 5);
    insertNode(tail, 15, 10);
    insertNode(tail, 20, 15);
    insertNode(tail, 25, 20);
    insertNode(tail, 30, 25);
    insertNode(tail, 35, 30);

    deleteNode(tail, 15);

    print(tail);
}