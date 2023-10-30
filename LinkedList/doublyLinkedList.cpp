#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *prev, *next;
    int data;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

int getLength(Node *&head)
{
    Node *temp = head;
    int size = 0;

    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }

    return size;
}

/****************************************** INSERTION START ****************************************************/
void insertAtHead(Node *&head, int data)
{
    if (!head)
    {
        head = new Node(data);
        return;
    }

    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = head;
    head->prev = nodeToInsert;
    head = nodeToInsert;
}

void insertAtTail(Node *&head, int data)
{
    if (!head)
    {
        head = new Node(data);
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Creating a new node.
    Node *nodeToInsert = new Node(data);
    nodeToInsert->prev = temp;
    temp->next = nodeToInsert;
}

void insertAtMiddle(Node *&head, int data, int pos)
{
    // Checking for null node.
    if (!head)
    {
        head = new Node(data);
        return;
    }

    if (pos == 0)
    {
        insertAtHead(head, data);
        return;
    }

    int size = getLength(head);

    if (pos > size)
    {
        cout << "Index out of range." << endl;
        return;
    }

    // Finding the pos where we want to insert new node.
    int index = 1;
    Node *temp = head;
    while (index < pos && temp != NULL)
    {
        temp = temp->next;
        index++;
    }

    Node *tempNext = temp->next;

    // Creating a new node.
    Node *newNode = new Node(data);
    newNode->next = tempNext;
    newNode->prev = temp;
    temp->next = newNode;
    if (tempNext)
        tempNext->prev = newNode;
}

void insertBeforeANode(Node *&node, int data)
{
    if (!node)
    {
        cout << "The given node can node be null." << endl;
        return;
    }

    // Creating a new node.
    Node *newNode = new Node(data);
    newNode->next = node;
    newNode->prev = node->prev;

    if (node->prev)
        node->prev->next = newNode;
    else
        node = newNode;
    node->prev = newNode;
}

void insertAfterANode(Node *&node, int data)
{
    if (!node)
    {
        cout << "The given node can node be null." << endl;
        return;
    }

    // Creating a new node.
    Node *newNode = new Node(data);
    newNode->next = node->next;
    newNode->prev = node;

    if (node->next)
        node->next->prev = newNode;

    node->next = newNode;
    node = newNode;
}
/****************************************** INSERTION END ****************************************************/

/****************************************** DELETION START ****************************************************/
void deleteFromHead(Node *&head)
{
    if (!head)
    {
        cout << "The head can not be empty." << endl;
        return;
    }

    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;

    delete temp;
}

void deleteFromTail(Node *&head)
{
    if (!head)
    {
        cout << "The head can not be empty." << endl;
        return;
    }

    Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    Node *temp2 = temp->next;
    temp2->prev = NULL;
    temp->next = NULL;

    delete temp2;
}

// Delete from any where 1-based indexing.
void deleteNode(Node *&head_ref, int x)
{
    if (x == 1)
    {
        deleteFromHead(head_ref);
        return;
    }

    int size = getLength(head_ref);
    if (size <= x)
    {
        cout << "Index out of range" << endl;
        return;
    }

    Node *temp = head_ref;
    int index = 1;

    while (index < x - 1 && temp != NULL)
    {
        temp = temp->next;
        index++;
    }

    Node *temp2 = temp->next;
    temp2->prev = NULL;
    temp->next = temp2->next;
    temp2->next = NULL;

    delete temp2;
}

/****************************************** DELETION END ****************************************************/

void printForward(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printBackword(Node *tail)
{
    Node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(5);

    Node *first = new Node(10);
    first->prev = head;
    head->next = first;

    Node *second = new Node(15);
    second->prev = first;
    first->next = second;

    Node *third = new Node(20);
    third->prev = second;
    second->next = third;

    Node *tail = new Node(25);
    tail->prev = third;
    third->next = tail;

    Node *node = NULL;
    deleteNode(head, 1);
    printForward(head);
}