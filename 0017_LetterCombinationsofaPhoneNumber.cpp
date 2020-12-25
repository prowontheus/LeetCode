/*17. 电话号码的字母组合（中等）：未完成
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
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;


//提示：使用深度优先搜索DFS或者广度优先搜索BFS

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
        unordered_map<char,string> un_map = {
                {'0'," "},{'1',""},{'2',"abc"},
                {'3',"def"},{'4',"ghi"},{'5',"jkl"},
                {'6',"mno"},{'7',"pqrs"},{'8',"tuv"},
                {'9',"wxyz"}};
        generate(digits,ret,un_map);
        return ret;
    }
    void generate(string &str,vector<string> &vec,unordered_map<char,string> &unmap)
    {
        if(str.length() <= 0)
        {
            vec.push_back("");
            return ;
        }
        char ch = str[0];
        str.erase(0,1);
        vector<string> tmp;
        generate(str,tmp,unmap);
        for(auto a:unmap[ch])
        {
            for(auto b:tmp)
            {
                vec.push_back(a+b);
            }
        }
    }
};

int main()
{
    Solution sol;
    string str1("23455678");
    clock_t ti = clock();
    auto ret1 = sol.letterCombinations(str1);
    std::cout << "可能的组合有：" << ret1.size() << "种。" << std::endl;
    std::cout << "耗时：" << clock() - ti << "微秒" << std::endl;
    return 0;
}