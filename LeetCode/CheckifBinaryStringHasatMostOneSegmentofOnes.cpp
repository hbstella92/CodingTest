#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool checkOnesSegment(string s) {
		int len = s.length();
		int flag = 0, cnt = 0;
		int cmp_cnt = 0;

		for (int i = 0; i < len; i++) {
			if (s[i] == '1') cnt++;
		}

		for (int i = 0; i < len; i++) {
			if (s[i] == '1') {
				if (!flag) {
					flag = 1;
				}
				cmp_cnt++;
			}
			else {
				if (flag) {
					if (cnt != cmp_cnt) return false;
					else break;
				}
			}
		}

		return true;
	}
};

int main() {
	Solution sol;

	if (sol.checkOnesSegment("1001") == true) { // FALSE
	//if (sol.checkOnesSegment("110") == true) { // TRUE
	//if (sol.checkOnesSegment("1") == true) { // TRUE
		cout << "true\n";
	}
	else {
		cout << "false\n";
	}

	return 0;
}