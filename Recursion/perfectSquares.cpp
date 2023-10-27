#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int numSquaresHelper(int num)
{
    if (num == 0)
        return 1;
    if (num < 0)
        return 0;

    int ans = INT_MAX;
    int i = 1;
    int end = sqrt(num);

    while (i <= end)
    {
        int square = i * i;
        int noOfPerfectSquare = 1 + numSquaresHelper(num - square);
        if (ans > noOfPerfectSquare)
        {
            ans = noOfPerfectSquare;
        }
        i++;
    }
    return ans;
}

int main()
{

    cout << "The ans is :- " << numSquaresHelper(12) - 1 << endl; 
}