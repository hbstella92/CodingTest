#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
		vector<int> ans;
		int len = s.length();
		int cy = startPos[0], cx = startPos[1];
		int ny, nx;

		unordered_map<char, int> dy, dx;
		dy['R'] = 0, dx['R'] = 1;
		dy['L'] = 0, dx['L'] = -1;
		dy['U'] = -1, dx['U'] = 0;
		dy['D'] = 1, dx['D'] = 0;

		for (int i = 0; i < len; i++) {
			int sum = 0;
			cy = startPos[0], cx = startPos[1];

			for (int j = i; j < len; j++) {
				ny = cy + dy[s[j]];
				nx = cx + dx[s[j]];

				if (ny < 0 || ny >= n || nx < 0 || nx >= n) break;
				sum++;
				cy = ny, cx = nx;
			}

			ans.push_back(sum);
		}

		return ans;
	}
};

int main() {
	Solution sol;
	vector<int> input = { 0,1 };

	vector<int> output = sol.executeInstructions(3, input, "RRDDLU");

	for (auto i : output) {
		cout << i << ' '; // [1, 5, 4, 3, 1, 0]
	} cout << endl;

	return 0;
}