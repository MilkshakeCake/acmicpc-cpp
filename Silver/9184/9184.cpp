// 신나는 함수 실행 - Baekjoon Online Judge no.9184

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
        if(a == 0 && b == 0 && c == 0) {
            arr[a][b][c] = 1;
        }
        return 1;
    }

    if(arr[a][b][c] != 0) {
        return arr[a][b][c];
    }

    else if(a > 20 || b > 20 || c > 20) {
        arr[a][b][c] = 1048576;
        return arr[a][b][c];
    }

    else if(a < b && b < c) {
        arr[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
        return arr[a][b][c];
    }

    else {
        arr[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
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

        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
    }
    return 0;
}