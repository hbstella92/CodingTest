#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		int sz = nums.size();
		map<int, int> cnt;

		if (k >= sz) k = sz - 1;

		for (int i = 0; i <= k; i++) {
			cnt[nums[i]]++;
			if (cnt[nums[i]] > 1) return true;
		}

		for (int i = k + 1; i < sz; i++) {
			cnt[nums[i - k - 1]]--;

			cnt[nums[i]]++;
			if (cnt[nums[i]] > 1) return true;
		}

		return false;
	}
};

int main() {
	Solution sol;
	//vector<int> input = { 1,2,3,1 };
	//vector<int> input = { 1 };
	vector<int> input = { 1,2,3,4,5,6,7,8,9,10 };

	//if (sol.containsNearbyDuplicate(input, 4)) { // true
	//if (sol.containsNearbyDuplicate(input, 1)) { // false
	if (sol.containsNearbyDuplicate(input, 15)) { // false
		cout << "true\n";
	}
	else cout << "false\n";

	return 0;
}