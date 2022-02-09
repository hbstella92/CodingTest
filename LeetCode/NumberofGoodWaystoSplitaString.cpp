#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Solution {
public:
	int numSplits(string s) {
		int ans = 0;
		int s_len = s.length();

		int cnt1[26] = { 0, }, cnt2[26] = { 0, };
		int num1 = 0, num2 = 0;

		num1++;
		cnt1[s[0] - 'a']++;
		for (int i = 1; i < s_len; i++) {
			if (!cnt2[s[i] - 'a']) {
				num2++;
			}
			cnt2[s[i] - 'a']++;
		}

		if (num1 == num2) ans++;
		for (int i = 1; i < s_len - 1; i++) {
			if (!cnt1[s[i] - 'a']) {
				num1++;
				cnt1[s[i] - 'a']++;
			}
			if (cnt2[s[i] - 'a'] == 1) {
				num2--;
			}
			cnt2[s[i] - 'a']--;
			if (num1 == num2) ans++;
		}

		return ans;
	}
};

int main() {
	Solution sol;

	cout << sol.numSplits("aacaba") << endl; // 2

	return 0;
}