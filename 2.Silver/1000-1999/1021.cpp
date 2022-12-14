// 회전하는 큐 - BOJ #1021

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fr first
#define sc second
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

using namespace std;

deque<int> DQ;

void rotateL() {
    DQ.push_back(DQ.front());
    DQ.pop_front();
}

void rotateR() {
    DQ.push_front(DQ.back());
    DQ.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;

int left, right;
	int cnt = 0;
	
	for(int i = 1; i <= N; i++){
		DQ.push_back(i);
	}
	

	while(M--){
		int num;
		cin >> num;
		
		for(int i = 0; i < DQ.size(); i++){
			
			if(DQ[i] == num){
				left = i;
				right = DQ.size() - i;
				break;
				
			}
		}
		
		if(left <= right) {
			while(true) {
				if(DQ.front() == num) break;

				DQ.push_back(DQ.front());
				DQ.pop_front();
				cnt++;
				
			}
			DQ.pop_front();
		}
		
		else{
			cnt++;
			while(true) {
				if(DQ.back() == num) break;
	
				DQ.push_front(DQ.back());
				DQ.pop_back();
				cnt++;
				
			}
			DQ.pop_back();
		}

	}
	
	cout << cnt;
	
	return 0;
}