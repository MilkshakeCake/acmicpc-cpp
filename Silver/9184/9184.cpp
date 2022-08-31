#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int arr[51][51][51] = {1};

int w(int a, int b, int c) {
    if(a <= 0 || b <= 0 || c <= 0) {
        arr[a][b][c] = 1;
        return 1;
    }

    if(a > 20 || b > 20 || c > 20) {
        arr[a][b][c] = arr[20][20][20];
        return arr[a][b][c];
    }

    if(a < b && b < c) {
        arr[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c); //arr[a][b][c-1] + arr[a][b-1][c-1] - arr[a][b-1][c];
        return arr[a][b][c];
    }

    else {
        arr[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1); //arr[a-1][b][c] + arr[a-1][b-1][c] + arr[a-1][b][c-1] - arr[a-1][b-1][c-1];
        return arr[a][b][c];
    }
}

int main() {
    int a, b, c;
    a = 0; b = 0; c = 0;
    while(true) {
        cin >> a >> b >> c;

        if(a == -1 && b == -1 && c == -1) {
            break;
        }

        cout << w(a, b, c);
    }   
    return 0;
}