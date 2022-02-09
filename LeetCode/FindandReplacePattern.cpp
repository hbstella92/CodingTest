#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
		vector<string> ans;
		int vec_sz = words.size();
		int len = pattern.length();

		int cnt = 1;
		int pattern_arr[50] = { 0, };
		int idx[26] = { 0, };
		int flag[26] = { 0, };
		for (int i = 0; i < len; i++) {
			if (!flag[pattern[i] - 'a']) {
				flag[pattern[i] - 'a'] = 1;
				pattern_arr[i] = idx[pattern[i] - 'a'] = cnt;
				cnt++;
			}
			else {
				pattern_arr[i] = idx[pattern[i] - 'a'];
			}
		}

		for (int i = 0; i < vec_sz; i++) {
			int word_len = words[i].length();
			int cmp_pattern[26] = { 0, };
			int cmp_flag[26] = { 0, };
			cnt = 1;
			bool chk = true;

			for (int j = 0; j < word_len; j++) {
				if (!cmp_flag[words[i][j] - 'a']) {
					cmp_flag[words[i][j] - 'a'] = 1;
					cmp_pattern[words[i][j] - 'a'] = cnt;
					cnt++;
				}

				if (cmp_pattern[words[i][j] - 'a'] != pattern_arr[j]) {
					chk = false;
					break;
				}
			}

			if (chk) ans.push_back(words[i]);
		}

		return ans;
	}
};

int main() {
	Solution sol;
	vector<string> input = { "abc", "deq", "mee", "aqq", "dkd", "ccc" };

	vector<string> ans = sol.findAndReplacePattern(input, "abb");

	int sz = ans.size();
	for (int i = 0; i < sz; i++) {
		cout << ans[i] << endl; // ["mee", "aqq"]
	}

	return 0;
}