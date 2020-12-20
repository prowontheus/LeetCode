/*10. 正则表达式匹配（困难）
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

using std::string;

class Solution {
public:
//    bool isMatch(string s, string p) {
//        int len1 = s.length(),len2 = p.length();
//        if(len1 == 0 || len2 == 0)
//            return false;
//        if(p[0] == '*')
//        {
//            if(len2 == 1)
//                return true;
//            int pos = 0;
//            while((pos = p.find('*',1)) != string::npos)
//            {
//                if(pos > 0)
//                {
//                    int spos = s.find(p.substr(1,pos-1));
//                    if( spos != string::npos)
//                    {
//                        s = s.substr(spos + 1, len1 - spos - 1);
//                        len1 -= spos + 1;
//                    }
//                    else return false;
//                }
//                p = p.substr(pos,len2-1);
//                len2 -= pos;
//            }
//            if(len1 + 1 < len2)
//                return false;
//            return isMatch(s.substr(len1 - len2 + 1, len2 - 1),p.substr(1, len2 - 1));
//        }
//        int i = 0,j = 0;
//        while(i < len1 && j < len2)
//        {
//            if(p[j] == '.')
//            {
//                if(j + 1 >= len2)
//                    return i + 1 == len1;
//                else
//                {
//                    i++;
//                    j++;
//                }
//            }
//            else if(p[j] == '*')
//            {
//                if(j + 1 >= len2)
//                    return true;
//                else
//                    return isMatch(s.substr(i,len1-i+1),p.substr(j,len2-j+1));
//            }
//            else
//            {
//                if(s[i++] != p[j++])
//                    return false;
//            }
//        }
//        return i == len1 && j == len2;
//    }
    bool isMatch(string s, string p) {
        int len1 = s.length(),len2 = p.length();
        if(len1 == 0 || len2 == 0)
            return false;
        if(p.find('.') == string::npos && p.find('*') == string::npos)
            return s == p;
        int k = 0;
        while(k < len2 && p[k] == '*')
            k++;
        p = p.substr(k,len2 - k - 1);
        len2 = len2 - k - 1;
//        while (p[0] == '.')
//        {
//            if(len2 == 1)
//            {
//                if(p[0] == '.')
//                    return len1 == 1;
//                else return true;
//            }
//            else if(len2 == 2)
//            {
////                if(p[1] == )
//            }
//        }
//        if(p[0] == '*')
//        {
//            if(len2 == 1)
//                return true;
//            int pos = 0;
//            while((pos = p.find('*',1)) != string::npos)
//            {
//                if(pos > 0)
//                {
//                    int spos = s.find(p.substr(1,pos-1));
//                    if( spos != string::npos)
//                    {
//                        s = s.substr(spos + 1, len1 - spos - 1);
//                        len1 -= spos + 1;
//                    }
//                    else return false;
//                }
//                p = p.substr(pos,len2-1);
//                len2 -= pos;
//            }
//            if(len1 + 1 < len2)
//                return false;
//            return isMatch(s.substr(len1 - len2 + 1, len2 - 1),p.substr(1, len2 - 1));
//        }
        int i = 0,j = 0;
        while(i < len1 && j < len2)
        {
            if(p[j] == '.')
            {
                if(j + 1 >= len2)
                    return i + 1 == len1;
                else
                {
                    i++;
                    j++;
                }
            }
            else if(p[j] == '*')
            {
                if(j + 1 >= len2)
                    return true;
                else
                    return isMatch(s.substr(i,len1-i+1),p.substr(j-1,len2-j+1));
            }
            else if(j+1 < len2 && p[j+1] == '*')
            {
                if(s[i++] != p[j++])
                    return false;
            }
        }
        return i == len1 && j == len2;
    }
};

int main()
{
    Solution sol;
    string s10("aaaaccccddddabbbb");
    string s11("aa.*c*a*b.b.");
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
    string s61("**.*is*p*.");
    clock_t ti = clock();
//    std::cout << "是否匹配：" << std::boolalpha << sol.isMatch(s10,s11) << std::endl;
//    std::cout << "是否匹配：" << std::boolalpha << sol.isMatch(s20,s21) << std::endl;
//    std::cout << "是否匹配：" << std::boolalpha << sol.isMatch(s20,s22) << std::endl;
//    std::cout << "是否匹配：" << std::boolalpha << sol.isMatch(s20,s23) << std::endl;
//    std::cout << "是否匹配：" << std::boolalpha << sol.isMatch(s30,s31) << std::endl;
//    std::cout << "是否匹配：" << std::boolalpha << sol.isMatch(s30,s32) << std::endl;
//    std::cout << "是否匹配：" << std::boolalpha << sol.isMatch(s40,s41) << std::endl;
//    std::cout << "是否匹配：" << std::boolalpha << sol.isMatch(s50,s51) << std::endl;
    std::cout << "是否匹配：" << std::boolalpha << sol.isMatch(s60,s61) << std::endl;
    std::cout << "耗时：" << clock() - ti << "微秒" << std::endl;
    return 0;
}
