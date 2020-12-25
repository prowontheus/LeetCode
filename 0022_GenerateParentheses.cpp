/*22. 括号生成（中等）：
    数字n代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且有效的括号组合。
示例：
    输入：n = 3
    输出：[
           "((()))",
           "(()())",
           "(())()",
           "()(())",
           "()()()"
         ]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/generate-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>
#include <vector>
#include <string>
#include "0000def.h"

using std::vector;
using std::string;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        return ret;
    }
};

int main()
{
    Solution sol;
    clock_t ti = clock();
    int n = 20;
    auto ret = sol.generateParenthesis(n);
    printVec(ret);
    std::cout << "耗时：" << clock() - ti << "微秒" << std::endl;
    return 0;
}
