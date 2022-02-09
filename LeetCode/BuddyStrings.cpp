#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool buddyStrings(string s, string goal) {
		int s_len = s.length();
		int goal_len = goal.length();
		string cmp = "";
		int flag[123];

		if (s_len != goal_len) return false;

		fill_n(flag, 123, 0);
		if (s == goal) {
			for (int i = 0; i < s_len; i++) {
				if (!flag[s[i]]) {
					flag[s[i]] = 1;
				}
				else {
					return true;
				}
			}

			return false;
		}

		if (s_len == 2) {
			reverse(s.begin(), s.end());
			if (s == goal) return true;
		}
		else {
			for (int i = 0; i < s_len - 1; i++) {
				for (int j = i + 1; j < s_len; j++) {
					if (s[i] == s[j]) continue;
					cmp = s;
					char tmp = s[i];
					cmp[i] = cmp[j];
					cmp[j] = tmp;
				
					if (cmp == goal) return true;
				}
			}
		}

		return false;
	}
};

int main() {
	Solution sol;

	//if (sol.buddyStrings("ab", "ba")) { // TRUE
	//if(sol.buddyStrings("ab", "ab")) { //	 FALSE
	//if(sol.buddyStrings("aa", "aa")) { // TRUE
	//if(sol.buddyStrings("aaaaaaabc", "aaaaaaacb")) { // TRUE
	//if(sol.buddyStrings("abab", "abab")) { // TRUE
	if(sol.buddyStrings("abcd", "abcd")) { // FALSE
		cout << "true\n";
	}
	else {
		cout << "false\n";
	}

	return 0;
}