#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
	int countPalindromicSubsequence(string s) {
		map<string, int> m;
		int s_len = s.length();
		int i = 0, j = s_len - 1;
		string str = "";
		int bInserted[26];
		int flag[26];
		int cnt = 0;

		fill_n(bInserted, 26, 0);
		
		while (1)	{
			if (!bInserted[s[i]-'a'] && s[i] == s[j]) {
				bInserted[s[i] - 'a'] = 1;
				fill_n(flag, 26, 0); cnt = 0;

				for (int a = i + 1; a < j; a++) {
					if ((!flag[s[a] - 'a']) && cnt < 26) {
						flag[s[a] - 'a'] = 1;
						cnt++;

						str = s[i];
						str += s[a];
						str += s[i];
						m.insert({ str, 1 });
					}
				}
			}

			j--;
			if (bInserted[s[i] - 'a'] || i + 1 == j) {
				i++; j = s_len - 1;
				if (i == s_len - 2) break;
			}
		}

		return m.size();
	}
};

int main() {
	Solution sol;

	cout << sol.countPalindromicSubsequence("aabca") << '\n'; // 3
	cout << sol.countPalindromicSubsequence("adc") << '\n'; // 0
	cout << sol.countPalindromicSubsequence("bbcbaba") << '\n'; // 4

	return 0;
}