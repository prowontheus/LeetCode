/*206. 反转链表（简单）：完成
    反转一个单链表。
示例:
    输入: 1->2->3->4->5->NULL
    输出: 5->4->3->2->1->NULL
进阶:
    你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {//迭代
        if(head == nullptr || head->next == nullptr)
            return head;
        auto tmp1 = head;
        auto tmp2 = tmp1->next;
        while(tmp2 != nullptr)
        {
            auto tmp = tmp2->next;
            tmp2->next = tmp1;
            tmp1 = tmp2;
            tmp2 = tmp;
        }
        head->next = nullptr;
        return tmp1;
    }
    ListNode* reverseList2(ListNode* head) {//递归
        if(head == nullptr || head->next == nullptr)
            return head;
        auto tmp = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return tmp;
    }
    void print(ListNode* head)
    {
        auto tmp = head;
        while(tmp != nullptr)
        {
            std::cout << tmp->val << ",";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    ListNode* node6 = new ListNode(6);
    ListNode* node5 = new ListNode(5);
    node5->next = node6;
    ListNode* node4 = new ListNode(4);
    node4->next = node5;
    ListNode* node3 = new ListNode(3);
    node3->next = node4;
    ListNode* node2 = new ListNode(2);
    node2->next = node3;
    ListNode* node1 = new ListNode(1);
    node1->next = node2;
    Solution sol;
    sol.print(node1);
    auto tmp1 = sol.reverseList(node1);
    sol.print(tmp1);
    auto tmp2 = sol.reverseList2(tmp1);
    sol.print(tmp2);
    return 0;
}