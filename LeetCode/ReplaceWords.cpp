#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
	string replaceWords(vector<string>& dictionary, string sentence) {
		string ans = "";
		int sz = dictionary.size();
		int len = sentence.length();
		unordered_map<string, int> um;
		int len_flag[101] = { 0, };
		int len_type[1001] = { 0, }, num = 0;

		sort(dictionary.begin(), dictionary.end());
		int str_len = 0;
		for (auto i : dictionary) {
			str_len = i.length();
			um[i] = str_len;
			if (!len_flag[str_len]) {
				len_flag[str_len] = 1;
				len_type[num++] = str_len;
			}
		}

		int i = 0; string tmp = "";
		bool find_substr = false;
		while (1) {
			i = sentence.find(' ');
			if (i == -1) {
				find_substr = false;
				for (int j = 0; j < num; j++) {
					int substr_len = len_type[j];
					string ttmp = sentence.substr(0, substr_len);
					if (um[ttmp] != 0) {
						ans += ttmp;
						find_substr = true;
						break;
					}
				}
				if (!find_substr) ans += sentence;

				break;
			}
			
			tmp = sentence.substr(0, i);
			
			find_substr = false;
			for (int j = 0; j < num; j++) {
				int substr_len = len_type[j];
				string ttmp = tmp.substr(0, substr_len);
				if (um[ttmp] != 0) {
					ans += (ttmp + ' ');
					find_substr = true;
					break;
				}
			}
			if (!find_substr) ans += (tmp + ' ');

			sentence = sentence.substr(i + 1);
		}

		return ans;
	}
};

int main() {
	Solution sol;
	vector<string> input;

	/*
	input.push_back("cat");
	input.push_back("bat");
	input.push_back("rat");
	*/

	input.push_back("a");
	input.push_back("aa");
	input.push_back("aaa");
	input.push_back("aaaa");

	//cout << sol.replaceWords(input, "the cattle was rattled by the battery") << endl; // "the cat was rat by the bat"
	cout << sol.replaceWords(input, "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa") << endl; // "a a a a a a a a bbb baba a"

	return 0;
}