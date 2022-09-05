// Hashing - Baekjoon Online Judge no.15829

#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int l;
    int M = 1234567891;

    string str;
    cin >> l >> str;

    long long hash = 0;
    for(unsigned int i = 0; i < str.length(); i++) {
        hash += (str[i] - 96) * pow(31, i);
    }
    hash--;

    hash %= M;
    cout << hash;
}