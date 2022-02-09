#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int ans = 0;
		int s_len = s.length();

		int eidx = -1;
		for (int i = s_len - 1; i >= 0; i--) {
			if (s[i] == ' ') {
				if (eidx != -1) break;
			}
			else {
				ans++;
				if (eidx == -1) eidx = i;
			}
		}

		return ans;
	}
};

int main() {
	Solution sol;

	cout << sol.lengthOfLastWord("Hello World") << '\n'; // 5

	return 0;
}