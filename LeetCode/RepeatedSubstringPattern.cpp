#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		int s_len = s.length();
		int substring_len = 1;

		string substring, cmpstring;
		int flag;
		for (int i = substring_len; i <= s_len / 2; i++) {
			if (s_len % i) continue;

			substring = s.substr(0, i);
			flag = 1;

			for (int j = i; j <= s_len - i; j+=i) {
				cmpstring = s.substr(j, i);
				if (substring != cmpstring) {
					flag = 0;
					break;
				}
			}

			if (flag) return true;
		}

		return false;
	}
};

int main() {
	Solution sol;

	//if (sol.repeatedSubstringPattern("abab") == true) {
	//if (sol.repeatedSubstringPattern("aba") == true) {
	//if (sol.repeatedSubstringPattern("abcabcabcabc") == true) {
	//if (sol.repeatedSubstringPattern("bb") == true) {
	//if (sol.repeatedSubstringPattern("aba") == true) {
	//if (sol.repeatedSubstringPattern("ababba") == true) {
	if (sol.repeatedSubstringPattern("aabaaba") == true) {
		cout << "true\n";
	}
	else {
		cout << "false\n";
	}

	return 0;
}