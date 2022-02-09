#include <iostream>
using namespace std;

class Solution {
public:
	bool checkRecord(string s) {
		int record[3] = { 0, };
		int s_len = s.length();
		int absent_cnt = 0, prev_late = 0;

		for (int i = 0; i < s_len; i++) {
			if (s[i] == 'P') {
				prev_late = 0;
				continue;
			}
			else if (s[i] == 'A') {
				absent_cnt++;
				if (absent_cnt == 2) return false;

				prev_late = 0;
			}
			else if (s[i] == 'L') {
				prev_late++;

				if (prev_late == 3) return false;
			}
		}

		return true;
	}
};

int main() {
	Solution sol;
	
	if (sol.checkRecord("PPALLP") == true) {
		cout << "true\n";
	}
	else {
		cout << "false\n";
	}

	return 0;
}