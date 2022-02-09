#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string convertToTitle(int columnNumber) {
		string alpha = ".ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		string ans = "";
		bool first_zero = false;

		first_zero = (columnNumber % 26) ? false : true;

		int flag = 0;

		while (1) {
			int remain = columnNumber % 26;

			if (!remain) {
				ans += alpha[26];

				if (columnNumber == 26) break;
			}
			else {
				ans += alpha[remain];

				if (columnNumber <= 26) break;
			}

			columnNumber /= 26;
			if ((!flag) && (first_zero)) {
				flag = 1;
				columnNumber--;
			}
		}

		reverse(ans.begin(), ans.end());

		return ans;
	}
};

int main() {
	Solution sol;

	cout << sol.convertToTitle(1) << '\n'; // A
	cout << sol.convertToTitle(28) << '\n'; // AB
	cout << sol.convertToTitle(701) << '\n'; // ZY
	cout << sol.convertToTitle(2147483647) << '\n'; // FXSHRXW
	cout << sol.convertToTitle(52) << '\n'; // AZ
	cout << sol.convertToTitle(702) << '\n'; // ZZ

	return 0;
}