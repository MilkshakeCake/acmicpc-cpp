// AC - Baekjoon Online Judge #5430

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
#include <sstream>

#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fr first
#define sc second
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define EACH(x, a) for (auto& x : a)

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        string P;
        cin >> P;

        deque<int> dq;
        bool flag = false;
        bool error = false;

        int n;
        cin >> n;
        string num;
        cin >> num;
		num.erase(0, 1);
		num.erase(num.size() - 1, 1);

		istringstream istr(num);

        string str;
		while (getline(istr, str, ',')) {
			dq.push_back(stoi(str));
		}

        int start = 0;
        int end = n;

        for(int j = 0; j < sz(P); j++) {
            if(P[j] == 'R') {
                flag = !flag;
            }

            else {
                if(start == end) {
                    error = true;
                    cout << "error" << endl;
                    break;
                }

                if(flag) {
                    end--;
                }
                else {
                    start++;
                }
            }
        }
        
        if(error) continue;

        cout << '[';
        if(!flag) {
            for(int j = start; j < end; j++) {
                cout << dq[j];
                if(j != end -1) cout << ',';
            }
        }

        else {
            for(int j = end - 1; j >= start; j--) {
                cout << dq[j];
                if(j != start) cout << ',';
            }

        }
        cout << ']' << endl;
    }
}