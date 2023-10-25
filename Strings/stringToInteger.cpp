#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s)
{
    int n = s.size();

    // Step 1 :- Remove Leading Spaces
    int index = 0;
    while (index < n && s[index] == ' ')
    {
        index++;
    }

    // Step 2 :- Check for sign.
    int sign = 1;
    if (index < s.size() && (s[index] == '-' || s[index] == '+'))
    {
        sign = s[index] == '-' ? -1 : 1;
        index++;
    }

    // According to question after sign their are some integers.
    int num = 0;
    while (index < s.size() && isdigit(s[index]))
    {
        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[index] > '7'))
        {
            return sign == -1 ? INT_MIN : INT_MAX;
        }
        else
        {
            num = num * 10 + (s[index] - '0');
        }
        index++;
    }

    return num * sign;
}

int main()
{
}