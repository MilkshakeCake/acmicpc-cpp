// Z - Baekjoon Online Judge no.1074

#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int result = 0;

int r, c;

void recursive(int x, int y, int n) {
    if(x == r && y == c) {
        cout << result;
        return;
    }

    if(r >= x + n || c >= y + n) {
        result += n * n;
        return;
    }

    recursive(x, y, n/2);
    recursive(x, y + n/2, n/2);
    recursive(x + n/2, y, n/2);
    recursive(x + n/2, y + n/2, n/2);
}

int main() {
    int n;
    cin >> n >> r >> c;

    recursive(0, 0, pow(2, n)); 
}