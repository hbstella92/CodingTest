#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	bool flipEquiv(TreeNode* root1, TreeNode* root2) {
		if ((root1 == nullptr) || (root2 == nullptr)) {
			return (!root1) && (!root2);
		}

		if (root1->val != root2->val) return false;

		return ((flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
			(flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left)));
	}
};

int main() {
	Solution sol;
	TreeNode *root1, *root2;
	TreeNode node[20];
	int arr[20] = { 1,2,3,4,5,6,7,8,1,3,2,6,4,5,8,7 };

	for (int i = 0; i < 16; i++) {
		node[i].val = arr[i];
	}

	root1 = &node[0];
	root1->left = &node[1];
	root1->right = &node[2];
	root1->left->left = &node[3];
	root1->left->right = &node[4];
	root1->right->left = &node[5];
	root1->left->right->left = &node[6];
	root1->left->right->right = &node[7];

	root2 = &node[8];
	root2->left = &node[9];
	root2->right = &node[10];
	root2->left->right = &node[11];
	root2->right->left = &node[12];
	root2->right->right = &node[13];
	root2->right->right->left = &node[14];
	root2->right->right->right = &node[15];

	if (sol.flipEquiv(root1, root2)) { // true
		cout << "true\n";
	}
	else {
		cout << "false\n";
	}

	return 0;
}