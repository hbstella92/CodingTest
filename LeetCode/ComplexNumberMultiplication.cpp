#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string complexNumberMultiply(string num1, string num2) {
		string ans = "";
		int n1_len = num1.length(), n2_len = num2.length();

		int idx = num1.find('+');
		int r1 = stoi(num1.substr(0, idx));
		int i1 = stoi(num1.substr(idx + 1, n1_len - 1));
		idx = num2.find('+');
		int r2 = stoi(num2.substr(0, idx));
		int i2 = stoi(num2.substr(idx + 1, n2_len - 1));

		int sr = 0, si = 0;
		sr += (r1 * r2);
		si += ((r1 * i2) + (r2 * i1));
		sr += (i1 * i2 * (-1));

		ans += to_string(sr) + '+' + to_string(si) + 'i';
		return ans;
	}
};

int main() {
	Solution sol;

	cout << sol.complexNumberMultiply("1+1i", "1+1i") << endl; // 0+2i

	return 0;
}