#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char x) : val(x), left(NULL), right(NULL) {}
};

// 递归构建二叉树，返回根节点指针
TreeNode* buildTree(string preorder, string inorder, int preStart, int inStart, int inEnd) {
    // 递归结束条件，如果当前子树为空，返回空指针
    if (preStart > preorder.size() - 1 || inStart > inEnd) {
        return nullptr;
    }

    auto root = new TreeNode(preorder[preStart]);

// 在中序遍历中查找当前根节点的位置，以便分割左右子树
    int inIndex = 0;
    for (int i = inStart; i <= inEnd; ++i) {
        if (inorder[i] == root->val) {
            inIndex = i;
            break;
        }
    }
// 递归构建左右子树，更新当前节点的左右孩子指针
    root->left = buildTree(preorder, inorder, preStart + 1, inStart, inIndex - 1);
    root->right = buildTree(preorder, inorder, preStart + inIndex - inStart + 1, inIndex + 1, inEnd);

    return root;
}

void postorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val;
}

int main() {
    string preorder, inorder;
    while (cin >> preorder >> inorder) {
        TreeNode* root = buildTree(preorder, inorder, 0, 0, inorder.size() - 1);
        postorderTraversal(root);
        cout << endl;
    }
    return 0;
}
