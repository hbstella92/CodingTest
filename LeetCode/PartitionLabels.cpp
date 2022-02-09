#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> partitionLabels(string s) {
		vector<int> ans;
		int end_idx[26] = { 0, };
		int s_len = s.length();

		for (int i = 0; i < s_len; i++) {
			end_idx[s[i] - 'a'] = i;
		}

		for (int i = 0; i < s_len; i++) {
			int border = end_idx[s[i] - 'a'];

			for (int j = i + 1; j <= border; j++) {
				if (border < end_idx[s[j] - 'a']) {
					border = end_idx[s[j] - 'a'];
				}
			}

			ans.push_back(border - i + 1);
			i = border;
		}

		return ans;
	}
};

int main() {
	Solution sol;
	vector<int> ans = sol.partitionLabels("ababcbacadefegdehijhklij");
	int ans_sz = ans.size();

	for (int i = 0; i < ans_sz; i++) {
		cout << ans[i] << " "; // [9,7,8]
	} cout << endl;

	return 0;
}