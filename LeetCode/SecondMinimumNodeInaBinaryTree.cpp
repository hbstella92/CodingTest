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
	int flag1 = 0, flag2 = 0;
	int minval = 0x7fffffff;
	int second_minval = 0x7fffffff;

	void preorder(TreeNode *root) {
		if (root == nullptr) return;

		if (minval >= root->val) {
			minval = root->val;
			if (!flag1) flag1 = 1;
		}
		else if (second_minval >= root->val) {
			second_minval = root->val;
			if(!flag2) flag2 = 1;
		}

		preorder(root->left);
		preorder(root->right);
	}

	int findSecondMinimumValue(TreeNode* root) {
		if (root == nullptr) return -1;
		
		preorder(root);
		if (flag2 == 0 && second_minval == 0x7fffffff) return -1;
		return second_minval;
	}
};

int main() {
	Solution sol;	
	TreeNode *root;
	TreeNode node[25];
	//int arr[25] = { 2,2,5,5,7 };
	//int arr[25] = { 1,1,3,1,1,3,4,3,1,1,1,3,8,4,8,3,3,1,6,2,1 };
	//int arr[3] = { 2,2,2147483647 };
	int arr[3] = { 2,2,2 };

	for (int i = 0; i < 3; i++) {
		node[i].val = arr[i];
	}

	root = &node[0];

	root->left = &node[1];
	root->right = &node[2];

	/*root->left->left = &node[3];
	root->left->right = &node[4];
	root->right->left = &node[5];
	root->right->right = &node[6];

	root->left->left->left = &node[7];
	root->left->left->right = &node[8];
	root->left->right->left = &node[9];
	root->left->right->right = &node[10];
	root->right->left->left = &node[11];
	root->right->left->right = &node[12];
	root->right->right->left = &node[13];
	root->right->right->right = &node[14];

	root->left->left->left->left = &node[15];
	root->left->left->left->right = &node[16];
	root->left->left->right->left = &node[17];
	root->left->left->right->right = &node[18];
	root->left->right->left->left = &node[19];
	root->left->right->left->right = &node[20];*/

	cout << sol.findSecondMinimumValue(root) << endl; // 5

	return 0;
}