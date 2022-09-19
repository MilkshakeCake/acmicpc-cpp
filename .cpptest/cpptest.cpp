// Practice techniques of C++

#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <deque>
#include <map>

#define all(v) (v).begin(), (v).end()

using namespace std;

int main() {
    ifstream readFile;
    readFile.open("text.txt");
    int n;
    cin >> n;
    string str;
    for(int i = 0; i < n; i++) {
        getline(readFile, str);
        cout << str << '\n';
    }
}