// 충남대학교 SW_IT Contest L

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
vector<int> preserve(200000, 0);
vector<int> idk(200000, 0);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> bulb[i].first;
        preserve[i] = bulb[i].first;
    }

    for(int i = 0; i < n; i++) {
        cin >> bulb[i].second;
        if(!bulb[i].second) {
            sum += bulb[i].first;
            bulb[i].first *= -1;
        }
        if(i) idk[i] = max(idk[i -1] + bulb[i].first, 0);
    }

    
}