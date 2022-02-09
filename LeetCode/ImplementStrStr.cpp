#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle == "") return 0;

		string tmp = "";
		int h_len = haystack.length();
		int n_len = needle.length();
		for (int i = 0; i <= h_len - n_len; i++) {
			tmp = haystack.substr(i, n_len);

			if (tmp == needle) return i;
		}

		return -1;
	}
};

int main() {
	Solution sol;

	cout << sol.strStr("hello", "ll") << '\n' // 2

	return 0;
}