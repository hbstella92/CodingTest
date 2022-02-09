#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int countSegments(string s) {
		int cnt = 0;
		int s_len = s.length();
		int idx;

		while (s != "") {
			idx = s.find(" ");
			if (idx != -1 && idx != 0) {
				cnt++;
			}
			else {
				if (s.substr(0, idx) != "") {
					cnt++;
				}

				if (idx == -1) break;
			}

			s = s.substr(idx + 1);
		}

		return cnt;
	}
};

int main() {
	Solution sol;

	cout << sol.countSegments("Hello, my name is John") << '\n'; // 5

	return 0;
}