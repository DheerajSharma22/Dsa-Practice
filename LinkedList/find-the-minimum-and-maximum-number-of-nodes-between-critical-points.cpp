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

vector<int> nodesBetweenCriticalPoints(ListNode *head)
{
    vector<int> ans = {-1, -1};
    if (!head || !head->next || !head->next->next)
        return ans;

    ListNode *temp = head->next;
    ListNode *prev = head;

    int firstCP = -1, lastCP = -1;
    int index = 2;
    int minDistance = INT_MAX;

    while (temp->next)
    {
        if ((temp->val > prev->val && temp->val > temp->next->val) ||
            (temp->val < prev->val && temp->val < temp->next->val))
        {
            if (firstCP == -1)
            {
                firstCP = index;
            }
            else
            {
                minDistance = min(index - lastCP, minDistance);
            }

            lastCP = index;
        }
        index++;
        prev = temp;
        temp = temp->next;
    }

    if (lastCP == firstCP)
        return ans;

    ans[0] = minDistance;
    ans[1] = lastCP - firstCP;

    return ans;
}

int main()
{
}