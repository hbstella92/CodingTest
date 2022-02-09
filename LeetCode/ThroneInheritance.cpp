#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class ThroneInheritance {
	unordered_map<string, vector<string>> family;
	unordered_map<string, bool> dead;
	string root;

public:
	ThroneInheritance(string kingName) {
		root = kingName;
	}

	void birth(string parentName, string childName) {
		family[parentName].push_back(childName);
	}

	void death(string name) {
		dead[name] = true;
	}

	void dfs(vector<string> &ans, string root) {
		if (!dead[root]) ans.push_back(root);

		for (auto child : family[root]) {
			dfs(ans, child);
		}
	}

	vector<string> getInheritanceOrder() {
		vector<string> ans;
		dfs(ans, root);
		return ans;
	}
};

int main() {
	ThroneInheritance *obj = new ThroneInheritance("king");

	obj->birth("king", "andy");
	obj->birth("king", "bob");
	obj->birth("king", "catherine");
	obj->birth("andy", "matthew");
	obj->birth("bob", "alex");
	obj->birth("bob", "asha");

	vector<string> ans = obj->getInheritanceOrder();
	for (auto i : ans) {
		cout << i << ' '; // ["king", "andy", "matthew", "bob", "alex", "asha", "catherine"]
	} cout << endl;

	obj->death("bob");

	ans = obj->getInheritanceOrder();
	for (auto i : ans) {
		cout << i << ' '; // ["king", "andy", "matthew", "alex", "asha", "catherine"]
	} cout << endl;

	return 0;
}