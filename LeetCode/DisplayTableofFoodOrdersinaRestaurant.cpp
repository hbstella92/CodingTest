#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
	vector<vector<string>> ans;
	set<string> foodList;
	map<int, map<string, int>> tableFoodCnt;

	void makeTable() {
		vector<string> tmp;

		tmp.push_back("Table");
		for (auto food : foodList) {
			tmp.push_back(food);
		}
		ans.push_back(tmp);
		tmp.clear();

		int i = 1;
		for (auto iter = tableFoodCnt.begin(); iter != tableFoodCnt.end(); iter++) {
			tmp.push_back(to_string(iter->first));

			for (auto food : foodList) {
				if (tableFoodCnt[iter->first].find(food) != tableFoodCnt[iter->first].end()) {
					tmp.push_back(to_string(tableFoodCnt[iter->first][food]));
				}
				else {
					tmp.push_back("0");
				}
			}

			i++;
			ans.push_back(tmp);
			tmp.clear();
		}
	}

	vector<vector<string>> displayTable(vector<vector<string>>& orders) {
		int sz = orders.size();
		for (int i = 0; i < sz; i++) {
			foodList.insert(orders[i][2]);

			int table_idx = atoi(orders[i][1].c_str());
			tableFoodCnt[table_idx][orders[i][2]]++;
		}

		makeTable();

		return ans;
	}
};

int main() {
	Solution sol;
	vector<vector<string>> input;

	input.push_back({ "David", "3", "Ceviche" });
	input.push_back({ "Corina", "10", "Beef Burrito" });
	input.push_back({ "David", "3", "Fried Chicken" });
	input.push_back({ "Carla", "5", "Water" });
	input.push_back({ "Carla", "5" , "Ceviche" });
	input.push_back({ "Rous", "3", "Ceviche" });

	vector<vector<string>> output = sol.displayTable(input);
	int sz = output.size();
	for (int i = 0; i < sz; i++) {
		int ssz = output[i].size();
		for (int j = 0; j < ssz; j++) {
			cout << output[i][j] << ' ';
		} cout << endl;
	} cout << endl;

	return 0;
}