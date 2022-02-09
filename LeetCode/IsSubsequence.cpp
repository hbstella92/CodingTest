#include <iostream>
using namespace std;

class Solution {
public:
	bool isSubsequence(string s, string t) {
		int len_t = t.length();
		int len_s = s.length();
		int cur_s = 0, cnt = 0;

		for (int i = 0; i < len_t; i++) {
			if (s[cur_s] == t[i]) {
				cnt++;
				cur_s++;
			}

		}

		if (cnt == len_s) return true;
		return false;
	}
};

int main() {
	Solution sol;
	if (sol.isSubsequence("axc", "ahbgdc") == true) cout << "true\n";
	else cout << "false\n";

	return 0;
}