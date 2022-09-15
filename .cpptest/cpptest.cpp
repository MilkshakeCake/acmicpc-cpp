// Practice techniques of C++

#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <deque>
#include <map>

#define all(v) (v).begin(), (v).end()

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[301] = {0};
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for(auto& i : arr) cout << i << ' ';
}