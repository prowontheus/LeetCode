/*17. 电话号码的字母组合（中等）
    给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
    给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
定义：
    数字9键对应的字母：
            2-abc   3-def
    4-ghi   5-jkl   6-mno
    7-pqrs  8-tuv   9-wxyz
示例:
    输入："23"
    输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明:
    尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>
#include <vector>
#include <string>
#include <map>

using std::vector;
using std::string;
using std::map;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        ret.resize(0);
        int len = digits.length();
        if(len <= 0)
            return ret;
        for(auto r:digits)
        {
            if(r < 50 || r > 57)
                return ret;
        }
        for(auto a:digits)
        {
            switch (a)
            {
                case '2':
                    ret.push_back("abc");
                    break;
                case '3':
                    ret.push_back("def");
                    break;
                case '4':
                    ret.push_back("ghi");
                    break;
                case '5':
                    ret.push_back("jkl");
                    break;
                case '6':
                    ret.push_back("mno");
                    break;
                case '7':
                    ret.push_back("pqrs");
                    break;
                case '8':
                    ret.push_back("tuv");
                    break;
                case '9':
                    ret.push_back("wxyz");
                    break;
            }
        }
        return generate(ret,0,ret.size()-1);
//        map<int,vector<char>> map_tmp;
//        map_tmp.insert(std::pair<int,vector<char>>(2,{'a','b','c'}));
//        map_tmp.insert(std::pair<int,vector<char>>(3,{'d','e','f'}));
//        map_tmp.insert(std::pair<int,vector<char>>(4,{'g','h','i'}));
//        map_tmp.insert(std::pair<int,vector<char>>(5,{'j','k','l'}));
//        map_tmp.insert(std::pair<int,vector<char>>(6,{'m','n','o'}));
//        map_tmp.insert(std::pair<int,vector<char>>(7,{'p','q','r','s'}));
//        map_tmp.insert(std::pair<int,vector<char>>(8,{'t','u','v'}));
//        map_tmp.insert(std::pair<int,vector<char>>(9,{'w','x','y','z'}));
//        return ret;
    }
    vector<string> generate(vector<string> &vec,int low,int high)
    {
        vector<string> ret;
        int len = vec.size();
        if(low < 0 || high < 0 || low >= len || high >= len || low > high)
            return ret;
        for (auto a:vec)
        {
            if (a.length() == 3)
            {}
            else if (a.length() == 4)
            {}
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    string str1("2345");
    clock_t ti = clock();
    auto ret1 = sol.letterCombinations(str1);
    std::cout << "可能的组合有：" << ret1.size() << "种。" << std::endl;
    std::cout << "耗时：" << clock() - ti << "微秒" << std::endl;
    return 0;
}