#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int ans = 0;

	vector<string> v;
	int v_sz;

	int pair_pick[2];
	int pick[100];

	void dfs(string target, int cur) {
		if (cur == 2) {
			string tmp = "";
			tmp = v[pair_pick[0]] + v[pair_pick[1]];

			if (target == tmp) {
				ans++;
			}
			return;
		}

		for (int i = 0; i < v_sz; i++) {
			if (pick[i] == 0) {
				pick[i] = 1;
				pair_pick[cur] = i;
				dfs(target, cur + 1);
				pick[i] = 0;
			}
		}
	}

	int numOfPairs(vector<string>& nums, string target) {
		v = nums;
		v_sz = v.size();
		fill_n(pick, 100, 0);

		dfs(target, 0);
		return ans;
	}
};

int main() {
	Solution sol;
	vector<string> input = { "777","7","77","77" };

	cout << sol.numOfPairs(input, "7777") << endl; // 4

	return 0;
}