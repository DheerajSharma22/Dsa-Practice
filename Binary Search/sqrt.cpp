#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Gives Only integer value.
int mySqrt(int x)
{
    int start = 0, end = x;
    int ans = -1;

    while (start <= end)
    {
        long long mid = start + (end - start) / 2;

        if (mid * mid <= x)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return ans;
}

int main()
{
    int n = 8;
    int sqrt = mySqrt(n);

    double ans = sqrt;
    double factor = 1;
    for (int precesion = 1; precesion <= 5; precesion++)
    {
        factor /= 10;
        for (float j = ans; j * j < n; j += factor)
            ans = j;
    }

    cout << ans << endl;
}