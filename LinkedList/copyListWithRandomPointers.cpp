#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    if (!head)
        return NULL;
    unordered_map<Node *, Node *> mp;

    Node *temp = head;

    // Creating the new list.
    Node *ansHead = new Node(temp->val);
    Node *ansTail = ansHead;
    mp[temp] = ansHead;

    // Shifting temp.
    temp = temp->next;

    // Copying list with next pointer.
    while (temp)
    {
        Node *newNode = new Node(temp->val);
        ansTail->next = newNode;
        ansTail = ansTail->next;
        mp[temp] = ansTail;
        temp = temp->next;
    }

    // Copy random pointers
    ansTail = ansHead;
    temp = head;
    while (ansTail)
    {
        ansTail->random = mp[temp->random];
        ansTail = ansTail->next;
        temp = temp->next;
    }

    return ansHead;
}

int main()
{
}