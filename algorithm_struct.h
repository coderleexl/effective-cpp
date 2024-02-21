#include "variant.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 复杂链表
// 跳表由此衍生
class ComplexNode
{
public:
    int val;
    ComplexNode *next;
    ComplexNode *random;

    explicit ComplexNode(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// 二叉树
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    static TreeNode *CreateTree(const std::vector<std::optional<int>> &values);
};
