#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int characterReplacement(string s, int k) {
		int s_len = s.length();
		int ans = 0;

		int count[26];
		fill_n(count, 26, 0);
		int max_count = 0;

		for (int start = 0, end = 0; end < s_len; end++) {
			count[s[end] - 'A']++;
			max_count = max(max_count, count[s[end] - 'A']);

			if ((end - start + 1) - max_count > k) {
				count[s[start] - 'A']--;
				start++;
			}
			else {
				ans = max(ans, (end - start + 1));
			}
		}

		return ans;
	}
};

int main() {
	Solution sol;

	cout << sol.characterReplacement("ABAB", 2) << endl; // 4

	return 0;
}