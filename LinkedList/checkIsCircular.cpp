#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head)
{
    if (!head || !head->next)
        return false;

    ListNode *slow = head;
    ListNode *fast = head;

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

int main()
{
}