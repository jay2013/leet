/* ******************************************************************
 * title: Maximum Depth of Binary Tree
 * url: https://leetcode.com/problems/maximum-depth-of-binary-tree/
 * date: Thu Oct 27 20:51:35 CST 2016
 * description: 求一颗二叉树的最大深度。
 * general idea: 利用二叉树的递归性质，MaxLen(root) = 1 + max(MaxLen(left), MaxLen(right));
 * tags: bin-tree
 *******************************************************************/
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode * root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    } 
};

int main() {
    freopen("input.txt", "r", stdin);
    return 0;
}
