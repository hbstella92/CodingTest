#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<string> simplifiedFractions(int n) {
		vector<string> ans;
		unordered_map<int, vector<int>> yaksu;

		for (int i = 4; i <= n; i++) {
			vector<int> candi;
			for (int j = 2; j < i; j++) {
				if (!(i % j)) candi.push_back(j);
			}
			yaksu[i] = candi;
		}

		for (int i = 2; i <= n; i++) {
			ans.push_back(to_string(1) + '/' + to_string(i));
		}

		for (int i = 2; i <= n; i++) {
			for (int j = 2; j < i; j++) {
				bool included = false;

				for (auto k : yaksu[i]) {
					if (!(j % k)) {
						included = true;
					}
				}
				if (!included)ans.push_back(to_string(j) + '/' + to_string(i));
			}
		}

		return ans;
	}
};

int main() {
	Solution sol;

	vector<string> output = sol.simplifiedFractions(6);
	for (auto i : output) {
		cout << i << ' ';
	} cout << endl;

	return 0;
}