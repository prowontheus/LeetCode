/*19. 删除链表的倒数第N个节点（中等）
    给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
示例：
    给定一个链表:1->2->3->4->5,和n=2.
    当删除了倒数第二个节点后，链表变为1->2->3->5.
说明：
    给定的n保证是有效的。
进阶：
    你能尝试使用一趟扫描实现吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr || n <= 0)
            return head;
        int i = 0;
        auto tmp1 = head,tmp2 = head,tmp3 = head->next;
        while(tmp1 != nullptr && i <= n)
        {
            tmp1 = tmp1->next;
            ++i;
        }
        while(tmp1 != nullptr)
        {
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
            tmp3 = tmp3->next;
        }
        if(i == n)
            return tmp3;
        else if(i < n)
            return head;
        if(tmp3 == nullptr)
            return nullptr;
        tmp2->next = tmp3->next;
        delete tmp3;
        return head;
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
    ListNode * node1 = new ListNode(7);
    ListNode * node2 = new ListNode(6,node1);
    ListNode * node3 = new ListNode(5,node2);
    ListNode * node4 = new ListNode(4,node3);
    ListNode * node5 = new ListNode(3,node4);
    ListNode * node6 = new ListNode(2,node5);
    ListNode * node7 = new ListNode(1,node6);
    Solution sol;
    clock_t ti = clock();
    sol.print(node7);
    auto ret1 = sol.removeNthFromEnd(node7,6);
    sol.print(ret1);
    std::cout << "耗时：" << clock() - ti << "微秒" << std::endl;
    return 0;
}