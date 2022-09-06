// Z - Baekjoon Online Judge no.1074

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, r, c;
    cin >> n >> r >> c;
    int i = 1;
    int expo = 0;
    while(r != r % i) {
        for(int iter = 0; iter < expo; iter++) {
            i *= 2;
        }
    }
}