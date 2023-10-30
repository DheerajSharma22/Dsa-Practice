#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *middle(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (!slow->next && (!fast && !fast->next))
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *merge(Node *firstNode, Node *secondNode)
{
    Node *merged = new Node(-1);
    Node *temp = new Node(-1);

    // merged is equal to temp so in the end we have the top
    // Node.
    merged = temp;

    // while either firstNode or secondNode becomes NULL
    while (firstNode != NULL && secondNode != NULL)
    {

        if (firstNode->data <= secondNode->data)
        {
            temp->next = firstNode;
            firstNode = firstNode->next;
        }

        else
        {
            temp->next = secondNode;
            secondNode = secondNode->next;
        }
        temp = temp->next;
    }

    // any remaining Node in firstNode or secondNode gets
    // inserted in the temp List
    while (firstNode != NULL)
    {
        temp->next = firstNode;
        firstNode = firstNode->next;
        temp = temp->next;
    }

    while (secondNode != NULL)
    {
        temp->next = secondNode;
        secondNode = secondNode->next;
        temp = temp->next;
    }
    // return the head of the sorted list
    return merged->next;
}

Node *mergeSort(Node *head)
{
    if (!head->next)
        return head;

    Node *mid = middle(head);
    Node *midNext = mid->next;

    mid->next = NULL;
    Node *a = mergeSort(head);
    Node *b = mergeSort(midNext);

    return merge(a, b);
}

int main()
{
}