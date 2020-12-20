/*21. 合并两个有序链表（简单）
    将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
示例：
    输入：1->2->4, 1->3->4
    输出：1->1->2->3->4->4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;
        auto tmp1 = l1,tmp2 = l2;
        auto ret = tmp1->val<=tmp2->val?tmp1:tmp2;
        while(tmp1 != nullptr && tmp2 != nullptr)
        {
            if(tmp1->val <= tmp2->val)
            {
                while(tmp1->next != nullptr && tmp1->next->val <= tmp2->val)
                    tmp1 = tmp1->next;
                auto tmp = tmp1->next;
                tmp1->next = tmp2;
                tmp1 = tmp;
            }
            else
            {
                while(tmp2->next != nullptr && tmp1->val > tmp2->next->val)
                    tmp2 = tmp2->next;
                auto tmp = tmp2->next;
                tmp2->next = tmp1;
                tmp2 = tmp;
            }
        }
        return ret;
    }
    void print(ListNode *head)
    {
        while(head != nullptr)
        {
            std::cout << head->val << "->";
            head = head->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main()
{
    Solution sol;
    ListNode *node1 = new ListNode(5);
    ListNode *node2 = new ListNode(4);
    ListNode *node3 = new ListNode(2,node2);
    ListNode *node4 = new ListNode(1,node3);
    clock_t ti = clock();
    auto ret1 = sol.mergeTwoLists(node1,node4);
    sol.print(ret1);
    ListNode *node5 = new ListNode(4);
    ListNode *node6 = new ListNode(2,node5);
    ListNode *node7 = new ListNode(1,node6);
    ListNode *node8 = new ListNode(4);
    ListNode *node9 = new ListNode(3,node8);
    ListNode *node10 = new ListNode(1,node9);
    auto ret2 = sol.mergeTwoLists(node7,node10);
    sol.print(ret2);

//    ListNode *node1 = new ListNode(3);
//    ListNode *node2 = new ListNode(2,node1);
//    ListNode *node3 = new ListNode(-1,node2);
//    ListNode *node4 = new ListNode(-3,node3);
//    ListNode *node5 = new ListNode(-3,node4);
//    ListNode *node6 = new ListNode(-7,node5);
//    ListNode *node7 = new ListNode(-9,node6);
//    ListNode *node8 = new ListNode(4);
//    ListNode *node9 = new ListNode(2,node8);
//    ListNode *node10 = new ListNode(-3,node9);
//    ListNode *node11 = new ListNode(-5,node10);
//    ListNode *node12 = new ListNode(-6,node11);
//    ListNode *node13 = new ListNode(-6,node12);
//    ListNode *node14 = new ListNode(-7,node13);
//    ListNode *node15 = new ListNode(-7,node14);
//    clock_t ti = clock();
//    auto ret1 = sol.mergeTwoLists(node7,node15);
//    sol.print(ret1);
    std::cout << "耗时：" << clock() - ti << "微秒" << std::endl;
    return 0;
}