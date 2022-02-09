#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool is_enclave = true;
	int m, n;
	int visit[500][500] = { 0, };
	const int dy[4] = { 1,-1,0,0 };
	const int dx[4] = { 0,0,1,-1 };

	void dfs(vector<vector<int>> &grid, int cury, int curx, int &cnt) {
		if (!grid[cury][curx]) return;

		visit[cury][curx] = 1;
		cnt++;

		for (int i = 0; i < 4; i++) {
			int newy = cury + dy[i];
			int newx = curx + dx[i];

			if (newy < 0 || newy >= m || newx < 0 || newx >= n) {
				is_enclave = false;
				continue;
			}
			if (!visit[newy][newx]) {
				dfs(grid, newy, newx, cnt);
			}
		}
	}

	int numEnclaves(vector<vector<int>>& grid) {
		int ans = 0;

		m = grid.size(), n = grid[0].size();

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] && (!visit[i][j])) {
					int num = 0;
					is_enclave = true;

					dfs(grid, i, j, num);
					if (is_enclave) ans += num;
				}
			}
		}

		return ans;
	}
};

int main() {
	Solution sol;
	vector<vector<int>> input;

	input.push_back({ 0,0,0,0 });
	input.push_back({ 1,0,1,0 });
	input.push_back({ 0,1,1,0 });
	input.push_back({ 0,0,0,0 });

	cout << sol.numEnclaves(input) << endl; // 3

	return 0;
}