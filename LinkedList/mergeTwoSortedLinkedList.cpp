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

Node *sort(Node *A, Node *B)
{
    Node *curr1 = A, *curr2 = B;

    Node *ans = new Node(-1);
    Node *temp = ans;
    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1->data <= curr2->data)
        {
            temp->next = curr1;
            curr1 = curr1->next;
        }
        else
        {
            temp->next = curr2;

            curr2 = curr2->next;
        }

        temp = temp->next;
    }

    while (curr1 != NULL)
    {
        temp->next = curr1;
        temp = temp->next;
        curr1 = curr1->next;
    }

    while (curr2 != NULL)
    {
        temp->next = curr2;
        temp = temp->next;
        curr2 = curr2->next;
    }

    temp = ans;
    ans = ans -> next;
    temp -> next = NULL;
    delete temp;

    return ans;
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
    Node *head1 = new Node(2);
    insertAtTail(head1, 4);
    insertAtTail(head1, 6);
    insertAtTail(head1, 8);
    insertAtTail(head1, 10);

    Node *head2 = new Node(1);
    insertAtTail(head2, 3);
    insertAtTail(head2, 5);
    insertAtTail(head2, 7);
    insertAtTail(head2, 9);

    // int n = getSize(head1), m = getSize(head2);
    Node *ans = sort(head1, head2);
    print(ans);
}