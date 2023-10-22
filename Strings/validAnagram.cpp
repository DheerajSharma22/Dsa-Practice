#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isAnagram (string &s, string& t) {
    vector<int> freq(26, 0);

    for (auto ch: s) freq[ch-'a']++;
    for (auto ch: t) freq[ch-'a']--;
    for (auto elm: freq) if (elm != 0) return false;

    return true; 
}

int main () {
    string a = "anagram", b = "nagaram";
    cout << isAnagram(a, b) << endl;
}