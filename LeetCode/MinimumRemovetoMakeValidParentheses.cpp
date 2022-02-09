#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
	string minRemoveToMakeValid(string s) {
		string ans = "";
		int len = s.length();

		stack<char> stck;
		vector<int> idx;

		for (int i = 0; i < len; i++) {
			if (s[i] == '(') {
				stck.push('(');
				idx.push_back(i);
			}
			else if (s[i] == ')') {
				if (!stck.empty()) {
					char tmp = stck.top();

					if (tmp == '(') {
						stck.pop();
						idx.pop_back();
						continue;
					}
				}

				stck.push(')');
				idx.push_back(i);
			}
		}

		int sz = idx.size();
		for (int i = 0, n = 0; i < len; i++) {
			if (n == sz) {
				ans += s[i];
				continue;
			}

			if (idx[n] == i) {
				n++;
				continue;
			}
			ans += s[i];
		}

		return ans;
	}
};

int main() {
	Solution sol;

	cout << sol.minRemoveToMakeValid("lee(t(c)o)de)") << endl; // lee(t(c)o)de

	return 0;
}