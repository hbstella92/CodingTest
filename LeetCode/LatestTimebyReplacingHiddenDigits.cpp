#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string maximumTime(string time) {
		if (time[0] == '?') {
			time[0] = '2';

			if (time[1] == '?') {
				time[1] = '3';

				if (time[3] == '?') {
					time[3] = '5';

					if (time[4] == '?') {
						time[4] = '9';
					}
				}
				else if (time[4] == '?') {
					time[4] = '9';
				}
			}
			else {
				if (time[1] >= '4') {
					time[0] = '1';
				}

				if (time[3] == '?') {
					time[3] = '5';

					if (time[4] == '?') {
						time[4] = '9';
					}
				}
				else if (time[4] == '?') {
					time[4] = '9';
				}
			}
		}
		else if (time[0] == '2') {
			if (time[1] == '?') {
				time[1] = '3';

				if (time[3] == '?') {
					time[3] = '5';

					if (time[4] == '?') {
						time[4] = '9';
					}
				}
				else {
					if (time[4] == '?') {
						time[4] = '9';
					}
				}
			}
			else {
				if (time[3] == '?') {
					time[3] = '5';

					if (time[4] == '?') {
						time[4] = '9';
					}
				}
				else {
					if (time[4] == '?') {
						time[4] = '9';
					}
				}
			}
		}
		else {
			if (time[1] == '?') {
				time[1] = '9';

				if (time[3] == '?') {
					time[3] = '5';

					if (time[4] == '?') {
						time[4] = '9';
					}
				}
				else {
					if (time[4] == '?') {
						time[4] = '9';
					}
				}
			}
			else {
				if (time[3] == '?') {
					time[3] = '5';

					if (time[4] == '?') {
						time[4] = '9';
					}
				}
				else {
					if (time[4] == '?') {
						time[4] = '9';
					}
				}
			}
		}

		return time;
	}
};

int main() {
	Solution sol;

	//cout << sol.maximumTime("2?:?0") << '\n'; // 23:50
	//cout << sol.maximumTime("0?:3?") << '\n'; // 09:39
	cout << sol.maximumTime("1?:22") << '\n'; // 19:22

	return 0;
}