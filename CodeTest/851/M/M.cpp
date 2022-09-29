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

vector<int> play(100000, 0);
bool prev[100000] = {false};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> play[i];
        sum += play[i];
    }

    sort(play.begin(), play.end(), greater<>());

    int elsenum = sum - play[0];

    if(play[0] > (elsenum + 1)) {
        cout << ((elsenum) * 2) + 1;
    }

    else if(play[0] == (elsenum + 1) || play[0] * 2 == sum) {
        cout << sum;
    }

    else {
        
    }
}