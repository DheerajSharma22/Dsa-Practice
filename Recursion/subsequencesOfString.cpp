#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printSubSequences(string &str, int index, string output) {
    if (index >= str.size()) {
        cout << output << " ";
        return;
    }
    
    // Exclude
    printSubSequences(str, index+1, output);

    // Include
    printSubSequences(str, index+1, output+str[index]);
}

int main () {
    string str = "abc";
    printSubSequences(str, 0, "");
}