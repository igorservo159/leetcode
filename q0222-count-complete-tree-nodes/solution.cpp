#include <cstddef>
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
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;

        int nodes_count = 0;

        if (root->left != NULL) nodes_count += countNodes(root->left);
        if (root->right != NULL) nodes_count += countNodes(root->right);

        return nodes_count + 1;
    }
};
