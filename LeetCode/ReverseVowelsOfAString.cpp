#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string reverseVowels(string s) {
		int s_len = s.length();
		vector<int> v;

		for (int i = 0; i < s_len; i++) {
			if (s[i] == 'a' || s[i] == 'e' ||
				s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
				s[i] == 'A' || s[i] == 'E' || 
				s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
				v.push_back(i);
			}
		}

		int v_len = v.size();
		for (int i = 0; i < v_len / 2; i++) {
			char tmp = s[v[i]];
			s[v[i]] = s[v[v_len - i - 1]];
			s[v[v_len - i - 1]] = tmp;
		}

		return s;
	}
};

int main() {
	Solution sol;

	cout << sol.reverseVowels("aA") << '\n';

	return 0;
}