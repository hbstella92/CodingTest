#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	int numDifferentIntegers(string word) {
		map<string, int> m;
		int word_len = word.length();

		int start = -1;
		string tmp = "";
		for (int i = 0; i < word_len; i++) {
			if (word[i] >= '1' && word[i] <= '9') {
				tmp += word[i];

				if (start == -1) start = i;
			}
			else if (word[i] == '0') {
				if (start == -1) {
					start = i;
				}
				else if (start == (i - 1) && word[i - 1] == '0') {
					start++;
				}
				else {
					tmp += word[i];
				}
			}
			else {
				if (tmp != "") m.insert({ tmp, 1 });
				if (tmp == "" && start != -1) m.insert({ "0", 1 });

				tmp = "";
				start = -1;
			}
		}
		if (tmp != "") m.insert({ tmp, 1 });
		if (tmp == "" && start != -1) m.insert({ "0", 1 });

		return m.size();
	}
};

int main() {
	Solution sol;

	cout << sol.numDifferentIntegers("a123bc34d8ef34") << '\n'; // 3

	return 0;
}