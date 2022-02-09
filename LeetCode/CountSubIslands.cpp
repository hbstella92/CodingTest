#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int ans = 0;
	int m, n;
	int visit[500][500] = { 0, };
	bool is_subisland;

	const int dy[4] = { 1,-1,0,0 };
	const int dx[4] = { 0,0,1,-1 };

	void dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int cury, int curx) {
		if (!grid1[cury][curx]) {
			is_subisland = false;
			return;
		}

		if (!grid2[cury][curx]) return;

		visit[cury][curx] = 1;
		for (int i = 0; i < 4; i++) {
			int nexty = cury + dy[i];
			int nextx = curx + dx[i];

			if (nexty < 0 || nexty >= m || nextx < 0 || nextx >= n || visit[nexty][nextx]) continue;
			if (grid2[nexty][nextx]) dfs(grid1, grid2, nexty, nextx);
		}
	}

	int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
		m = grid1.size(); n = grid1[0].size();

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid2[i][j] && grid1[i][j] && (!visit[i][j])) {
					is_subisland = true;
					dfs(grid1, grid2, i, j);
					if (is_subisland) ans++;
				}
			}
		}

		return ans;
	}
};

int main() {
	Solution sol;
	vector<vector<int>> input1, input2;
	
	input1.push_back({ 1,1,1,0,0 });
	input1.push_back({ 0,1,1,1,1 });
	input1.push_back({ 0,0,0,0,0 });
	input1.push_back({ 1,0,0,0,0 });
	input1.push_back({ 1,1,0,1,1 });

	input2.push_back({ 1,1,1,0,0 });
	input2.push_back({ 0,0,1,1,1 });
	input2.push_back({ 0,1,0,0,0 });
	input2.push_back({ 1,0,1,1,0 });
	input2.push_back({ 0,1,0,1,0 });

	cout << sol.countSubIslands(input1, input2) << endl; // 3

	return 0;
}