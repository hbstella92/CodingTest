#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool canReach(vector<int>& arr, int start) {
		if (start < 0 || start >= arr.size() || arr[start] < 0) return false;
		arr[start] *= -1;
		return (!arr[start]) || canReach(arr, start + arr[start]) || canReach(arr, start - arr[start]);
	}
};

int main() {
	Solution sol;	
	//vector<int> input = { 4,2,3,0,3,1,2 };
	//vector<int> input = { 1,1,1,1,1,1,1,1,1,0 };
	//vector<int> input = { 0,0 };
	vector<int> input = { 1,0,2,0 };

	//if (sol.canReach(input, 5)) { // true
	//if (sol.canReach(input, 0)) { // true
	if (sol.canReach(input, 0)) { // true
		cout << "true\n";
	}
	else {
		cout << "false\n";
	}

	return 0;
}