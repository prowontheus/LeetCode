/*10. 正则表达式匹配（困难）：未完成
    给你一个字符串s和一个字符规律p，请你来实现一个支持'.'和'*'的正则表达式匹配。
    '.' 匹配任意单个字符
    '*' 匹配零个或多个前面的那一个元素
    所谓匹配，是要涵盖整个字符串s的，而不是部分字符串。
示例 1：
    输入：s = "aa" p = "a"
    输出：false
    解释："a" 无法匹配 "aa" 整个字符串。
示例 2:
    输入：s = "aa" p = "a*"
    输出：true
    解释：因为'*'代表可以匹配零个或多个前面的那一个元素,在这里前面的元素就是'a'。因此，字符串"aa"可被视为'a'重复了一次。
示例3：
    输入：s = "ab" p = ".*"
    输出：true
    解释：".*"表示可匹配零个或多个（'*'）任意字符（'.'）。
示例 4：
    输入：s = "aab" p = "c*a*b"
    输出：true
    解释：因为'*'表示零个或多个，这里'c'为0个,'a'被重复一次。因此可以匹配字符串"aab"。
示例 5：
    输入：s = "mississippi" p = "mis*is*p*."
    输出：false
提示：
    0 <= s.length<= 20
    0 <= p.length<= 30
    s可能为空，且只包含从a-z的小写字母。
    p可能为空，且只包含从a-z的小写字母，以及字符.和*。
    保证每次出现字符*时，前面都匹配到有效的字符

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/regular-expression-matching
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

class Solution {
public:
    //动态规划：https://leetcode-cn.com/problems/regular-expression-matching/solution/zheng-ze-biao-da-shi-pi-pei-by-leetcode-solution/
    bool isMatch(string s, string p) {
        int len1 = s.length(),len2 = p.length();
        if(len1 == 0 && len2 == 0)
            return true;
        bool arr[len1+1][len2+1];
        for(int i = 0;i <= len1;++i)
        {
            for(int j = 0;j <= len2;++j)
                arr[i][j] = false;
        }
        arr[0][0] = true;
        for(int i = 0;i <= len1;++i)
        {
            for(int j = 1;j <= len2;++j)
            {
                if(p[j-1] == '*')
                {
                    if(i > 0 && (p[j-2] == '.' || s[i-1] == p[j-2]))
                    {
                        arr[i][j] = arr[i-1][j] || arr[i][j-2];
                    }
                    else
                        arr[i][j] = arr[i][j-2];
                }
                else
                {
                    if(i > 0 && (p[j-1] == '.' || s[i-1] == p[j-1]))
                        arr[i][j] = arr[i-1][j-1];
                }
            }
        }
        return arr[len1][len2];
    }
//    bool isMatch(string s, string p)
//    {
//        int len1 = s.length(),len2 = p.length();
//        bool arr[len1+1][len2+1];
//        for(int i = 0;i <= len1;++i)
//        {
//            for(int j = 0;j <= len2;++j)
//                arr[i][j] = false;
//        }
//        arr[0][0] = true;
//        for(int i = 0;i <= len1;++i)
//        {
//            for(int j = 1;j <= len2;++j)
//            {
//                if(p[j-1] == '*')
//                {
//                    if(i > 0 && (p[j-2] == '.' || s[i-1] == p[j-2]))
//                        arr[i][j] = arr[i-1][j] || arr[i][j-2];
//                    else arr[i][j] = arr[i][j-2];
//                }
//                else if(p[j-1] == '.')
//                {
//                    if(i > 0)
//                        arr[i][j] = arr[i-1][j-1];
//                }
//                else
//                {
//                    if(i > 0)
//                        arr[i][j] = s[i-1] == p[j-1] && arr[i-1][j-1];
//                }
//            }
//        }
//        return arr[len1][len2];
//    }
};

int main()
{
    Solution sol;
    string s10("aaaaccccddddabbbb");
    string s11("a.*c*d*ab*");
    string s20("aaaabb");
    string s21(".*");
    string s22("aa.*b");
    string s23("aa.*a");
    string s30("aa");
    string s31("a");
    string s32("a*");
    string s40("ab");
    string s41(".*");
    string s50("aab");
    string s51("c*a*b");
    string s60("mississippi");
    string s61("mis*is*p*.");
    string s70("");
    string s71(".*");
    clock_t ti = clock();
    std::cout << "是否匹配：" << std::boolalpha << sol.isMatch(s10,s11) << std::endl;
//    std::cout << "是否匹配：" << std::boolalpha << sol.isMatch(s20,s21) << std::endl;
//    std::cout << "是否匹配：" << std::boolalpha << sol.isMatch(s20,s22) << std::endl;
//    std::cout << "是否匹配：" << std::boolalpha << sol.isMatch(s20,s23) << std::endl;
    std::cout << "是否匹配：" << std::boolalpha << sol.isMatch(s30,s31) << std::endl;
//    std::cout << "是否匹配：" << std::boolalpha << sol.isMatch(s30,s32) << std::endl;
//    std::cout << "是否匹配：" << std::boolalpha << sol.isMatch(s40,s41) << std::endl;
//    std::cout << "是否匹配：" << std::boolalpha << sol.isMatch(s50,s51) << std::endl;
    std::cout << "是否匹配：" << std::boolalpha << sol.isMatch(s60,s61) << std::endl;
    std::cout << "是否匹配：" << std::boolalpha << sol.isMatch(s70,s71) << std::endl;
    std::cout << "耗时：" << clock() - ti << "微秒" << std::endl;
    return 0;
}
