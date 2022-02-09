#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	int scoreOfParentheses(string s) {
		int ans = 0;
		int len = s.length();
		stack<int> stk;
		stk.push(0);

		for (int i = 0; i < len; i++) {
			if (s[i] == '(') {
				stk.push(0);
			}
			else {
				int val = stk.top(); stk.pop();
				int sum = 0;

				if (!val) {
					sum = 1;
				}
				else {
					sum = (val * 2);
				}

				stk.top() += sum;
			}
		}
		ans = stk.top();
		return ans;
	}
};

int main() {
	Solution sol;

	//cout << sol.scoreOfParentheses("()") << endl; // 1
	//cout << sol.scoreOfParentheses("(())()") << endl; // 3
	cout << sol.scoreOfParentheses("(()(()))") << endl; // 6

	return 0;
}