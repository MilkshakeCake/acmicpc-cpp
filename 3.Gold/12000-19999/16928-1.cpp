// 뱀과 사다리 게임 - BOJ #16928 V2

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

vt<int> board(102, 0);
vt<int> graph(102, 0);

void bfs() {
    queue<int> que;
    que.push(1);
    board[1] = 0;
    
    while(!que.empty()) {
        int v = que.front();
        que.pop();

        for(int i = 1; i <= 6; i++) {
            int nav = v + i;
            if(nav > 100) break;
            
            if(graph[nav] != 0) {
                nav = graph[nav];
            }

            if(board[nav] == 0) {   // not visited
                que.push(nav);
                board[nav] = board[v] +1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, head, tail;
    cin >> n >> m;

    while(n--) {
        cin >> head >> tail;
        graph[head] = tail;
    }

    while(m--) {
        cin >> head >> tail;
        graph[head] = tail;
    }

    bfs();

    cout << board[100];
}