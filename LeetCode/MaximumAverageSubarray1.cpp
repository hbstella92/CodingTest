#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		double ans = INT_MIN;
		int sz = nums.size();
		double sum = 0;
		int start_idx = 0, end_idx = 0;

		for (int i = 0; i < k; i++) {
			sum += nums[i];
		}
		ans = max(ans, sum);
		end_idx = k;

		while (end_idx < sz) {
			sum = (sum - nums[start_idx++] + nums[end_idx++]);
			ans = max(ans, sum);
		}
		ans /= k;

		return ans;
	}
};

int main() {
	Solution sol;
	vector<int> input = { 1,12,-5,-6,50,3 };

	cout << sol.findMaxAverage(input, 4) << endl; // 12.75000

	return 0;
}