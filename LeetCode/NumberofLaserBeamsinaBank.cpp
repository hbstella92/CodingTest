#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int numberOfBeams(vector<string>& bank) {
		int ans = 0;
		int sz = bank.size(), len = bank[0].length();
		int cnt = 0, prev_cnt = 0;

		for (int i = 0; i < sz; i++) {
			cnt = count(bank[i].begin(), bank[i].end(), '1');
			if (cnt) {
				ans += (prev_cnt * cnt);
				prev_cnt = cnt;
			}
		}

		return ans;
	}
};

int main() {
	Solution sol;
	vector<string> input = { "011001", "000000", "010100", "001000" };

	cout << sol.numberOfBeams(input) << endl; // 8

	return 0;
}