#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int addDigits(int num)
{
    int ans = num;

    while (ans >= 10)
    {
        int n = 0;
        while (ans > 0)
        {
            n += ans % 10;
            ans /= 10;
        }
        ans = n;
    }

    return ans;
}

int main()
{
}