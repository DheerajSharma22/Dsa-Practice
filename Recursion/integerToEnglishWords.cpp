#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string numberToWords(int num)
{
    if (num == 0)
        return "Zero";

    vector<string> englishWords = {"Billion", "Million", "Thousand", "Hundred", "Ninety", "Eighty", "Seventy", "Sixty", "Fifty", "Forty", "Thirty", "Twenty", "Nineteen", "Eighteen", "Seventeen", "Sixteen", "Fifteen", "Fourteen", "Thirteen", "Twelve", "Eleven", "Ten", "Nine", "Eight", "Seven", "Six", "Five", "Four", "Three", "Two", "One"};

    vector<int> nums = {1000000000, 1000000, 1000, 100, 90, 80, 70, 60, 50, 40, 30, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    string ans = "";

    for (int i = 0; i < englishWords.size(); i++)
    {
        if (num >= nums[i])
        {
            if (num >= 100)
            {
                ans += numberToWords(num / nums[i]) + " ";
            }

            ans += englishWords[i];

            if (num % nums[i] != 0)
                ans += " " + numberToWords(num % nums[i]);

            return ans;
        }
    }

    return ans;
}
int main()
{
}