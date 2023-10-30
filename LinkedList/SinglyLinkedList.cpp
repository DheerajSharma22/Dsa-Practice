#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
int getSize(Node *head)
{
    int size = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }

    return size;
}

void insertAtHead(Node *&head, int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        return;
    }

    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node *&head, int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        return;
    }

    // Finding the tail.
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    // Creating the new node.
    Node *newNode = new Node(data);
    temp->next = newNode;
}

void insertAtMiddle(Node *head, int data, int pos)
{
    if (head == NULL)
    {
        head = new Node(data);
        return;
    }

    // Finding the node after that we want to insert a new node.
    int index = 1;
    Node *temp = head;
    while (index < pos - 1 && temp != NULL)
    {
        temp = temp->next;
        index++;
    }

    // Creating the new node.
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deletionFromHead(Node *&head)
{
    if (!head)
        return;

    Node *temp = head;
    head = head->next;
    temp->next = NULL;

    delete temp;
}

void deletionFromTail(Node *&head)
{
    if (!head)
        return;

    Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    Node *temp2 = temp->next;
    temp->next = NULL;

    delete temp2;
}

void deletionFromMiddle(Node *&head, int pos)
{
    int sizeOfLL = getSize(head);
    if (!head)
        return;
    if (pos > sizeOfLL || pos < 1) {
        cout << "Index out of range..." << endl;
        return;
    }
    if (pos == 1)
    {
        deletionFromHead(head);
        return;
    };

    Node *temp = head;

    int index = 1;
    while (temp != NULL && index < pos - 1)
    {
        temp = temp->next;
        index++;
    }

    Node *temp2 = temp->next;
    temp->next = temp2->next;
    temp2->next = NULL;

    delete temp2;
}

void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    Node *head = NULL;
    insertAtTail(head, 5);
    insertAtTail(head, 10);
    insertAtTail(head, 15);
    insertAtTail(head, 25);
    insertAtTail(head, 35);
    insertAtMiddle(head, 20, 4);

    deletionFromMiddle(head, 100);

    print(head);
}
