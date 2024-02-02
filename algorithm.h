#include "variant.h"
#include "algorithm_struct.h"

namespace Algorithm
{
    // 插入
    void InsertSort(std::vector<int> &arr);
    // 冒泡
    void BubbleSort(std::vector<int> &arr);

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