#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int data)
    {
        val = data;
        next = NULL;
    }
};

ListNode *mergeNodes(ListNode *head)
{
    ListNode *ansHead = new ListNode(-1);
    ListNode *ansPtr = ansHead;

    ListNode *temp = head;

    while (temp)
    {
        if (temp->val == 0)
        {
            int sum = 0;
            temp = temp->next;
            while (temp && temp->val != 0)
            {
                sum += temp->val;
                temp = temp->next;
            }
            if (sum != 0)
            {
                ListNode *curr = new ListNode(sum);
                ansPtr->next = curr;
                ansPtr = ansPtr->next;
            }
        }
    }

    return ansHead->next;
}

int main()
{
}