#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		string input_string = "";
		int s_len = s.length();

		for (int i = 0; i < s_len; i++) {
			if (s[i] >= 65 && s[i] <= 90) {
				s[i] += 32;
				input_string += s[i];
			}
			else if (s[i] >= 97 && s[i] <= 122) {
				input_string += s[i];
			}
			else if (s[i] >= 48 && s[i] <= 57) {
				input_string += s[i];
			}
			else {
				continue;
			}
		}

		int input_len = input_string.length();
		for (int i = 0; i < input_len / 2; i++) {
			if (input_string[i] != input_string[input_len - i - 1]) {
				return false;
			}
		}

		return true;
	}
};

int main() {
	Solution sol;

	//if (sol.isPalindrome("A man, a plan, a canal: Panama") == true) {
	//if (sol.isPalindrome("race a car") == true) {
	if (sol.isPalindrome(" ") == true) {
		cout << "true\n";
	}
	else {
		cout << "false\n";
	}

	return 0;
}