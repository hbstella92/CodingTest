#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		int len = s.length();
		int replaced_char[128], used[128];
		fill_n(replaced_char, 128, -1);
		fill_n(used, 128, -1);

		for (int i = 0; i < len; i++) {
			if (replaced_char[s[i]] == -1) {
				if (used[t[i]] == 1) return false;
				replaced_char[s[i]] = t[i];
				used[t[i]] = 1;
			}
			else if(replaced_char[s[i]] != t[i]) {
				return false;
			}
		}

		return true;
	}
};

int main() {
	Solution sol;

	//if (sol.isIsomorphic("egg", "add") == true) { // true
	//if (sol.isIsomorphic("foo", "bar") == true) { // false
	//if (sol.isIsomorphic("paper", "title") == true) { // true
	if (sol.isIsomorphic("badc", "baba") == true) { // false
		cout << "true\n";
	}
	else {
		cout << "false\n";
	}

	return 0;
}