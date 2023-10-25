#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(int n, int x, int y, int z)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return INT_MIN;

    int a = solve(n - x, x, y, z) + 1;
    int b = solve(n - y, x, y, z) + 1;
    int c = solve(n - z, x, y, z) + 1;

    int ans = max(a, max(b, c));

    return ans;
}

int main()
{
    int N = 70, X = 5, Y = 2, Z = 2;

    cout << solve(N, X, Y, Z) << endl;
}