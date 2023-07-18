#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

// 递归建树
TreeNode* buildTree(string& str, int& index) {
    if (str[index] == '#') {
        index++;
        return nullptr;
    }
    TreeNode* root = new TreeNode(str[index++]);
    root->left = buildTree(str, index);
    root->right = buildTree(str, index);
    return root;
}

// 非递归中序遍历
void inOrderTraversal(TreeNode* root) {
    stack<TreeNode*> stk;
    TreeNode* p = root;
    while (p != nullptr || !stk.empty()) {
        while (p != nullptr) {
            stk.push(p);
            p = p->left;
        }
        p = stk.top();
        stk.pop();
        cout << p->val << ' ';
        p = p->right;
    }
    cout << endl;
}

int main() {
    string str;
    while (getline(cin, str)) {
        if (str.empty()) break;
        int index = 0;
        TreeNode* root = buildTree(str, index);
        inOrderTraversal(root);
    }
    return 0;
}
