#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string intToRoman(int num)
{
    vector<int> numValues = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> romanValues = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string ans = "";
    for (int i = 0; i < 13; i++)
    {
        while (num >= numValues[i])
        {
            ans += romanValues[i];
            num -= numValues[i];
        }
    }

    return ans;
}

int main()
{
}