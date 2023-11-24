// "Project_Name" - BOJ #

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define pii pair<int, int>
#define pll pair<long, long>
#define fr first
#define sc second
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define printall(i, a) for (auto &i : a) cout << i << endl
#define endl '\n'

using namespace std;

bool compare (const string& s1, const string s2) {
        if(s1.length() == s2.length()) return s1 < s2;
		return s1.length() < s2.length();
};


bool compare2 (const string& s1, const string s2) {
        return s1 < s2;
};

int main() {    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    cin.ignore();
    string str;
    char delim = '\n';

    // priority_queue<string, vt<string>, compare2> boj;
    vector<string> bojs;
    vector<string> todos;
    // priority_queue<string, vt<string>, compare> todo;

    for(int i = 0; i < n; i++) {
        getline(cin, str, delim);
        if(str.substr(0, 6) == "boj.kr") {
            // boj.push(str);
            bojs.push_back(str);
        }
        else {
            // todo.push(str);
            todos.push_back(str);
        }
    }

    sort(all(bojs), compare2);
    sort(all(todos), compare);

    printall(i, todos);
    printall(i, bojs);

    // while(!todo.empty()) {
    //     cout << todo.top() << endl;
    //     todo.pop();
    // }

    // while(!boj.empty()) {
    //     cout << boj.top() << endl;
    //     boj.pop();
    // }
}