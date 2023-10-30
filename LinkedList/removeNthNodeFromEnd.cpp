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

int getLength(ListNode *head)
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
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    int size = getLength(head);
    ListNode *temp = head;

    if (size - n == 0)
    {
        ListNode *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return head;
    }

    int index = 1;
    while (index < size - n && temp)
    {
        temp = temp->next;
        index++;
    }

    if (temp)
    {
        ListNode *toDelete = temp->next;
        temp->next = toDelete->next;
        toDelete->next = NULL;
        delete toDelete;
    }

    return head;
}
int main()
{
}