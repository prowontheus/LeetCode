/*9. 回文数（简单）
    判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
示例 1:
    输入: 121
    输出: true
示例2:
    输入: -121
    输出: false
    解释: 从左向右读,为-121。从右向左读,为121- 。因此它不是一个回文数。
示例 3:
    输入: 10
    输出: false
    解释: 从右向左读,为01。因此它不是一个回文数。
进阶:
    你能不将整数转为字符串来解决这个问题吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        else if(x < 10)
            return true;
        int tmp = x;
        int y = 0;
        while(tmp != 0)
        {
            if(y > 214744741)
                return false;
            y = 10 * y + tmp % 10;
            tmp /= 10;
        }
        return y == x;
    }
};

int main()
{
    Solution sol;
    int num1 = 324234;
    int num2 = 2147483647;
    clock_t ti = clock();
    std::cout << num1 << "是否是回文数：" << std::boolalpha << sol.isPalindrome(num1) << std::endl;
    std::cout << num2 << "是否是回文数：" << std::boolalpha << sol.isPalindrome(num2) << std::endl;
    std::cout << "耗时：" << clock() - ti << "微秒" << std::endl;
    return 0;
}