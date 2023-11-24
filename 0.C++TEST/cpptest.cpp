// Practice Techniques of C++

// #include <bits/stdc++.h>

#include <iostream>

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
#define printall(i, a) for (auto &i : a) cout << i << ' '

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char choice;
    cout << "is A?" << endl;
    cin >> choice;
    if(choice == 'y' || choice == 'Y') {
        cout << "is C?" << endl;
        cin >> choice;
        if(choice == 'y' || choice == 'Y') {
            cout << "A, C" << endl;
        }

        else cout << "A, D" << endl;
    }

    else {
        cout << "is C?" << endl;
        cin >> choice;
        if(choice == 'y' || choice == 'Y') {
            cout << "B, C" << endl;
        }

        else cout << "B, D" << endl;
    }
}