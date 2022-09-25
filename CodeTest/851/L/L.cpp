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
    
    bool flag = true;

    for(int i = 0; i < n; i++) {
        cin >> bulb[i].second;
        if(!bulb[i].second) {
            sum += bulb[i].first;
            bulb[i].first *= -1;
        }
        else flag = false;
        
        if(i) idk[i] = max(idk[i -1] + bulb[i].first, 0);
    }
    
    if(!flag) {
        cout << sum - preserve[min_element(preserve.begin(), preserve.end()) - preserve.begin];
        return 0;
    }

    cout << sum + idk[max_element(idk.begin(), idk.end()) - idk.begin()];
}