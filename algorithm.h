#include "variant.h"
#include "algorithm_struct.h"

namespace Algorithm
{
    using std::string;
    using std::vector;
    // 插入
    void InsertSort(std::vector<int> &arr);
    // 冒泡
    void BubbleSort(std::vector<int> &arr);
    // 快排
    void QuickSort(std::vector<int> &arr);
    void QuickSortImpl(std::vector<int> &arr, int left, int right);
    // 链表逆序
    ListNode *trainningPlan(ListNode *head);

    // 复杂链表的拷贝
    ComplexNode *copyRandomList(ComplexNode *head);
    // 字符串替换
    int repalce(std::string &src, const std::string &oldKey, const std::string &newKey);
    // 将.替换成\t字符串
    std::string pathEncryption(std::string path);
    // 动态密码计算  将前面N位移到末尾
    std::string dynamicPassword(const std::string &passwd, int target);
    // 设备中存有 n 个文件，文件 id 记于数组 documents。若文件 id 相同，则定义为该文件存在副本。请返回任一存在副本的文件 id。
    int findRepeatDocument(std::vector<int> &documents);
    // 找到字符或者数字出现的次数 该数组是有序的
    int countTarget(std::vector<int> &scores, int begin, int end, int target);
    int countTarget(std::vector<int> &scores, int target);
    // 计算连续的数组中缺少的一个数
    int takeAttendance(std::vector<int> &records);
    // 二维数组里面寻找目标值 target  数组下边不小于上面 右边不小于左边  左右有序 上下有序
    bool findTargetIn2DPlants(vector<vector<int>> &plants, int target);
    bool findTargetIn2DPlants(vector<vector<int>> &plants, int target, int i, int j);
    // 找出字符串中第一个只出现一次的字符串
    char dismantlingAction(string arr);
    // 找出数组中最小的数字的值
    int stockManagement(vector<int> &stock);
    // 广度优先遍历树
    std::vector<int> decorateRecord(TreeNode *root);
    // 广度优先遍历树 把每一层的作为一个数组返回
    vector<vector<int>> decorateRecordV2(TreeNode *root);
    // 广度优先遍历树 把每一层的作为一个数组返回 ,每一层的打印顺序与上一层相反第一层除外
    vector<vector<int>> decorateRecordV3(TreeNode *root);
    // 判断树A是否包含树B
    bool isSubStructure(TreeNode *A, TreeNode *B);
    bool treeCompare(TreeNode *A, TreeNode *B);
};
// 最小栈
class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        m_aStorage.push(x);

        if (m_aMin.empty() || m_aMin.top() > x)
            m_aMin.push(x);
        else
            m_aMin.push(m_aMin.top());
    }

    void pop()
    {
        m_aStorage.pop();
        m_aMin.pop();
    }

    int top()
    {
        return m_aStorage.top();
    }

    int min()
    {
        return m_aMin.top();
    }

private:
    std::stack<int> m_aMin;
    std::stack<int> m_aStorage;
};

// 将链表逆序成vector
class Solution
{
public:
    std::vector<int> reversePrint(ListNode *head)
    {
        std::vector<int> a;
        std::stack<int> b;
        ListNode *newHeader = head;
        while (newHeader)
        {
            b.push(newHeader->val);
            newHeader = newHeader->next;
        }
        while (!b.empty())
        {
            a.push_back(b.top());
            b.pop();
        }
        return a;
    }
};
