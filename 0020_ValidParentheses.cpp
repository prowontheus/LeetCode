/*20. 有效的括号（简单）
    给定一个只包括'('，')'，'{'，'}'，'['，']'的字符串，判断字符串是否有效。
    有效字符串需满足：
    左括号必须用相同类型的右括号闭合。
    左括号必须以正确的顺序闭合。
    注意空字符串可被认为是有效字符串。
示例1:
    输入:"()"
    输出:true
示例2:
    输入:"()[]{}"
    输出:true
示例3:
    输入:"(]"
    输出:false
示例4:
    输入:"([)]"
    输出:false
示例5:
    输入:"{[]}"
    输出:true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using std::string;
using std::stack;
using std::unordered_map;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        int len = s.length();
        if(len <= 0)
            return true;
        sta.push(s[0]);
        for(int i = 1;i < len;++i)
        {
            switch (s[i])
            {
                case '(':
                case '[':
                case '{':
                    sta.push(s[i]);
                    break;
                case ')':
                {
                    if (!sta.empty() && sta.top() == '(')
                        sta.pop();
                    else return false;
                }
                    break;
                case ']':
                {
                    if (!sta.empty() && sta.top() == '[')
                        sta.pop();
                    else return false;
                }
                    break;
                case '}':
                {
                    if(!sta.empty() && sta.top() == '{')
                        sta.pop();
                    else return false;
                }
                    break;
                default:
                    return false;
            }
        }
        if(sta.empty())
            return true;
        else return false;
    }
};

int main()
{
    Solution sol;
    string s1("(");
    string s2("()[]{}");
    string s3("(]");
    string s4("([)]");
    string s5("{[]}");
    string s6("(){}}{");
    clock_t ti = clock();
    std::cout << "括号是否有效:" << std::boolalpha << sol.isValid(s1) << std::endl;
    std::cout << "括号是否有效:" << std::boolalpha << sol.isValid(s2) << std::endl;
    std::cout << "括号是否有效:" << std::boolalpha << sol.isValid(s3) << std::endl;
    std::cout << "括号是否有效:" << std::boolalpha << sol.isValid(s4) << std::endl;
    std::cout << "括号是否有效:" << std::boolalpha << sol.isValid(s5) << std::endl;
    std::cout << "括号是否有效:" << std::boolalpha << sol.isValid(s6) << std::endl;
    std::cout << "耗时：" << clock() - ti << "微秒" << std::endl;
    return 0;
}