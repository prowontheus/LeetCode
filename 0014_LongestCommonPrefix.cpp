/*14. 最长公共前缀（简单）：完成
    编写一个函数来查找字符串数组中的最长公共前缀。
    如果不存在公共前缀，返回空字符串""。
示例1:
    输入:["flower","flow","flight"]
    输出:"fl"
示例2:
    输入:["dog","racecar","car"]
    输出:""
解释:
    输入不存在公共前缀。
说明:
    所有输入只包含小写字母a-z。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return string("");
        if(strs.size() == 1)
            return strs[0];
        int min_len = INT_MAX;
        for(auto r:strs)
        {
            if(min_len > r.length())
                min_len = r.length();
        }
        if(min_len <= 0)
            return string("");
        string ret;
        char str[min_len+1];
        int i = 0;
        bool isBreak = false;
        char tmp = strs[0][i];
        for(;i < min_len;i++)
        {
            isBreak = false;
            tmp = strs[0][i];
            for (auto iter = strs.cbegin() + 1; iter != strs.cend(); ++iter)
            {
                if (tmp != iter->at(i))
                {
                    isBreak = true;
                    break;
                }
            }
            if(!isBreak)
                str[i] = tmp;
            else break;
        }
        str[i] = '\0';
        return string(str);
    }
};

int main()
{
    Solution sol;
    string s1("flower");
    string s2("flow");
    string s3("flight");
    string s4("dog");
    string s5("racecar");
    string s6("car");
    string s7("ab");
    string s8("a");
    vector<string> vec1;
    vector<string> vec2;
    vector<string> vec3;
    vec1.push_back(s1);
    vec1.push_back(s2);
    vec1.push_back(s3);
    vec2.push_back(s4);
    vec2.push_back(s5);
    vec2.push_back(s6);
    vec3.push_back(s7);
    vec3.push_back(s8);
    clock_t ti = clock();
    std::cout << "最长公共前缀：" << sol.longestCommonPrefix(vec1) << std::endl;//"fl"
    std::cout << "最长公共前缀：" << sol.longestCommonPrefix(vec2) << std::endl;//""
    std::cout << "最长公共前缀：" << sol.longestCommonPrefix(vec3) << std::endl;//"a"
    std::cout << "耗时：" << clock() - ti << "微秒" << std::endl;
    return 0;
}