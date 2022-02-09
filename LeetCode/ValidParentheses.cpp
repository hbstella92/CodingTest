#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		vector<char> stack;
		int s_len = s.length();

		if (s_len == 1) return false;

		for (int i = 0; i < s_len; i++) {
			if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
				stack.push_back(s[i]);
			}
			else {
				if (!stack.size()) return false;

				char cmp = stack.back();
				stack.pop_back();

				if (!((cmp == '(' && s[i] == ')') ||
					(cmp == '{' && s[i] == '}') ||
					(cmp == '[' && s[i] == ']'))) {
					return false;
				}
			}
		}

		if (stack.size()) return false;

		return true;
	}
};

int main() {
	Solution sol;

	//if (sol.isValid("()") == true) { // true
	//if (sol.isValid("()[]{}") == true) { // true
	//if (sol.isValid("(]") == true) { // false
	//if (sol.isValid("{[]}") == true) { // true
	//if (sol.isValid("[") == true) { // false
	if (sol.isValid("((") == true) { // false
		cout << "true\n";
	}
	else {
		cout << "false\n";
	}

	return 0;
}