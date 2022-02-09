#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	int m, n;
	int visit[100][100] = { 0, };
	const int dy[4] = { 1,-1,0,0 };
	const int dx[4] = { 0,0,1,-1 };

	bool bfs(vector<vector<int>> &grid, int cy, int cx, int check_value) {
		vector<pair<int, int>> candidate;
		queue<pair<int, int>> q;
		q.push({ cy, cx });
		candidate.push_back({ cy, cx });

		while (!q.empty()) {
			int cury = q.front().first;
			int curx = q.front().second;
			q.pop();

			if (visit[cury][curx] < 0) continue;
			visit[cury][curx] = check_value;

			for (int i = 0; i < 4; i++) {
				int newy = cury + dy[i];
				int newx = curx + dx[i];

				if (newy >= m || newy < 0 || newx >= n || newx < 0 || visit[newy][newx] < 0) continue;
				if (grid[newy][newx] == 0) {
					q.push({ newy, newx });
					candidate.push_back({ newy, newx });
				}
			}
		}

		int sz = candidate.size();
		for (int i = 0; i < sz; i++) {
			if ((candidate[i].first == 0) || (candidate[i].first == m - 1) || (candidate[i].second == 0) || (candidate[i].second == n - 1)) return false;
		}

		return true;
	}

	int closedIsland(vector<vector<int>>& grid) {
		int ans = 0;
		m = grid.size(), n = grid[0].size();
		int v = -1;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 0 && visit[i][j] == 0) {
					if (bfs(grid, i, j, v)) ans++;
					v--;
				}
			}
		}

		return ans;
	}
};

int main() {
	Solution sol;
	vector<vector<int>> input;

	input.push_back({ 1,1,1,1,1,1,1,0 });
	input.push_back({ 1,0,0,0,0,1,1,0 });
	input.push_back({ 1,0,1,0,1,1,1,0 });
	input.push_back({ 1,0,0,0,0,1,0,1 });
	input.push_back({ 1,1,1,1,1,1,1,0 });

	cout << sol.closedIsland(input) << endl; // 2

	return 0;
}