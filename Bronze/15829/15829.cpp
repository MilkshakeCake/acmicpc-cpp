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

    long long int hash = 0;
    for(int i = 0; i < l; i++) {
        long long int temp = str[i] - 96;
        for(int j = 0; j < i; j++) {
            temp = (temp * 31) % M;
        }
        hash += temp;
    }
    cout << hash % M;
}