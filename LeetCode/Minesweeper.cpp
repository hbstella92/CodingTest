#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		int m = board.size(); int n = board[0].size();

		int visit[50][50] = { 0, };
		const int dy[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
		const int dx[8] = { 1, 0, -1, 1, -1, 1, 0, -1 };

		queue<pair<int, int>> q;
		q.push({ click[0], click[1] });

		while (!q.empty()) {
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop();

			if (visit[cy][cx] == 1) continue;
			visit[cy][cx] = 1;

			if (board[cy][cx] == 'M') {
				board[cy][cx] = 'X';
				break;
			}

			int count = 0;
			for (int i = 0; i < 8; i++) {
				int ny = cy + dy[i];
				int nx = cx + dx[i];

				if (ny >= m || ny < 0 || nx >= n || nx < 0 || visit[ny][nx] == 1) continue;
				if (board[ny][nx] == 'M') count++;
			}

			if (!count) {
				board[cy][cx] = 'B';
				for (int i = 0; i < 8; i++) {
					int ny = cy + dy[i];
					int nx = cx + dx[i];

					if (ny >= m || ny < 0 || nx >= n || nx < 0 || visit[ny][nx] == 1) continue;
					q.push({ ny, nx });
				}
			}
			else {
				board[cy][cx] = (char)(count + '0');
			}
		}

		return board;
	}
};

int main() {
	Solution sol;
	vector<vector<char>> input1;
	vector<int> input2 = { 3,0 };

	input1.push_back({ 'E', 'E', 'E', 'E', 'E' });
	input1.push_back({ 'E', 'E', 'M', 'E', 'E' });
	input1.push_back({ 'E', 'E', 'E', 'E', 'E' });
	input1.push_back({ 'E', 'E', 'E', 'E', 'E' });

	vector<vector<char>> output = sol.updateBoard(input1, input2);

	for (auto i : output) {
		for (auto j : i) {
			cout << j << ' ';
		} cout << endl;
	} cout << endl;

	return 0;
}