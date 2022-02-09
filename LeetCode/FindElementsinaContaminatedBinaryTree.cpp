#include <iostream>
#include <unordered_set>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindElements {
public:
	unordered_set<int> us;

	FindElements() {}

	FindElements(TreeNode* root) {
		dfs(root, 0);
	}

	bool find(int target) {
		return (us.count(target) > 0);
	}

	void dfs(TreeNode *root, int num) {
		if (root == nullptr) return;

		root->val = num;
		us.insert(root->val);
		dfs(root->left, num * 2 + 1);
		dfs(root->right, num * 2 + 2);
	}
};

int main() {
	TreeNode *root;
	TreeNode node[10];

	node[0].val = node[1].val = -1;
	root = &node[0];
	root->right = &node[1];

	FindElements *obj = new FindElements(root);
	bool param1 = obj->find(1);
	bool param2 = obj->find(2);

	return 0;
}