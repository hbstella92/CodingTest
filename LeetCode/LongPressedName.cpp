#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isLongPressedName(string name, string typed) {
		int nlen = name.length(), tlen = typed.length();
		int word_cnt = 1, cnt;
		int curidx = 0;
		int j;

		if ((nlen == 1) && (tlen == 1)) {
			if (name == typed) return true;
			else return false;
		}

		for (int i = 0; i < nlen - 1; i++) {
			if (name[i] == name[i + 1]) {
				word_cnt++;
			}
			else {
				cnt = 0;
				for (j = curidx; j < tlen; j++) {
					if (name[i] == typed[j]) {
						cnt++;
						continue;
					}
					else {
						if (!cnt) return false;
						if (word_cnt > cnt) return false;

						word_cnt = 1;
						curidx = j;
						break;
					}
				}
			}
		}

		for (j = curidx; j < tlen; j++) {
			if (name[nlen - 1] != typed[j]) {
				return false;
			}
		}

		return true;
	}
};

int main() {
	Solution sol;

	if (sol.isLongPressedName("alex", "aaleex")) {
		cout << "true\n";
	}
	else {
		cout << "false\n";
	}

	return 0;
}