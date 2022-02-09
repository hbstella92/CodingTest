#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool backspaceCompare(string s, string t) {
		string new_s, new_t;
		int s_len = s.length(), t_len = t.length();
		int carry = 0, k = 0;

		for (int i = s_len - 1; i >= 0; i--) {
			if (s[i] == '#') {
				carry++;
			}
			else {
				if (carry) {
					if (k == 0) {
						carry--;
						continue;
					}

					new_s[k] = s[i];
					carry--;
				}
				else {
					new_s += s[i];
					k++;
				}
			}
		}

		carry = k = 0;
		for (int i = t_len - 1; i >= 0; i--) {
			if (t[i] == '#') {
				carry++;
			}
			else {
				if (carry) {
					if (k == 0) {
						carry--;
						continue;
					}

					new_t[k] = t[i];
					carry--;
				}
				else {
					new_t += t[i];
					k++;
				}
			}
		}

		reverse(new_s.begin(), new_s.end());
		reverse(new_t.begin(), new_t.end());

		return (new_s == new_t) ? true : false;
	}
};

int main() {
	Solution sol;

	if (sol.backspaceCompare("a#c", "b") == true) {
		cout << "true\n";
	}
	else {
		cout << "false\n";
	}

	return 0;
}