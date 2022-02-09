#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minNumberOfFrogs(string croakOfFrogs) {
		int len = croakOfFrogs.length();
		int croak[5];
		
		fill_n(croak, 5, 0);

		for (char ch : croakOfFrogs) {
			if (ch == 'c') {
				croak[0]++;

				if (croak[4] != 0) croak[4]--;
			}
			else if (ch == 'r') {
				if (croak[0] <= 0) return -1;

				croak[0]--, croak[1]++;
			}
			else if (ch == 'o') {
				if (croak[1] <= 0) return -1;

				croak[1]--, croak[2]++;
			}
			else if (ch == 'a') {
				if (croak[2] <= 0) return -1;

				croak[2]--, croak[3]++;
			}
			else if (ch == 'k') {
				if (croak[3] <= 0) return -1;

				croak[3]--, croak[4]++;
			}
		}

		if (croak[0] || croak[1] || croak[2] || croak[3]) return -1;

		return croak[4];
	}
};

int main() {
	Solution sol;

	cout << sol.minNumberOfFrogs("croakcroak") << endl; // 1
	cout << sol.minNumberOfFrogs("crcoakroak") << endl; // 2
	cout << sol.minNumberOfFrogs("croakcrook") << endl; // -1

	return 0;
}