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