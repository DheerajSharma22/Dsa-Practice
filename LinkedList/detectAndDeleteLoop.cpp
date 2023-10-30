#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

bool hasCycle(Node *head)
{
    if (!head || !head->next)
        return false;

    Node *slow = head;
    Node *fast = head;

    while (fast)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast)
            fast = fast->next;

        if (slow == fast)
            break;
    }

    slow = head;
    while (slow && fast)
    {
        slow = slow->next;
        fast = fast->next;

        if (slow == fast)
            return true;
    }

    return false;
}

void removeLoop(Node *&head)
{
    if (head == NULL)
    {
        return;
    }

    Node *fast = head;
    Node *slow = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        if (fast == slow)
        {
            slow = head;
            break;
        }
    }

    Node *prev = fast;

    while (slow && fast)
    {
        prev = fast;
        slow = slow->next;
        fast = fast->next;

        if (slow == fast)
        {
            prev->next = NULL;
            return;
        }
    }
}

int main()
{
    Node *head = new Node(7);

    Node *first = new Node(58);
    head->next = first;

    Node *second = new Node(36);
    first->next = second;

    Node *third = new Node(34);
    second->next = third;

    Node *fourth = new Node(16);
    third->next = fourth;

    fourth->next = first;

    removeLoop(head);

    cout << hasCycle(head) << endl;
}