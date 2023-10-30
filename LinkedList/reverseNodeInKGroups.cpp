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

int getLength(ListNode *&head)
{
    int size = 0;
    ListNode *temp = head;

    while (temp)
    {
        size++;
        temp = temp->next;
    }

    return size;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // Getting the length of linked list
    int len = getLength(head);
    if (len < k)
    {
        return head;
    }

    // Case where length is greater than equal to k
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *forwards = curr->next;
    int count = 0;

    while (count < k)
    {
        forwards = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forwards;
        count++;
    }

    head->next = reverseKGroup(forwards, k);
    return prev;
}
int main()
{
}