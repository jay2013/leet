/* ******************************************************************
 * title: Unique Binary Search Trees II
 * url: https://leetcode.com/problems/unique-binary-search-trees-ii/
 * date: Mon Oct 31 22:31:59 CST 2016
 * description: 构造可以存储1...n到所有二分搜索树(binary search trees).
 * general idea: 利用二分搜索树特有的递归性质去递归构造，具体构造方法看
 * 代码会比较清楚。
 * tags: bin-tree
 *******************************************************************/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<TreeNode * > generateTrees(int l, int r) {
        vector<TreeNode *> ret;
        if(l > r) return ret;
        for(int i = l; i <= r; ++i) {
            vector<TreeNode *> lRet = generateTrees(l, i - 1);
            vector<TreeNode *> rRet = generateTrees(i + 1, r);
            if(lRet.size() == 0 && rRet.size() == 0) {
                TreeNode * root = new TreeNode(i);
                ret.push_back(root);
            } else if(lRet.size() == 0) {
                for(size_t j = 0; j < rRet.size(); ++j) {
                    TreeNode * root = new TreeNode(i);
                    root->right = rRet[j];
                    ret.push_back(root);
                }
            } else if(rRet.size() == 0) {
                for(size_t j = 0; j < lRet.size(); ++j) {
                    TreeNode * root = new TreeNode(i);
                    root->left = lRet[j];
                    ret.push_back(root);
                } 
            } else {
                for(size_t j = 0; j < lRet.size(); ++j) {
                    for(size_t k = 0; k < rRet.size(); ++k) {
                        TreeNode * root = new TreeNode(i);
                        root->left = lRet[j];
                        root->right = rRet[k];
                        ret.push_back(root);
                    }
                } 
            }
        }
        return ret;
    }
public:
    vector<TreeNode * > generateTrees(int n) {
        return generateTrees(1, n); 
    } 
};

void visit(TreeNode * root) {
    if(root == NULL) return;
    queue<TreeNode * > qu;
    qu.push(root);
    while(!qu.empty()) {
        TreeNode * curr = qu.front();
        cout << "node: " << curr->val ;
        qu.pop();
        if(curr->left != NULL) {
            qu.push(curr->left);
            cout << "\t left: " << curr->left->val ;
        } 
        if(curr->right != NULL) {
            qu.push(curr->right);
            cout << "\t right: " << curr->right->val ; 
        } 
        cout << endl;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    Solution s;
    int n = 3;
    cin >> n;
    vector<TreeNode *> v = s.generateTrees(n);
    for(size_t i = 0; i < v.size(); ++i) {
        visit(v[i]);
        cout << "==============================++++++++++++++++++\n";
    }
    return 0;
}
