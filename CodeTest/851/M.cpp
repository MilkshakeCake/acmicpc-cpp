// 자유 이용권 - 충남대학교 SW_IT Contest M

#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <deque>
#include <fstream>
#include <map>

using namespace std;

vector<long long> play(100000, 0);
bool prev[100000] = {false};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    long long sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> play[i];
        sum += play[i];
    }

    sort(play.begin(), play.end(), greater<>());

    if(play[0] > (sum - play[0] + 1)) {
        cout << ((sum - play[0]) * 2) + 1;
    }

    else {
        cout << sum;
    }
}

// 숫자 크다 싶으면 long long 쓰기