// 104. Maximum Depth of Binary Tree
// Easy
// Topics
// premium lock icon
// Companies
// Given the root of a binary tree, return its maximum depth.

// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

int maxDepth(struct TreeNode* root) {
    // Base Case: An empty tree has a depth of 0
    if (root == NULL) {
        return 0;
    }

    // Recursive call for left and right children
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    // Return the larger of the two depths + 1 (for the current node)
    if (leftDepth > rightDepth) {
        return leftDepth + 1;
    } else {
        return rightDepth + 1;
    }
}
