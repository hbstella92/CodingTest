#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool check(string s) {
		int s_len = s.length();
		for (int i = 0; i < s_len - 1; i++) {
			if (s[i] == s[i + 1]) return false;
		}
		return true;
	}

	string getHappyString(int n, int k) {
		string arr[11][1000];
		int arr_len[11] = { 0, };
		arr[1][0] = 'a', arr[1][1] = 'b', arr[1][2] = 'c';

		if ((n == 1) && (k <= 3)) {
			return arr[1][k - 1];
		}

		arr_len[1] = 3;
		for (int i = 2; i <= n; i++) {
			int len = 0;

			int num = 0;
			for (int j = 0; j < arr_len[i - 1]; j++) {
				for (int m = 0; m < 3; m++) {
					arr[i][num] = (arr[i - 1][j] + arr[1][m]);
					if (!check(arr[i][num])) {
						continue;
					}
					num++;
					if ((i == n) && (num == k)) return arr[i][num - 1];
				}
				arr_len[i] = num;
			}
		}

		return "";
	}
};

int main() {
	Solution sol;

	//cout << sol.getHappyString(1, 3) << endl; // c
	//cout << sol.getHappyString(3, 9) << endl; // cab
	cout << sol.getHappyString(2, 1) << endl; // ab

	return 0;
}