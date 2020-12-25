/*203. 移除链表元素（简单）：完成
    删除链表中等于给定值 val 的所有节点。
示例：
    输入: 1->2->6->3->4->5->6, val = 6
    输出: 1->2->3->4->5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-linked-list-elements/
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/


#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr)
            return nullptr;
        if(head->next == nullptr)
        {
            if(head->val == val)
            {
                delete head;
                return nullptr;
            }
        }
        while(head != nullptr && head->val == val)
        {
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
        }
        if(head == nullptr)
            return nullptr;
        for (ListNode *tmp1 = head, *tmp2 = tmp1->next; tmp2 != nullptr;)
        {
            if (tmp2->val == val)
            {
                tmp1->next = tmp2->next;
                delete tmp2;
                tmp2 = tmp1->next;
            } else
            {
                tmp1 = tmp2;
                tmp2 = tmp2->next;
            }
        }
        return head;
    }
};
int main()
{
    return 0;
}
