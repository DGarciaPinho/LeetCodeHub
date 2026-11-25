/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) return {};
        return caminhos(root, "");
    }

private:
    vector<string> caminhos(TreeNode* no, string prefixo) {
        if (no == nullptr) return {};

        string atual = prefixo + to_string(no->val);

        if (no->left == nullptr && no->right == nullptr)
            return {atual};

        vector<string> esq = caminhos(no->left, atual + "->");
        vector<string> dir = caminhos(no->right, atual + "->");
        esq.insert(esq.end(), dir.begin(), dir.end());
        return esq;
    }
};