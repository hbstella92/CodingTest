#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string removeOccurrences(string s, string part) {
		int s_len = s.length();
		int p_len = part.length();
		string origin = s, cmp = "";

		int i = 0;
		string tmp = "";
		for (; i < s_len - p_len + 1; i++) {
			cmp = s.substr(i, p_len);

			if (cmp == part) {
				if (!i) tmp = s.substr(i + p_len);
				else tmp = s.substr(0, i) + s.substr(i + p_len);

				s = tmp;
				i = -1;
				s_len -= p_len;
			}
		}

		return s;
	}
};

int main() {
	Solution sol;

	cout << sol.removeOccurrences("daabcbaabcbc", "abc") << endl; // dab

	return 0;
}