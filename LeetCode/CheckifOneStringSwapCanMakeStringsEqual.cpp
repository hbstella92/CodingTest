#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool areAlmostEqual(string s1, string s2) {
		int s1_len = s1.length();
		int s2_len = s2.length();

		if (s1_len != s2_len) return false;

		int idx1 = -1, idx2 = -1;
		for (int i = 0; i < s1_len; i++) {
			if (s1[i] != s2[i]) {
				if (idx1 == -1) {
					idx1 = i;
				}
				else {
					idx2 = i;
					break;
				}
			}
		}

		if (idx1 != -1 && idx2 != -1) {
			char tmp;
			tmp = s1[idx1];
			s1[idx1] = s1[idx2];
			s1[idx2] = tmp;
		}

		if (s1 != s2) return false;

		return true;
	}
};

int main() {
	Solution sol;

	if (sol.areAlmostEqual("bank", "kanb") == true) {
		cout << "true\n";
	}
	else {
		cout << "false\n";
	}

	return 0;
}