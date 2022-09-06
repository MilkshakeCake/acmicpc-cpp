// "Project_Name" - Baekjoon Online Judge no."Project_Num"

#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

int arr[50] = {0, 1, };

int fibonacci(int n) {
    if(arr[n] == 0 && n > 1) {
        arr[n] = fibonacci(n-1) + fibonacci(n-2);
    }
    return arr[n];
}

int main() {
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int temp;
        cin >> temp;
        if(temp == 0) {
            cout << "1 0\n";
        }
        else {
            cout << fibonacci(temp - 1) << ' ' << fibonacci(temp) << '\n';
        }
    }
}