#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *next;
    int data;
};

void linkdelete(struct Node *head, int M, int N)
{
    Node *curr = head, *t;
    int count;

    // The main loop that traverses
    // through the whole list
    while (curr)
    {
        // Skip M nodes
        for (count = 1; count < M &&
                        curr != NULL;
             count++)
            curr = curr->next;

        // If we reached end of list, then return
        if (curr == NULL)
            return;

        // Start from next node and delete N nodes
        t = curr->next;
        for (count = 1; count <= N && t != NULL; count++)
        {
            Node *temp = t;
            t = t->next;
            free(temp);
        }

        // Link the previous list with remaining nodes
        curr->next = t;

        // Set current pointer for next iteration
        curr = t;
    }
}
int main()
{
}