#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
int countPairs(Node *root1, Node *root2, int x)
{
    int count = 0;

    stack<Node *> s1, s2;

    Node *a = root1;
    Node *b = root2;

    while (1)
    {
        while (a)
        {
            // Inorder
            s1.push(a);
            a = a->left;
        }

        while (b)
        {
            // Reverse Inorder
            s2.push(b);
            b = b->right;
        }

        if (s1.empty() || s2.empty())
        {
            break;
        }

        Node *aTop = s1.top();
        Node *bTop = s2.top();

        int sum = aTop->data + bTop->data;

        if (sum == x)
        {
            count++;
            s1.pop();
            s2.pop();

            a = aTop->right;
            b = bTop->left;
        }
        else if (sum < x)
        {
            s1.pop();
            a = aTop->right;
        }
        else
        {
            s2.pop();
            b = bTop->left;
        }
    }

    return count;
}

int main()
{
}