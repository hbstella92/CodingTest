#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	string ans = "";
	bool success = false;

	void dfs(int n, int cnt, string candi, unordered_map<string, int> &m) {
		if (success) return;

		if (n == cnt) {
			if (m[candi] != 1) {
				ans = candi;
				success = true;
			}
			return;
		}

		string tmp = candi;
		candi += '0';
		dfs(n, cnt + 1, candi, m);

		candi = tmp;
		candi += '1';
		dfs(n, cnt + 1, candi, m);
	}

	string findDifferentBinaryString(vector<string>& nums) {
		int v_sz = nums.size();
		int n = nums[0].length();
		
		sort(nums.begin(), nums.end());
		unordered_map<string, int> m;
		for (int i = 0; i < v_sz; i++) {
			m[nums[i]] = 1;
		}

		string candi = "";
		dfs(n, 0, candi, m);

		return ans;
	}
};

int main() {
	Solution sol;
	vector<string> input;

	input.push_back("01");
	input.push_back("10");

	cout << sol.findDifferentBinaryString(input) << endl; // 11

	return 0;
}