#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int countBattleships(vector<vector<char>>& board) {
		int ans = 0;
		int m = board.size();
		int n = board[0].size();

		int visit[200][200];
		const int dy[4] = { 0,0,1,-1 };
		const int dx[4] = { 1,-1,0,0 };
		fill(&visit[0][0], &visit[199][200], 0);

		vector<pair<int, int>> v;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 'X') {
					v.push_back(make_pair(i, j));
				}
			}
		}

		int v_sz = v.size();
		for (int i = 0; i < v_sz; i++) {
			int cury = v[i].first;
			int curx = v[i].second;

			if (visit[cury][curx] == 1) continue;
			visit[cury][curx] = 1;
			ans++;

			int k = 0;
			for (; k < 4; k++) {
				int newy = cury + dy[k];
				int newx = curx + dx[k];

				if ((newy >= m) || (newy < 0) || (newx >= n) || (newx < 0)) continue;

				if ((visit[newy][newx] == 0) && (board[newy][newx] == 'X')) {
					visit[newy][newx] = 1;
					cury = newy, curx = newx, k = -1;
				}
			}
		}

		return ans;
	}
};

int main() {
	Solution sol;
	vector<vector<char>> input;

	input.push_back({ 'X', '.', '.', 'X' });
	input.push_back({ '.', '.', '.', 'X' });
	input.push_back({ '.', '.', '.', 'X' });

	cout << sol.countBattleships(input) << endl; // 2

	return 0;
}