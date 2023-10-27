#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printPerms(string str, int index)
{
    if (index >= str.size())
        cout << str << " ";

    for (int i = index; i < str.size(); i++)
    {
        swap(str[i], str[index]);
        printPerms(str, index + 1);
        swap(str[i], str[index]);
    }
}

int main()
{
    printPerms("abc", 0);
}