#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool static comp(string &a, string &b)
{
    return a + b > b + a;
}
string largestNumber(vector<int> &nums)
{
    vector<string> numbers;
    for (auto num : nums)
        numbers.push_back(to_string(num));

    sort(numbers.begin(), numbers.end(), comp);

    if (numbers[0] == "0")
        return "0";

    string ans = "";
    for (auto str : numbers)
        ans += str;

    return ans;
}

int main()
{
}