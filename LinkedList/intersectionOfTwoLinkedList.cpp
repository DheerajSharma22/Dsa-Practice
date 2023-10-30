#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *a = headA, *b = headB;

    while (a->next && b->next)
    {
        if (a == b)
            return a;
        a = a->next;
        b = b->next;
    }

    int lenA = 0, lenB = 0;
    while (a->next)
    {
        a = a->next;
        lenA++;
    }

    while (b->next)
    {
        b = b->next;
        lenB++;
    }

    // Reset a & b.
    a = headA, b = headB;

    // IF a > b.
    if (lenA > lenB)
    {
        int diff = lenA - lenB;

        while (diff-- && a)
        {
            a = a->next;
        }
    }

    if (lenB > lenA)
    {
        int diff = lenB - lenA;
        while (diff-- && b)
        {
            b = b->next;
        }
    }

    // Checking for intersection.
    while (a && b)
    {
        if (a == b)
            return a;
        a = a->next;
        b = b->next;
    }

    return NULL;
}

int main()
{
}