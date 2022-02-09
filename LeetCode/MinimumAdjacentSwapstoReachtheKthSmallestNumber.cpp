#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int getMinSwaps(string num, int k) {
		int ans = 0;
		int len = num.length();

		string newstr = num;
		while (k--) {
			next_permutation(newstr.begin(), newstr.end());
		}

		int i = 0, j = 0;
		while (j < len) {
			if (num[i] == newstr[j]) {
				i++, j++;
				continue;
			}
			else {
				while (num[i] != newstr[j]) {
					j++;
				}

				while (i < j) {
					swap(newstr[j - 1], newstr[j]);
					j--;
					ans++;
				}

				j = (++i);
			}
		}

		return ans;
	}
};

int main() {
	Solution sol;

	cout << sol.getMinSwaps("5489355142", 4) << endl; // 2

	return 0;
}