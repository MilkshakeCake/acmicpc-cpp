// 소수 부르기 게임 - 충남대학교 SW_IT Contest I
// BOJ #25632

#include <bits/stdc++.h>
#include <map>

using namespace std;

bool sosu(int num) {
	if (num < 2) return false;
	int a = (int) sqrt(num);
	for (int i = 2; i <= a; i++) if (num % i == 0) return false;
	return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string yt = "yt";
    string yj = "yj";
    
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int comS = max(a, c);
    int maxS = min(a, c);
    int comE = min(b, d);
    int maxE = max(b, d);
    int ytcnt = 0;
    int yjcnt = 0;
    int common = 0;

    for(int i = maxS; i <= maxE; i++) {
        if(sosu(i)) {
            if(comS <= i && i <= comE) common++;
            else if(a <= i && i <= b) ytcnt++;
            else if(c <= i && i <= d) yjcnt++;
        }
    }

    if(common % 2) {
        if(ytcnt >= yjcnt) cout << yt;
        else cout << yj;
    }
    else {
        if(ytcnt > yjcnt) cout << yt;
        else cout << yj;
    }
}