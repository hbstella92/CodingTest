#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool validPalindrome(string s) {
		bool ans = true;
		int s_len = s.length();
		int once = 0;
		int i = 0, j = s_len - 1;

		while (i < j) {
			if (s[i] != s[j]) {
				if (once) {
					ans = false;
					break;
				}

				if (s[i + 1] == s[j]) {
					i++;
					once = 1;
				}
				else ans = false;
			}

			if (!ans) break;
			i++, j--;
		}

		if (ans) return ans;

		ans = true;
		i = 0, j = s_len - 1;
		once = 0;

		while (i < j) {
			if (s[i] != s[j]) {
				if (once) {
					ans = false;
					break;
				}

				if (s[i] == s[j - 1]) {
					j--;
					once = 1;
				}
				else ans = false;
			}

			if (!ans) break;
			i++, j--;
		}

		return ans;
	}
};

int main() {
	Solution sol;

	// (sol.validPalindrome("aba") == true) { // TRUE
	//if (sol.validPalindrome("abca") == true) { // TRUE
	//if (sol.validPalindrome("abc") == true) { // FALSE
	//if (sol.validPalindrome("acjakebdccdeedccdbeaca") == true) { // FALSE
	if (sol.validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga") == true) { // TRUE
		cout << "true\n";
	}
	else {
		cout << "false\n";
	}

	return 0;
}