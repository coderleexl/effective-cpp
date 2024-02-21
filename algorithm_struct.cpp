#include "algorithm_struct.h"

TreeNode *TreeNode::CreateTree(const std::vector<std::optional<int>> &values)
{
    if (values.empty())
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(values[0].value());
    std::queue<TreeNode *> q;
    q.push(root);

    size_t i = 1;
    while (!q.empty() && i < values.size())
    {
        TreeNode *node = q.front();
        q.pop();

        if (values[i].has_value())
        {
            node->left = new TreeNode(values[i].value());
            q.push(node->left);
        }
        i++;

        if (i < values.size() && values[i].has_value())
        {
            node->right = new TreeNode(values[i].value());
            q.push(node->right);
        }
        i++;
    }

    return root;
}
