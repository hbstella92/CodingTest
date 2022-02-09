#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		stack<int> dfs; dfs.push(0);
		unordered_set<int> seen = { 0 };
		while (!dfs.empty()) {
			int i = dfs.top(); dfs.pop();
			for (int j : rooms[i])
				if (seen.count(j) == 0) {
					dfs.push(j);
					seen.insert(j);
					if (rooms.size() == seen.size()) return true;
				}
		}
		return rooms.size() == seen.size();
	}
};

int main() {
	Solution sol;
	vector<vector<int>> input;

	input.push_back({ 1 });
	input.push_back({ 2 });
	input.push_back({ 3 });
	input.push_back({ });

	if (sol.canVisitAllRooms(input)) { // true
		cout << "true\n";
	}
	else {
		cout << "false\n";
	}

	return 0;
}