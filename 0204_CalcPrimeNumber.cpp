/*204. 计数质数（简单）：完成
    统计所有小于非负整数 n 的质数的数量。
示例 1：
    输入：n = 10
    输出：4
    解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
示例 2：
    输入：n = 0
    输出：0
示例 3：
    输入：n = 1
    输出：0
提示：
    0 <= n <= 5 * 106

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-primes/
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>

class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)
            return 0;
        int arr[n];
        arr[0] = 0;
        arr[1] = 0;
        arr[2] = 1;
        for(int i = 3;i < n;i = i+2)
            arr[i] = 1;
        for(int i = 4;i < n;i = i+2)
            arr[i] = 0;
        for(int i = 2;i < n;i++)
        {
            if(i % 2 != 0)
            {
                for (int k = i * 2; k < n; k += i)
                {
                    if (arr[k] != 0)
                        arr[k] = 0;
                }
            }
        }
        int count = 1;
        for(int i = 3;i < n;i++)
        {
            if(arr[i] == 1)
                count++;
        }
        return count;
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
        std::cout << "在" << num << "之前的质数有" <<sol.countPrimes(num) << "个" << std::endl;
        std::cout << "耗时：" << (clock() - ti) << "微秒" << std::endl;
    }
    return 0;
}