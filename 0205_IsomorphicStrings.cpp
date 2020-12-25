/*205. 同构字符串（简单）：完成
    给定两个字符串s和t，判断它们是否是同构的。
    如果s中的字符可以被替换得到t，那么这两个字符串是同构的。
    所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。
示例 1:
    输入: s = "egg", t = "add"
    输出: true
示例 2:
    输入: s = "foo", t = "bar"
    输出: false
示例 3:
    输入: s = "paper", t = "title"
    输出: true
说明:
    你可以假设s和t具有相同的长度。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/isomorphic-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>
#include <string>
#include <unordered_map>

using std::unordered_map;
using std::string;

class Solution {
public:
    bool isIsomorphic1(string s, string t) {
        int len1 = s.length(),len2 = t.length();
        if(len1 == 0 && len2 == 0)
            return true;
        if(len1 != len2)
            return false;
        int arr[len1];
        for(int i = 0;i < len1;i++)
            arr[i] = 0;
        for(int i = 0;i < len1;i++)
        {
            if(arr[i] == 0)
            {
                arr[i] = 1;
                for(int j = i+1;j < len1;j++)
                {
                    if(t[j] == t[i] && arr[j] == 0)
                    {
                        if(s[j] == s[i])
                        {
                            t[j] = s[i];
                            arr[j] = 1;
                        }
                        else return false;
                    }
                    else
                    {
                        if(s[j] == s[i])
                            return false;
                    }
                }
                t[i] = s[i];
            }
        }
        return true;
    }
    bool isIsomorphic2(string s, string t) {
        int len1 = s.length(),len2 = t.length();
        if(len1 == 0 && len2 == 0)
            return true;
        if(len1 != len2)
            return false;
        unordered_map<char,char> tmp;
        for(int i = 0;i < len1;i++)
        {
            auto ret = tmp.find(s[i]);
            if(ret == tmp.cend())
            {
                for(auto r:tmp)
                {
                    if(r.second == t[i] && r.first != s[i])
                        return false;
                }
                tmp.insert(std::pair<char,char>(s[i],t[i]));
            }
            else if(ret->second != t[i])
                return false;
        }
        return true;
    }
    bool isIsomorphic3(string s, string t)
    {//速度最快

        if (s.empty() && t.empty())
            return true;
        if (s.empty() || t.empty())
            return false;
        if (s.size() != t.size())
            return false;
        for (int i = 0; i < s.size(); i++)
        {
            auto tmp1 = s.find(s[i]);
            auto tmp2 = t.find(t[i]);
            if (tmp1 != tmp2)//哈希思想，如果abb第二次找b时返回1而不会返回2，相当于keyb的value是1
                return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    string s1("egg");
    string s2("add");
    string s3("fooo");
    string s4("bara");
    string s5("paper");
    string s6("title");
    string s7("aabbcccdff");
    string s8("aaffggghff");
    string s9("aa");
    string s10("ab");
    string s11("baa");
    string s12("aba");
    string s13("aabbccaabc");
    clock_t ti = clock();
//    std::cout << s1 << "和" << s2 << "是否同构：" << std::boolalpha << sol.isIsomorphic2(s1,s2) << std::endl;//true
//    std::cout << s3 << "和" << s4 << "是否同构：" << std::boolalpha << sol.isIsomorphic2(s3,s4) << std::endl;//false
//    std::cout << s4 << "和" << s3 << "是否同构：" << std::boolalpha << sol.isIsomorphic2(s4,s3) << std::endl;//false
//    std::cout << s5 << "和" << s6 << "是否同构：" << std::boolalpha << sol.isIsomorphic2(s5,s6) << std::endl;//true
    std::cout << s7 << "和" << s8 << "是否同构：" << std::boolalpha << sol.isIsomorphic2(s7,s8) << std::endl;//false
    std::cout << s8 << "和" << s7 << "是否同构：" << std::boolalpha << sol.isIsomorphic2(s8,s7) << std::endl;//false
    std::cout << s9 << "和" << s10 << "是否同构：" << std::boolalpha << sol.isIsomorphic2(s9,s10) << std::endl;//false
    std::cout << s10 << "和" << s9 << "是否同构：" << std::boolalpha << sol.isIsomorphic2(s10,s9) << std::endl;//false
    std::cout << s11 << "和" << s12 << "是否同构：" << std::boolalpha << sol.isIsomorphic2(s11,s12) << std::endl;//false
    std::cout << s12 << "和" << s11 << "是否同构：" << std::boolalpha << sol.isIsomorphic2(s12,s11) << std::endl;//false
    std::cout << s8 << "和" << s13 << "是否同构：" << std::boolalpha << sol.isIsomorphic2(s8,s13) << std::endl;//false
    std::cout << "耗时：" << clock() - ti << "微秒" << std::endl;
    return 0;
}