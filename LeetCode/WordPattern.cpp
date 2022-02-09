#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string s) {
		map<char, string> m;
		map<string, int> check;
		int pattern_len = pattern.length();
		int word_cnt = 1;

		for (int i = 0; i < pattern_len; i++) {
			int idx = s.find(" ");
			string sub = s.substr(0, idx);
			if (idx != -1) word_cnt++;

			if (m[pattern[i]] == "" && check[sub] == 0) {
				m[pattern[i]] = sub;
				check[sub] = 1;
			}
			else if (m[pattern[i]] != "") {
				if (m[pattern[i]] != sub) {
					return false;
				}
			}
			else if (check[sub]) {
				return false;
			}

			s = s.substr(idx + 1);
		}

		if (word_cnt != pattern_len) return false;

		return true;
	}
};

int main() {
	Solution sol;

	if (sol.wordPattern("abba", "dog cat cat dog") == true) {
		cout << "true\n";
	}
	else {
		cout << "false\n";
	}

	return 0;
}