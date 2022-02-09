#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;

class Solution {
public:
	vector<vector<int>> findFarmland(vector<vector<int>>& land) {
		vector<vector<int>> ans;

		vector<pair<int, int>> candi;

		int sz = land.size();
		int ssz = land[0].size();
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < ssz; j++) {
				if (land[i][j] == 1) {
					candi.push_back(make_pair(i, j));
				}
			}
		}

		const int dy[4] = { 0, 0, 1, -1 };
		const int dx[4] = { 1, -1, 0, 0 };

		queue<pair<int, int>> q;
		int candi_sz = candi.size();
		for (int i = 0; i < candi_sz; i++) {
			int maxy = -1, maxx = -1, miny = 301, minx = 301;

			q.push(candi[i]);
			while (!q.empty()) {
				int cy = q.front().first;
				int cx = q.front().second;
				q.pop();

				if (land[cy][cx] == 0) continue;

				land[cy][cx] = 0;
				if (cy <= miny && cx <= minx) {
					miny = cy, minx = cx;
				}
				if (cy >= maxy && cx >= maxx) {
					maxy = cy, maxx = cx;
				}

				for (int d = 0; d < 4; d++) {
					int ny = cy + dy[d];
					int nx = cx + dx[d];

					if (ny < 0 || ny >= sz || nx < 0 || nx >= ssz) continue;
					if (land[ny][nx] == 0) continue;
					q.push(make_pair(ny, nx));
				}
			}

			if (maxy == -1 || miny == 301) continue;
			ans.push_back({ miny, minx, maxy, maxx });
		}

		return ans;
	}
};

int main() {
	Solution sol;
	vector<vector<int>> input;

	//input.push_back({ 1,0,0 });
	//input.push_back({ 0,1,1 });
	//input.push_back({ 0,1,1 });
	input.push_back({ 1,1,1,1,1,1,1,1,1,1,1,1 });

	vector<vector<int>> output = sol.findFarmland(input);

	int sz = output.size();
	for (int i = 0; i < sz; i++) {
		int ssz = output[i].size();
		for (int j = 0; j < ssz; j++) {
			//cout << output[i][j] << ' '; // [[0, 0, 0, 0], [1, 1, 2, 2]]
			cout << output[i][j] << ' '; // [[0, 0, 0, 11]]
		} cout << endl;
	} cout << endl;

	return 0;
}