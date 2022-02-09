#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> ans;
	string str;
	int str_len;
	int alpha_flag[12] = { 0, };
	int flag[12] = { 0, };

	void dfs(int idx, int cur_num, int n) {
		if (cur_num == n) {
			string reverse_str = str;
			for (int i = 0; i < str_len; i++) {
				if (flag[i]) {
					reverse_str[i] = (reverse_str[i] >= 'a' && reverse_str[i] <= 'z') ? (reverse_str[i] - 32) : (reverse_str[i] + 32);
				}
			}
			ans.push_back(reverse_str);
			return;
		}

		for (int i = idx; i < str_len; i++) {
			if (alpha_flag[i]) {
				flag[i] = 1;
				dfs(i + 1, cur_num + 1, n);
				flag[i] = 0;
			}
		}
	}

	vector<string> letterCasePermutation(string s) {
		str = s;
		str_len = s.length();

		for (int i = 0; i < str_len; i++) {
			if (s[i] >= '0' && s[i] <= '9') continue;
			alpha_flag[i] = 1;
		}

		ans.push_back(s);
		for (int i = 1; i <= str_len; i++) {
			dfs(0, 0, i);
		}

		return ans;
	}
};

int main() {
	Solution sol;

	vector<string> output = sol.letterCasePermutation("a1b2");
	int sz = output.size();
	for (int i = 0; i < sz; i++) {
		cout << output[i] << ' ';
	} cout << endl;

	return 0;
}