#include <iostream>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
	int ans = 0;
	set<string> s;

	int cnt[26];
	char type_list[27];
	int list_len = 0;

	string candi;
	int c_len;

	void dfs(string tiles, int cur, int n) {
		if (cur == n) {
			s.insert(candi);
			return;
		}

		for (int i = 0; i < list_len; i++) {
			if (cnt[type_list[i] - 'A'] > 0) {
				cnt[type_list[i] - 'A']--;
				candi += type_list[i];

				dfs(tiles, cur + 1, n);

				cnt[type_list[i] - 'A']++;
				c_len = candi.length();
				candi[c_len - 1] = '\0';
			}
		}
	}

	int numTilePossibilities(string tiles) {
		int len = tiles.length();
		int total = 0;
		ans = 0;

		fill_n(cnt, 26, 0);
		fill_n(type_list, 27, 0);
		for (int i = 0; i < len; i++) {
			cnt[tiles[i] - 'A']++;
			if (cnt[tiles[i] - 'A'] == 1) type_list[list_len++] = tiles[i];
		}

		ans += list_len;
		for (int i = 2; i <= len; i++) {
			dfs(tiles, 0, i);
		}
		ans += s.size();

		return ans;
	}
};

int main() {
	Solution sol;

	cout << sol.numTilePossibilities("AAB") << endl; // 8

	return 0;
}