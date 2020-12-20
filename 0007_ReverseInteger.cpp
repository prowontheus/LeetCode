/*7. 整数反转（简单）
    给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
示例1:
    输入: 123
    输出: 321
示例 2:
    输入: -123
    输出: -321
示例 3:
    输入: 120
    输出: 21
注意:
    假设我们的环境只能存储得下32位的有符号整数，则其数值范围为[−2^31,2^31−1]。请根据这个假设，如果反转后整数溢出那么就返回0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>
#include <string>
#include <deque>

using std::string;
using std::deque;

//class Solution {
//public:
//    long wuhu;
//    int reverse(int x) {
//        if(x==0)
//            return 0;
//
//        string trans = std::to_string(abs(x));
//        std::reverse(trans.begin(),trans.end());
//
//        long tmp=1;
//        x>0?wuhu=atol(trans.c_str()):wuhu=0-atol(trans.c_str());
//        if(wuhu>=0-(tmp<<31) && wuhu<=(tmp<<31)-1)
//        {
//            int a = (int)wuhu;
//            return a;
//        }
//        else
//            return 0;
//    }
//};

class Solution {
public:
    int reverse(int x) {
        if(x == 0 || x == -2147483648) return 0;
        deque<int> deq;
        int coef = 1;
        if(x < 0)
        {
            coef = -1;
            x = -x;
        }
        while(x != 0)
        {
            deq.push_back(x % 10);
            x /= 10;
        }
        while(deq.front() == 0)
            deq.pop_front();
        int ret = 0;
        while(!deq.empty())
        {
            if(ret > 214748364)
                return 0;
            else if(ret == 214748364 && deq.front() > 7)
                return 0;
            ret = ret*10 + deq.front();
            deq.pop_front();
        }
        return coef==1?ret:-ret;
    }
};

int main()
{
    Solution sol;
    clock_t ti = clock();
    int a = INT_MAX;
    std::cout << "反转后的结果为：" << sol.reverse(-123) << std::endl;
    std::cout << "反转后的结果为：" << sol.reverse(123) << std::endl;
    std::cout << "反转后的结果为：" << sol.reverse(-3) << std::endl;
    std::cout << "反转后的结果为：" << sol.reverse(3) << std::endl;
    std::cout << "反转后的结果为：" << sol.reverse(-0) << std::endl;
    std::cout << "反转后的结果为：" << sol.reverse(0) << std::endl;
    std::cout << "反转后的结果为：" << sol.reverse(10) << std::endl;
    std::cout << "反转后的结果为：" << sol.reverse(100) << std::endl;
    std::cout << "反转后的结果为：" << sol.reverse(-10) << std::endl;
    std::cout << "反转后的结果为：" << sol.reverse(-100) << std::endl;
    std::cout << "反转后的结果为：" << sol.reverse(2147483647) << std::endl;
    std::cout << "反转后的结果为：" << sol.reverse(2147483648) << std::endl;
    std::cout << "反转后的结果为：" << sol.reverse(-2147483648) << std::endl;
    std::cout << "反转后的结果为：" << sol.reverse(-2147483649) << std::endl;
    std::cout << "反转后的结果为：" << sol.reverse(2147483647) << std::endl;
    std::cout << "反转后的结果为：" << sol.reverse(2147483648) << std::endl;
    std::cout << "反转后的结果为：" << sol.reverse(-2147483648000) << std::endl;
    std::cout << "反转后的结果为：" << sol.reverse(-214748364000) << std::endl;
    std::cout << "反转后的结果为：" << sol.reverse(-2147483649) << std::endl;
    std::cout << "反转后的结果为：" << sol.reverse(-2147483412) << std::endl;
    std::cout << "反转后的结果为：" << sol.reverse(1563847412) << std::endl;
    std::cout << "耗时：" << clock() - ti << "微秒" << std::endl;
    return 0;
}