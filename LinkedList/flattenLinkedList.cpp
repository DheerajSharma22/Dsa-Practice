#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node *mergeTwoLists(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    Node *ans = NULL;
    Node *ansTail = NULL;

    Node *temp = head1;
    Node *temp2 = head2;

    while (temp != NULL && temp2 != NULL)
    {
        if (temp->data <= temp2->data)
        {
            if (ans == NULL)
            {
                ans = temp;
                ansTail = temp;
            }
            else
            {
                ansTail->bottom = temp;
                ansTail = temp;
            }
            temp = temp->bottom;
        }
        else
        {
            if (ans == NULL)
            {
                ans = temp2;
                ansTail = temp2;
                temp2 = temp2->bottom;
            }
            else
            {
                ansTail->bottom = temp2;
                ansTail = temp2;
                temp2 = temp2->bottom;
            }
        }
    }

    while (temp != NULL)
    {
        ansTail->bottom = temp;
        ansTail = temp;
        temp = temp->bottom;
    }

    while (temp2 != NULL)
    {
        ansTail->bottom = temp2;
        ansTail = temp2;
        temp2 = temp2->bottom;
    }

    return ans;
}

Node *flatten(Node *root)
{
    if (root == NULL || root->next == NULL)
    {
        return root;
    }
    root->next = flatten(root->next);
    root = mergeTwoLists(root, root->next);

    return root;
}

int main()
{
}