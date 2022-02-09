#include <iostream>
using namespace std;

class Solution {
public:
	int secondHighest(string s) {
		int first = -1, second = -1; 
		int s_len = s.length();

		for (int i = 0; i < s_len; i++) {
			if (s[i] >= '0' && s[i] <= '9') {
				int num_s = s[i] - '0';

				if (second < num_s) {
					if (first < num_s) {
						second = first;
						first = num_s;
					}
					else if (first == num_s) continue;
					else {
						second = num_s;
					}
				}
			}
		}

		if (first == second) second = -1;

		return second == -1 ? -1 : second;
	}
};

int main() {
	Solution sol;
	
	cout << sol.secondHighest("abc1111") << '\n';

	return 0;
}