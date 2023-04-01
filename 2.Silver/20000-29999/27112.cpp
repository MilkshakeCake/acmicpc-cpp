#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct work {
	int deadline;
	int time;
	int num;

	void printall() {
		cout << deadline << ' ' << time << ' ' << num << '\n';
	}
};

struct compare {
	bool operator()(const work& w1, const work w2) {
		return w1.deadline > w2.deadline;
	}
};

int main() {
	int n, d, t;
	bool flag = true;
	cin >> n;
	priority_queue<work, vector<work>, compare> todo;
	vector<int> daytime;
	vector<int> overtime;
	for (int i = 0; i < n; i++) {
		cin >> d >> t;
		todo.push({ d, t, i });
	}

	while (!todo.empty()) {
		if (daytime.size() % 7 > 4) daytime.push_back(-1);
		auto now = todo.top();
		todo.pop();
		if (now.time > 1) todo.push({ now.deadline, now.time - 1, now.num });
		
		if (now.deadline > (int)daytime.size()) {
			daytime.push_back(now.num);
			continue;
		}

		if (now.deadline > (int)overtime.size()) {
			overtime.push_back(now.num);
			continue;
		}
		flag = false;
		break;
	}

	cout << (flag ? (int)overtime.size() : -1);
}
