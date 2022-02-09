#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minimumSwap(string s1, string s2) {
		int ans = 0;
		int len = s1.length();
		int x_cnt = 0, y_cnt = 0;

		for (int i = 0; i < len; i++) {
			if (s1[i] == 'x') {
				x_cnt++;
			}
			else y_cnt++;

			if (s2[i] == 'x') {
				x_cnt++;
			}
			else y_cnt++;
		}
		x_cnt /= 2, y_cnt /= 2;
		int cmp_len = x_cnt + y_cnt;
		if (len != cmp_len) return -1;

		string new_s1 = "";
		for (int i = 0; i < len; i++) {
			if (s1[i] != s2[i]) {
				new_s1 += s1[i];
			}
		}

		string tmp = "";
		int new_len = new_s1.length();
		sort(new_s1.begin(), new_s1.end());

		for (int i = 0; i <= new_len - 2; i += 2) {
			tmp = new_s1.substr(i, 2);

			if (tmp == "xx" || tmp == "yy") {
				ans++;
			}
			else if (tmp == "xy" || tmp == "yx") {
				ans += 2;
			}
		}

		return ans;
	}
};

int main() {
	Solution sol;

	// cout << sol.minimumSwap("xx", "yy") << endl; // 1
	cout << sol.minimumSwap("xxyyxyxyxx", "xyyxyxxxyx") << endl; // 4

	return 0;
}