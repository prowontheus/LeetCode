/*202. 快乐数（简单）
    编写一个算法来判断一个数 n 是不是快乐数。
    「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为1，也可能是
    无限循环但始终变不到1。如果 可以变为1，那么这个数就是快乐数。
    如果 n 是快乐数就返回true;不是，则返回false。
示例：
    输入：19
    输出：true
解释：
    12 + 92 = 82
    82 + 22 = 68
    62 + 82 = 100
    12 + 02 + 02 = 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/happy-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>
#include <set>

class Solution {
public:
    bool isHappy(int n) {
        if(n <= 0)
            return false;
        if(n == 1)
            return true;
        int num = n;
        std::set<int> s;
        s.insert(num);
        int mCount = 0;
        while(num != 1)
        {
            int count = 0;
            int coef = 0;
            while(num != 0)
            {
                coef = num % 10;
                num = num /10;
                count += coef * coef;
            }
            if(s.find(count) != s.cend())
                return false;
            else
            {
                s.insert(count);
                num = count;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    int num;
    while(std::cin >> num)
    {
        if(num == -1)
            break;
        clock_t ti = clock();
        std::cout << num << "是否是快乐数:" << std::boolalpha <<sol.isHappy(num) << std::endl;
        std::cout << "耗时：" << (clock() - ti) << "微秒" << std::endl;
    }
    return 0;
}