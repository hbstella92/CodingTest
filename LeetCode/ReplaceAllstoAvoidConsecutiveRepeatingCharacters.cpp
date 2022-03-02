#include <iostream>
#include <string>
using namespace std;

class Solution {
	public:
		string modifyString(string s) {
			int len = s.length();

			for (int i = 0; i < len; i++) {
				if (s[i] == '?') {
					for (s[i] = 'a'; s[i] <= 'c'; s[i]++) {
						if (((i == 0) || (s[i - 1] != s[i])) && ((i == len - 1) || (s[i] != s[i + 1]))) break;
					}
				}
			}

			return s;
		}
};

int main() {
	Solution sol;

	cout << sol.modifyString("?zs") << endl; // azs

	return 0;
}
