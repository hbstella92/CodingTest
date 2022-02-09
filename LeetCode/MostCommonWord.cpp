#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
using namespace std;

class Solution {
public:
	string mostCommonWord(string paragraph, vector<string>& banned) {
		class Solution {
		public:
			string mostCommonWord(string paragraph, vector<string>& banned) {
				vector<string> p;
				map<string, int> m;
				int banned_sz = banned.size();
				int paragraph_len = paragraph.length();

				string tmp = "";
				for (int i = 0; i < paragraph_len; i++) {
					if (paragraph[i] == '!' || paragraph[i] == '?'
						|| paragraph[i] == '\'' || paragraph[i] == ','
						|| paragraph[i] == ';' || paragraph[i] == '.'
						|| paragraph[i] == '\"' || paragraph[i] == ' ') {
						if (tmp == "") {
							continue;
						}

						int tmp_len = tmp.length();
						for (int j = 0; j < tmp_len; j++) {
							if (tmp[j] >= 65 && tmp[j] <= 90) {
								tmp[j] += 32;
							}
						}
						p.push_back(tmp);

						if (!m[tmp]) {
							m.insert({ tmp, 1 });
							m[tmp] = 1;
						}
						else {
							m[tmp]++;
						}

						tmp = "";
					}
					else {
						tmp += paragraph[i];
					}
				}
				if (tmp != "") {
					int tmp_len = tmp.length();
					for (int j = 0; j < tmp_len; j++) {
						if (tmp[j] >= 65 && tmp[j] <= 90) {
							tmp[j] += 32;
						}
					}
					p.push_back(tmp);

					if (!m[tmp]) {
						m.insert({ tmp, 1 });
						m[tmp] = 1;
					}
					else {
						m[tmp]++;
					}
				}

				int p_sz = p.size();
				int m_sz = m.size();
				string ans = "";

				int max_val = 0;
				for (auto iter = m.begin(); iter != m.end(); iter++) {
					int okay = 1;

					if (iter->second > max_val) {
						for (int i = 0; i < banned_sz; i++) {
							if (banned[i] == iter->first) {
								okay = 0;
								break;
							}
						}

						if (okay) {
							max_val = iter->second;
							ans = iter->first;
						}
					}
				}

				return ans;
			}
		};
	}
};

int main() {
	Solution sol;
	vector<string> input;
	input.push_back("hit");

	cout << sol.mostCommonWord("Bob hit a ball, the hit BALL flew far after it was hit.", input) << endl;

	return 0;
}