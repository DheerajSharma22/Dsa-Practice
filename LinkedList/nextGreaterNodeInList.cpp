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

ListNode *reverse(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *nxt = head->next;

    while (curr)
    {
        curr->next = prev;
        prev = curr;
        curr = nxt;
        if (curr)
            nxt = curr->next;
    }

    return prev;
}

vector<int> nextLargerNodes(ListNode *head)
{
    ListNode *reverseHead = reverse(head);
    vector<int> ans;
    stack<int> st;

    ListNode *reversedList = reverseHead;
    while (reversedList)
    {
        int curr = reversedList->val;

        while (!st.empty() && curr >= st.top())
        {
            st.pop();
        }

        if (st.empty())
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(st.top());
        }
        st.push(curr);

        reversedList = reversedList->next;
    }

    std::reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
}