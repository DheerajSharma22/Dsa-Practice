#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
Node *createNodeToParentMapping(Node *root, unordered_map<Node *, Node *> &mp, int target)
{
    queue<Node *> q;
    q.push(root);
    mp[root] = NULL;

    Node *targetNode;
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front->data == target)
            targetNode = front;

        if (front->left)
        {
            mp[front->left] = front;
            q.push(front->left);
        }
        if (front->right)
        {
            mp[front->right] = front;
            q.push(front->right);
        }
    }

    return targetNode;
}
int burnTree(Node *root, unordered_map<Node *, Node *> &nodeToParent)
{
    unordered_map<Node *, bool> visited;
    queue<Node *> q;
    q.push(root);
    visited[root] = true;

    int ans = 0;
    while (!q.empty())
    {
        int size = q.size();
        bool flag = 0;

        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();

            if (front->left && !visited[front->left])
            {
                visited[front->left] = 1;
                q.push(front->left);
                flag = 1;
            }
            if (front->right && !visited[front->right])
            {
                flag = 1;
                visited[front->right] = 1;
                q.push(front->right);
            }
            if (nodeToParent[front] && !visited[nodeToParent[front]])
            {
                visited[nodeToParent[front]] = 1;
                flag = 1;
                q.push(nodeToParent[front]);
            }
        }

        if (flag)
            ans++;
    }

    return ans;
}

int minTime(Node *root, int target)
{
    // Step 1 :- Node to parent mapping & find target.
    unordered_map<Node *, Node *> nodeToParent;
    Node *targetNode = createNodeToParentMapping(root, nodeToParent, target);

    // Step 2 :- Burn the tree.
    int ans = burnTree(targetNode, nodeToParent);

    return ans;
}

int main()
{
}