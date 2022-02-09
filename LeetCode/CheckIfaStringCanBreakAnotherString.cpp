#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool checkIfCanBreak(string s1, string s2) {
		int len = s1.length();
		bool ans1 = true, ans2 = true;

		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());

		for (int i = 0; i < len; i++) {
			if (s1[i] > s2[i]) ans1 = false;
			if (s2[i] > s1[i]) ans2 = false;
		}

		if (ans1 || ans2) return true;
		return false;
	}
};

int main() {
	Solution sol;

	if (sol.checkIfCanBreak("abe", "acd")) { // false
		cout << "true\n";
	}
	else {
		cout << "false\n";
	}

	return 0;
}