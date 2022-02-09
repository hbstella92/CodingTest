#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CombinationIterator {
public:
	vector<string> v;
	int v_sz = 0;
	int cnt = 0;

	int pick_idx[15];
	int pick[15];

	string origin_str;
	int len;

	CombinationIterator(string characters, int combinationLength) {
		origin_str = characters;
		len = characters.length();

		fill_n(pick_idx, 15, -1);
		fill_n(pick, 15, 0);

		dfs(0, 0, combinationLength);
	}

	string next() {
		return v[cnt++];
	}

	bool hasNext() {
		return (cnt < v_sz);
	}

	void dfs(int idx, int cur, int n) {
		if (cur == n) {
			string tmp = "";
			for (int i = 0; i < n; i++) {
				tmp += origin_str[pick_idx[i]];
			}

			//v[v_sz++] = tmp;
			v.push_back(tmp); v_sz++;
			return;
		}

		for (int i = idx; i < len; i++) {
			if (!pick[i]) {
				pick[i] = 1;
				pick_idx[cur] = i;

				dfs(i + 1, cur + 1, n);

				pick_idx[cur] = -1;
				pick[i] = 0;
			}
		}
	}
};

int main() {
	CombinationIterator obj = CombinationIterator("abc", 2);

	cout << obj.next() << endl; // ab
	if (obj.hasNext()) { // True
		cout << "True\n";
	}
	else {
		cout << "False\n";
	}
	cout << obj.next() << endl; // ac
	if (obj.hasNext()) { // True
		cout << "True\n";
	}
	else {
		cout << "False\n";
	}
	cout << obj.next() << endl; // bc
	if (obj.hasNext()) { // False
		cout << "True\n";
	}
	else {
		cout << "False\n";
	}

	return 0;
}