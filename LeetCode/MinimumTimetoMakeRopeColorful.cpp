#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minCost(string colors, vector<int>& neededTime) {
		int ans = 0;
		int len = colors.length();

		int cmp = 0;
		for (int i = 1; i < len; i++) {
			if (colors[cmp] == colors[i]) {
				ans += min(neededTime[cmp], neededTime[i]);
				cmp = (neededTime[cmp] < neededTime[i]) ? i : cmp;
			}
			else cmp = i;
		}

		return ans;
	}
};

int main() {
	Solution sol;
	vector<int> input = { 1,2,3,4,5 };

	cout << sol.minCost("abaac", input) << endl; // 3

	return 0;
}