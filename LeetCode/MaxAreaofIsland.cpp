#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int ans = 0; int candi = 0;

	int m, n;
	const int dy[4] = { 0, 0, 1, -1 };
	const int dx[4] = { 1, -1, 0, 0 };

	void dfs(vector<vector<int>> &grid, int cur_y, int cur_x) {
		if (cur_y >= m || cur_y < 0 || cur_x >= n || cur_x < 0) return;

		if (grid[cur_y][cur_x] == 1) {
			candi++;
			grid[cur_y][cur_x] = 0;

			for (int k = 0; k < 4; k++) {
				int next_y = cur_y + dy[k];
				int next_x = cur_x + dx[k];

				dfs(grid, next_y, next_x);
			}
		}
	}

	int maxAreaOfIsland(vector<vector<int>>& grid) {
		m = grid.size();
		n = grid[0].size();

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1) {
					dfs(grid, i, j);

					ans = max(ans, candi);
					candi = 0;
				}
			}
		}

		return ans;
	}
};

int main() {
	Solution sol;
	vector<vector<int>> input;

	input.push_back({ 0,0,1,0,0,0,0,1,0,0,0,0,0 });
	input.push_back({ 0,0,0,0,0,0,0,1,1,1,0,0,0 });
	input.push_back({ 0,1,1,0,1,0,0,0,0,0,0,0,0 });
	input.push_back({ 0,1,0,0,1,1,0,0,1,0,1,0,0 });
	input.push_back({ 0,1,0,0,1,1,0,0,1,1,1,0,0 });
	input.push_back({ 0,0,0,0,0,0,0,0,0,0,1,0,0 });
	input.push_back({ 0,0,0,0,0,0,0,1,1,1,0,0,0 });
	input.push_back({ 0,0,0,0,0,0,0,1,1,0,0,0,0 });

	cout << sol.maxAreaOfIsland(input) << endl; // 6

	return 0;
}