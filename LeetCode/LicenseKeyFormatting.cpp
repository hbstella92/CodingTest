#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Solution {
public:
	string licenseKeyFormatting(string s, int k) {
		string ans = "";
		int s_len = s.length();

		string tmp = "";
		for (int i = 0; i < s_len; i++) {
			if (s[i] == '-') {
				continue;
			}
			else if (s[i] >= 97 && s[i] <= 122) {
				s[i] -= 32;
			}

			tmp += s[i];
		}
		int tmp_len = tmp.length();

		if (tmp_len % k) {
			for (int i = 0, j = tmp_len % k; i < s_len, j > 0; i++) {
				if (s[i] != '-') {
					ans += s[i];
					j--;
				}
			}
			ans += '-';

			tmp = tmp.substr(ans.length() - 1);
		}
		tmp_len = tmp.length();

		if (!tmp_len) {
			ans = ans.substr(0, ans.length() - 1);
		}

		int cnt = k;
		for (int i = 0; i < tmp_len; i++) {
			ans += tmp[i];
			cnt--;

			if (!cnt && (i != (tmp_len - 1))) {
				cnt = k;
				ans += '-';
			}
		}

		return ans;
	}
};

int main() {
	Solution sol;

	cout << sol.licenseKeyFormatting("5F3Z-2e-9-w", 4) << '\n'; // 5F3Z-2E9W
	cout << sol.licenseKeyFormatting("2-5G-3-J", 2) << '\n'; // 2-5G-3J
	cout << sol.licenseKeyFormatting("2-4A0r7-4k", 4) << '\n'; //  24A0-R74K
	cout << sol.licenseKeyFormatting("2-4A0r7-4k", 3) << '\n'; //  24-A0R-74K
	cout << sol.licenseKeyFormatting("2", 2) << '\n'; //  2

	return 0;
}