// 인간-컴퓨터 상호작용 - BOJ #16139

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fr first
#define sc second
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define printall(i, a) for (auto &i : a) cout << i << ' '

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