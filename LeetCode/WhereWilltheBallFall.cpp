#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> findBall(vector<vector<int>>& grid) {
		vector<int> ans;
		int row = grid.size();
		int col = grid[0].size();

		int turn = 0;
		int by = -1, bx = turn;
		int y = 0, x = 0;
		bool stuck = false;

		while (turn < col) {
			if (grid[y][x] == 1) {
				if (by < y) {
					by++, x++;
					if ((x < col) && (grid[y][x] == -1)) stuck = true;
				}
				else if (bx < x) {
					bx++, y++;
				}
				else if (x < bx) {
					stuck = true;
				}
			}
			else if (grid[y][x] == -1) {
				if (by < y) {
					by++, x--;
					if ((x >= 0) && (grid[y][x] == 1)) stuck = true;
				}
				else if (bx < x) {
					stuck = true;
				}
				else if (x < bx) {
					bx--, y++;
				}
			}

			if (y < 0 || y >= row || x < 0 || x >= col) {
				stuck = (by == row - 1) ? false : true;
			}
			if (x < 0 || x >= col) stuck = true;
			if (stuck) {
				ans.push_back(-1);

				turn++;
				by = -1, bx = turn;
				y = 0, x = turn;
				stuck = false;
			}
			else if (by == row - 1) {
				ans.push_back(x);

				turn++;
				by = -1, bx = turn;
				y = 0, x = turn;
			}
		}

		return ans;
	}
};

int main() {
	Solution sol;
	vector<vector<int>> input;

	input.push_back({ 1,1,1,-1,-1 });
	input.push_back({ 1,1,1,-1,-1 });
	input.push_back({ -1,-1,-1,1,1 });
	input.push_back({ 1,1,1,1,-1 });
	input.push_back({ -1,-1,-1,-1,-1 });

	vector<int> output = sol.findBall(input);

	for (auto i : output) {
		cout << i << ' '; // [1, -1, -1, -1, -1]
	} cout << endl;

	return 0;
}