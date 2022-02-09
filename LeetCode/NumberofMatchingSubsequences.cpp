#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int numMatchingSubseq(string s, vector<string>& words) {
		int ans = 0;
		int s_len = s.length();
		int v_sz = words.size();
		map<string, int> m;

		for (int i = 0; i < v_sz; i++) {
			m.insert({ words[i], 0 });
			m[words[i]]++;
		}

		int m_sz = m.size();

		for (auto iter = m.begin(); iter != m.end(); iter++) {
			int words_len = iter->first.length();
			bool subseq = true;
			int j = 0, k = 0;

			while (j != words_len) {
				if (iter->first[j] == s[k]) {
					j++, k++;
				}
				else k++;

				if (k == s_len) {
					if (j != words_len) subseq = false;
					break;
				}
			}

			if (subseq) {
				if (ans) {
					ans += (1 * iter->second);
				}
				else {
					ans += iter->second;
				}
			}
		}

		return ans;
	}
};

int main() {
	Solution sol;
	vector<string> input;

	input.push_back("a");
	input.push_back("bb");
	input.push_back("acd");
	input.push_back("ace");

	cout << sol.numMatchingSubseq("abcde", input) << endl; // 3

	return 0;
}