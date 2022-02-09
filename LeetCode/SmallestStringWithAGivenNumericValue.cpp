#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	string getSmallestString(int n, int k) {
		string ans(n, 'a');
		k -= n;

		while (k > 0) {
			int r = min(k, 25);
			ans[n - 1] += r;
			k -= r;
			n--;
		}

		return ans;
	}
};

int main() {
	Solution sol;

	//cout << sol.getSmallestString(3, 27) << endl; // aay
	cout << sol.getSmallestString(5, 73) << endl; // aaszz

	return 0;
}