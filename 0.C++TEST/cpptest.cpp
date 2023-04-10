// Practice Techniques of C++

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
#define printall(i, a) for (auto &i : a) cout << i << ' '

using namespace std;

class Person {
    string name;
    string tel;

    public:
    Person() {};
    void setName(string name) {this->name = name; this->tel = ""; }
    string getName() {return name; }
    string getTel() {return tel; }
    void set(string name, string tel) {this->name = name; this->tel = tel; }
};

class Family {
    string name;
    int size;
    Person *p;

    public:
    Family(string name, int size) {
        this->name = name;
        this->size = size;
        this->p = new Person[size];
    }

    void setName(int num, string name) {
        this->p[num].setName(name);
    }

    void show() {
        for(int i = 0; i < size; i++) {
            cout << p[i].getName() << ' ';
        }
    }
    ~Family() {};
};

int main() {
    Family *simpson = new Family("Simpson", 3);
    simpson->setName(0, "Mr. Simpson");
    simpson->setName(1, "Mrs. Simpson");
    simpson->setName(2, "Bart Simpson");
    simpson->show();
    delete simpson;
}