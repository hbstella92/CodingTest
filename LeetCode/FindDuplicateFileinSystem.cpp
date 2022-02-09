#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;

class Solution {
public:
	vector<vector<string>> findDuplicate(vector<string>& paths) {
		vector<vector<string>> ans;
		int sz = paths.size();
		unordered_map<string, vector<string>> m;

		string dir_path = "", file_name = "", content_name = "";
		int idx = 0;
		int n, start, end;
		for (int i = 0; i < sz; i++) {
			idx = paths[i].find(' ');
			dir_path = paths[i].substr(0, idx);

			n = 0;
			while (1) {
				start = paths[i].find('(', n);
				if (start == -1) break;
				file_name = paths[i].substr(idx + 1, start - idx - 1);

				end = paths[i].find(')', n);
				content_name = paths[i].substr(start + 1, end - start - 1);

				m[content_name].push_back(dir_path + '/' + file_name);
				idx = n = end + 1;
			}
		}

		for (auto iter = m.begin(); iter != m.end(); iter++) {
			if ((iter->second).size() > 1) ans.push_back(iter->second);
		}

		return ans;
	}
};

int main() {
	Solution sol;
	vector<string> input;

	/* [["root/a/2.txt", "root/c/d/4.txt", "root/4.txt"], ["root/a/1.txt", "root/c/3.txt"]]
	input.push_back("root/a 1.txt(abcd) 2.txt(efgh)");
	input.push_back("root/c 3.txt(abcd)");
	input.push_back("root/c/d 4.txt(efgh)");
	input.push_back("root 4.txt(efgh)");
	*/

	input.push_back("root/a 1.txt(abcd) 2.txt(efsfgh)");
	input.push_back("root/c 3.txt(abdfcd)");
	input.push_back("root/c/d 4.txt(efggdfh)");

	vector<vector<string>> output = sol.findDuplicate(input);
	for (auto i : output) {
		for (auto j : i) {
			cout << j << endl; // []
		} cout << endl;
	} cout << endl;

	return 0;
}