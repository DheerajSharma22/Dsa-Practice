#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int countPrimes(int n)
{
    if (n == 0)
        return 0;

    vector<bool> prime(n, 1);
    prime[0] = prime[1] = false;

    int count = 0;
    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            count++;

            int j = i * 2;
            while (j < n)
            {
                prime[j] = false;
                j += i;
            }
        }
    }

    return count;
}

int main()
{
    cout << "Prime no. till 20 are :- " << countPrimes(20) << endl;
}