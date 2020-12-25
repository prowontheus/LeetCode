/*2. 两数相加（中等）：完成
    给出两个非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照逆序的方式存储的，并且它们的每个节点只能存储
    一位数字。
    如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
    您可以假设除了数字0之外，这两个数都不会以0开头。

示例：
    输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
    输出：7 -> 0 -> 8
    原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry   = 0;
        int cur_num = 0;
        ListNode *root = new ListNode(cur_num);
        ListNode *node = root;
        while(l1 != nullptr || l2 != nullptr || carry != 0)
        {
            cur_num = ((l1?l1->val:0) + (l2?l2->val:0) + carry) % 10;
            node->val = cur_num;
            carry   = ((l1?l1->val:0) + (l2?l2->val:0) + carry) / 10;
            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
            if(l1 != nullptr || l2 != nullptr || carry != 0)
            {
                node->next = new ListNode(0);
                node = node->next;
            }
        }
        node->next = nullptr;
        return root;
    }
};