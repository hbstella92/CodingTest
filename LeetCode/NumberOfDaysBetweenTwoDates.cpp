#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
	int daysBetweenDates(string date1, string date2) {
		int year_1 = 0, month_1 = 0, day_1 = 0;
		int year_2 = 0, month_2 = 0, day_2 = 0;
		int len_1 = date1.length(), len_2 = date2.length();
		const int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		// make dates
		string tmp;
		int loc = 0;
		for (int i = 0; i < len_1; i++) {
			if (date1[i] == '-') {
				if (loc == 0) {
					year_1 = atoi(tmp.c_str());
					tmp = "";
					loc++;
				}
				else if (loc == 1) {
					month_1 = atoi(tmp.c_str());
					tmp = "";
					loc++;
				}
			}
			else {
				tmp += date1[i];
			}
		}
		day_1 = atoi(tmp.c_str());
		tmp = "";
		loc = 0;

		for (int i = 0; i < len_2; i++) {
			if (date2[i] == '-') {
				if (loc == 0) {
					year_2 = atoi(tmp.c_str());
					tmp = "";
					loc++;
				}
				else if (loc == 1) {
					month_2 = atoi(tmp.c_str());
					tmp = "";
					loc++;
				}
			}
			else {
				tmp += date2[i];
			}
		}
		day_2 = atoi(tmp.c_str());

		// calculate number of days
		int one = 0, two = 0;

		one = 365 * (year_1 - 1971);
		for (int i = 1; i < month_1; i++) {
			one += month[i];
		}
		one += day_1;
		
		for (int i = 1971; i <= year_1; i++) {
			if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0)) {
				if (i != year_1) {
					one++;
				}
				else if ((i == year_1) && ((month_1 > 2) || (month_1 == 2 && day_1 == 29))) {
					one++;
				}
			}
		}
		
		two = 365 * (year_2 - 1971);
		for (int i = 1; i < month_2; i++) {
			two += month[i];
		}
		two += day_2;

		for (int i = 1971; i <= year_2; i++) {
			if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0)) {
				if (i != year_2) {
					two++;
				}
				else if ((i == year_2) && ((month_2 > 2) || (month_2 == 2 && day_2 == 29))) {
					two++;
				}
			}
		}

		int ans = abs(two - one);

		return ans;
	}
};

int main() {
	Solution sol;

	cout << sol.daysBetweenDates("2019-06-29", "2019-06-30") << '\n'; // 1
	cout << sol.daysBetweenDates("2020-01-15", "2019-12-31") << '\n'; // 15
	cout << sol.daysBetweenDates("2019-12-31", "2020-01-01") << '\n'; // 1
	cout << sol.daysBetweenDates("2074-09-12", "1983-01-08") << '\n'; // 33485

	return 0;
}