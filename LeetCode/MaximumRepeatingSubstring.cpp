#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int maxRepeating(string sequence, string word) {
		int maxval = 0, cnt = 0;
		int seq_len = sequence.length();
		int word_len = word.length();
		int prev = 0;

		for (int i = 0; i < seq_len; i++) {
			string sub_str = sequence.substr(i, word_len);

			if (sub_str == word) {
				cnt++;
				i += (word_len - 1);
			}
			else {
				cnt = 0;
				i = (prev++);
			}

			maxval = (maxval < cnt) ? cnt : maxval;
		}

		return maxval;
	}
};

int main() {
	Solution sol;

	cout << sol.maxRepeating("ababc", "ab") << '\n'; // 2
	cout << sol.maxRepeating("ababc", "ba") << '\n'; // 1
	cout << sol.maxRepeating("ababc", "ac") << '\n'; // 0

	return 0;
}