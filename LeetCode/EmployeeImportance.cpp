#include <iostream>
#include <vector>
using namespace std;

class Employee {
public:
	int id;
	int importance;
	vector<int> subordinates;
};

class Solution {
public:
	void dfs(vector<Employee*> employees, int id, int &ans) {
		for (auto i : employees) {
			if (i->id == id) {
				ans += i->importance;

				for (auto j : i->subordinates) {
					dfs(employees, j, ans);
				}
			}
		}
	}

	int getImportance(vector<Employee*> employees, int id) {
		int ans = 0;
		dfs(employees, id, ans);
		return ans;
	}
};

int main() {
	Solution sol;
	vector<Employee*> input;
	Employee* node[10];

	node[0]->id = 1;
	node[0]->importance = 5;
	node[0]->subordinates = { 2,3 };

	node[1]->id = 2;
	node[1]->importance = 3;
	node[1]->subordinates = {};

	node[2]->id = 3;
	node[2]->importance = 3;
	node[2]->subordinates = {};

	for (int i = 0; i < 3; i++) {
		input.push_back(node[i]);
	}

	cout << sol.getImportance(input, 1) << endl; // 11

	return 0;
}