#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int countSubstrings(string s, string t) {
		int ans = 0;
		int s_len = s.length(), t_len = t.length();

		string subS = "", subT = "";
		for (int i = 1; i <= s_len; i++) {
			for (int j = 0; j < s_len; j++) {
				subS = s.substr(j, i);

				for (int k = 0; k < t_len; k++) {
					subT = t.substr(k, i);

					if (subS.length() != subT.length()) break;

					int diff = 0;
					for (int m = 0; m < i; m++) {
						if (subS[m] != subT[m]) diff++;
						if (diff > 1) break;
					}

					if (diff == 1) {
						ans++;
					}
				}
			}
		}

		return ans;
	}
};

int main() {
	Solution sol;

	cout << sol.countSubstrings("aba", "baba") << endl; // 6

	return 0;
}