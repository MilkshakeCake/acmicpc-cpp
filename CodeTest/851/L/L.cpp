// 전구 뒤집기 : 충남대학교 SW_IT Contest L

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

vector<pair<int, bool> > bulb(200000);
vector<int> lux(200000, 5001);
vector<int> dp(200000, 0);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> bulb[i].first;
        lux[i] = bulb[i].first;
    }
    
    // if all bulbs are on,  flag == true
    bool flag = true;

    for(int i = 0; i < n; i++) {
        cin >> bulb[i].second;
        // i'nd bulb is on
        if(bulb[i].second) {
            sum += bulb[i].first;
            bulb[i].first *= -1;
        }
        // ... is off
        else flag = false;
        
        dp[0] = max((bulb[0].second ? bulb[0].first : lux[0]), 0);
        if(i) dp[i] = max(dp[i -1] + bulb[i].first, 0);
    }
    
    // all bulbs are on
    sort(lux.begin(), lux.end());
    if(flag) {
        cout << sum - lux[0];
        return 0;
    }

    cout << sum + dp[max_element(dp.begin(), dp.end()) - dp.begin()];
}