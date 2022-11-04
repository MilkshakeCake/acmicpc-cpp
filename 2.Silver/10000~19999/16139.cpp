// 인간-컴퓨터 상호작용 - Baekjoon Online Judge no.16139

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

int board[26][200001] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string str;
    cin >> str;

    int qnum;
    cin >> qnum;
    board[(int)str[0] -97][1] = 1;
    for(int i = 2; i <= (int)str.length(); i++) {
        for(int j = 0; j < 26; j++) {
            board[j][i] = board[j][i-1];
        }
        board[(int)str[i-1] - 97][i]++;
    }

    while(qnum--) {
        char ch;
        int start, end;
        cin >> ch >> start >> end;
        int chnum = (int)ch - 97;
        cout << board[chnum][end + 1] - board[chnum][start]<< '\n';
    }
}