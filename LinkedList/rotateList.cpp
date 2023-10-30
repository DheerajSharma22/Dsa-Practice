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

int getLen(ListNode *&head)
{
    int size = 0;
    ListNode *temp = head;

    while (temp)
    {
        temp = temp->next;
        size++;
    }

    return size;
}
ListNode *rotateRight(ListNode *head, int k)
{
    if (!head || !head->next)
        return head;

    int len = getLen(head);
    k = k % len;
    if (k == len || k == 0)
        return head;

    ListNode *tail = head;
    while (tail->next)
        tail = tail->next;

    ListNode *temp = head;
    int index = 1;
    while (index < len - k && temp)
    {
        temp = temp->next;
        index++;
    }

    ListNode *tempHead = temp->next;
    temp->next = NULL;
    tail->next = head;
    head = tempHead;

    return head;
}
int main()
{
}