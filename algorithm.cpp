#include "algorithm.h"

// 插入排序
void Algorithm::InsertSort(std::vector<int> &arr)
{
    int n = arr.size() - 1;
    for (size_t i = 1; i < n; ++i)
    {
        auto key = arr[i];
        int j = i - 1;
        // 找到比key小的数的位置  因为他是有序的那么 他的下一位就是key的位置
        // 移动
        while (j >= 0 && key > arr[j])
        {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}

void Algorithm::BubbleSort(std::vector<int> &arr)
{
    int n = arr.size() - 1;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void Algorithm::QuickSort(std::vector<int> &arr)
{
    if (arr.size() < 3)
    {
        return;
    }

    return QuickSortImpl(arr, 0, arr.size() - 1);
}

// 挖坑法
void Algorithm::QuickSortImpl(std::vector<int> &arr, int left, int right)
{
    if (right - left < 2)
    {
        return;
    }

    int k = arr[left];             // 取出首元素作为基准
    int start = left, end = right; // 记录区间用于递归
    int iMove = 1;                 // 当前移动的是左指针还是右指针 0表示左边 1表示右边
    while (left < right)
    {

        // 从右往左找到第一个比k大的 移到left
        switch (iMove)
        {
        case 1:
            if (k > arr[right])
            {
                --right;
                continue;
            }
            arr[left++] = arr[right];
            iMove = 0;
            break;

        // 从右往左找到第一个比k小的 移到right
        default:
            if (k < arr[left])
            {
                ++left;
                continue;
            }
            arr[right--] = arr[left];
            iMove = 1;
            break;
        }
    }

    // 重合的位置就是中心轴的位置
    arr[left] = k;

    QuickSortImpl(arr, start, left - 1);
    QuickSortImpl(arr, left + 1, end);
}

//  链表逆序
//  记录前一个节点
//  将节点强行改变指向
ListNode *Algorithm::trainningPlan(ListNode *head)
{
    ListNode *pre = nullptr;
    ListNode *current = head;

    while (current != nullptr)
    {
        ListNode *next = current->next; // 记录下一个节点 用于遍历
        current->next = pre;            // 将前节点改为当前节点的next
        pre = current;                  // 当前节点变为原来next的前节点
        current = next;                 // 迭代器自增
    }
    head = pre; // 推出循环时current 为空，pre为头节点

    return head;
}

// 复杂链表的拷贝
// @coderleex: 是否有其他写法这个太绕了
ComplexNode *Algorithm::copyRandomList(ComplexNode *head)
{
    if (!head)
        return head;
    std::unordered_map<ComplexNode *, int> map_src; // 源地址映射Index
    std::unordered_map<int, int> map_dest;          // 源头地址index映射random的index
    std::unordered_map<int, ComplexNode *> map2;    // index映射新的node地址

    map_src[NULL] = -1;
    map2[-1] = NULL;
    ComplexNode *newHeadd, *ret = head;

    // 记录原指针跟位置
    int i = 0;
    while (head)
    {
        map_src[head] = i++;
        head = head->next;
    }

    head = ret;

    i = 0;
    while (head)
    {
        auto node = new ComplexNode(head->val);

        // 如果是头节点 直接拷贝
        if (ret == head)
        {
            ret = node;
            newHeadd = node;
        }
        else
        {
            // 如果不是头节点，遍历拷贝next
            newHeadd->next = node;
            newHeadd = node;
        }

        // 找出这个节点再第几个位置
        // 记录每个节点对应的random下标
        int index = map_src[head];
        if (!head->random)
        {
            map_dest[index] = -1;
        }
        else
            map_dest[index] = map_src[head->random]; // 找到新标对应的下标

        map2[i++] = node;
        head = head->next;
    }
    newHeadd = ret;

    i = 0;
    while (newHeadd)
    {
        // 找到当前index对应random下标
        int r = map_dest[i++];
        // 根据下标找到新的地址
        newHeadd->random = map2[r];
        newHeadd = newHeadd->next;
    }

    return ret;
}

int Algorithm::repalce(std::string &src, const std::string &oldKey, const std::string &newKey)
{
    for (auto &c : src)
    {
        if (c == *oldKey.c_str())
        {
            c = *oldKey.c_str();
        }
    }

    return 0;
}

std::string Algorithm::pathEncryption(std::string path)
{
    Algorithm::repalce(path, ".", "\t");
    return path;
}

std::string Algorithm::dynamicPassword(const std::string &passwd, int target)
{
    if (target > passwd.length())
        target = passwd.length();

    std::string left = passwd.substr(target);
    std::string right = passwd.substr(0, target);

    return left + right;
}

int Algorithm::findRepeatDocument(std::vector<int> &documents)
{
    std::unordered_map<int, int> map;
    int ret;
    for (auto i : documents)
    {
        if (map.find(i) == map.end())
        {
            map[i] = 0;
        }
        else
        {
            map[i] = ++map[i];
        }
        if (map[i] > 0)
        {
            ret = i;
            break;
        }
    }

    return ret;
}

int Algorithm::countTarget(std::vector<int> &scores, int begin, int end, int target)
{
    if (end < begin)
        return 0;
    if (end == begin)
        return scores[begin] == target;

    int i = 0;

    int middle = begin + (end - begin) / 2;
    if (scores[middle] > target)
    {
        i += countTarget(scores, begin, middle - 1, target);
    }
    else if (scores[middle] == target)
    {
        ++i;
        i += countTarget(scores, begin, middle - 1, target);
        i += countTarget(scores, middle + 1, end, target);
    }
    else
        i += countTarget(scores, middle + 1, end, target);

    return i;
}

int Algorithm::countTarget(std::vector<int> &scores, int target)
{
    return countTarget(scores, 0, scores.size() - 1, target);
}

int Algorithm::takeAttendance(std::vector<int> &records)
{
    // int n = records.size() + 1;
    // // 等差数列求和 然后减去数组的和即为差值
    // int total = (n * (records[0] + records[n - 1])) / 2;
    // for (auto &i : records)
    // {
    //     total -= i;
    // }
    // return total;

    // 二分法  如果等于往左边 否则往右边
    int i = 0, j = records.size() - 1;
    while (i <= j)
    {
        int m = (i + j) / 2;
        if (records[m] == m)
            i = m + 1;
        else
            j = m - 1;
    }
    return i;
}

bool Algorithm::findTargetIn2DPlants(vector<vector<int>> &plants, int target)
{
    if (plants.empty() || plants[0].empty())
    {
        return false; // 空矩阵，不存在目标值
    }

    return findTargetIn2DPlants(plants, target, 0, plants[0].size() - 1);
}

// 将矩阵旋转45度 可以得到一张图 类似平衡二叉树遍历
bool Algorithm::findTargetIn2DPlants(vector<vector<int>> &plants, int target, int i, int j)
{
    if (i > plants[0].size() || j < 0)
    {
        return false;
    }

    // 当前元素与目标值比较
    if (plants[i][j] == target)
    {
        return true;
    }
    else if (plants[i][j] > target)
    {
        // 目标值在当前元素的左边列，递归搜索左边的子矩阵和上方的子矩阵
        return findTargetIn2DPlants(plants, target, i, j - 1);
    }
    return findTargetIn2DPlants(plants, target, i + 1, j);
}
