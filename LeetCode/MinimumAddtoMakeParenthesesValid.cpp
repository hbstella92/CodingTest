#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	int minAddToMakeValid(string s) {
		int ans = 0;
		int s_len = s.length();
		stack<char> stck;
		char tmp;

		for (int i = 0; i < s_len; i++) {
			if (s[i] == '(') {
				stck.push(s[i]);
			}
			else {
				if (!stck.empty()) {
					tmp = stck.top();

					if (tmp == '(') {
						stck.pop();
						continue;
					}
				}

				ans++;
			}
		}

		while (!stck.empty()) {
			stck.pop(); ans++;
		}

		return ans;
	}
};

int main() {
	Solution sol;

	cout << sol.minAddToMakeValid("())") << endl; // 1

	return 0;
}