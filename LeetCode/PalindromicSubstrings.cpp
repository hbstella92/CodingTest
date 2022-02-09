#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int countSubstrings(string s) {
		int ans = 0;
		int len = s.length();

		ans += len;
		for (int i = 2; i <= len; i++) {
			for (int j = 0; j < len; j++) {
				if (j + i > len) break;
				string tmp = s.substr(j, i);

				int l = tmp.length();
				bool check = true;
				for (int k = 0; k < (l / 2); k++) {
					if (tmp[k] != tmp[l - k - 1]) {
						check = false;
						break;
					}
				}

				if (check) ans++;
			}
		}

		return ans;
	}
};

int main() {
	Solution sol;

	cout << sol.countSubstrings("abc") << endl; // 3

	return 0;
}