#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string reverseParentheses(string s) {
		int len = s.length();
		string tmp = "";

		int start = len - 1, end = 0;
		while (1) {
			while (s[start] != '(') {
				start--;
				if (start < 0) break;
			}
			if (start < 0) break;

			end = start + 1;
			while (s[end] != ')') {
				end++;
				if (end >= len) break;
			}
			if (end >= len)break;

			tmp = "";
			for (int i = end - 1; i > start; i--) {
				tmp += s[i];
			}

			if (!start) s = tmp + s.substr(end + 1);
			else s = s.substr(0, start) + tmp + s.substr(end + 1);
			len -= 2;
		}

		return s;
	}
};

int main() {
	Solution sol;

	cout << sol.reverseParentheses("(abcd)") << endl; // dcba

	return 0;
}