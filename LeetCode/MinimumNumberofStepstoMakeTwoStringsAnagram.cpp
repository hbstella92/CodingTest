#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int minSteps(string s, string t) {
		int ans = 0;
		int alpha[26];
		int len = s.length();

		fill_n(alpha, 26, 0);
		for (int i = 0; i < len; i++) {
			alpha[s[i] - 'a']++;
		}

		for (int i = 0; i < len; i++) {
			if (alpha[t[i] - 'a'] > 0) {
				alpha[t[i] - 'a']--;
			}
			else {
				ans++;
			}
		}

		return ans;
	}
};

int main() {
	Solution sol;

	cout << sol.minSteps("bab", "aba") << endl; // 1

	return 0;
}