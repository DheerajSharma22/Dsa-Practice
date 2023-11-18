#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

pair<ListNode *, ListNode *> findMid(ListNode *head)
{
    if (!head->next)
        return {head, NULL};

    ListNode *slow = head, *fast = head->next, *prev = NULL;

    while (fast)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next;

        if (fast)
        {
            fast = fast->next;
        }
    }

    return {slow, prev};
}

TreeNode *sortedListToBST(ListNode *head)
{
    if (!head)
        return NULL;
    if (!head->next)
        return new TreeNode(head->val);

    // Find mid.
    auto ans = findMid(head);
    ListNode *mid = ans.first;
    ListNode *midPrev = ans.second;
    ListNode *midNext = mid->next;
    midPrev->next = NULL;

    // Create root node from head.
    TreeNode *root = new TreeNode(mid->val);

    root->left = sortedListToBST(head);
    root->right = sortedListToBST(midNext);

    return root;
}

int main()
{
}