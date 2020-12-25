/*6. Z 字形变换（中等）：完成
    将一个给定字符串根据给定的行数，以从上往下、从左到右进行Z字形排列。
    比如输入字符串为"LEETCODEISHIRING"行数为 3 时，排列如下：
    L   C   I   R
    E T O E S I I G
    E   D   H   N
    之后，你的输出需要从左往右逐行读取，产生出一个新的字符串,比如："LCIRETOESIIGEDHN"。
    请你实现这个将字符串进行指定行数变换的函数：
    string convert(string s, int numRows);
示例1:
    输入: s = "LEETCODEISHIRING", numRows = 3
    输出: "LCIRETOESIIGEDHN"
示例2:
    输入: s = "LEETCODEISHIRING",numRows = 4
    输出:"LDREOEIIECIHNTSG"
    解释:

    L     D     R
    E   O E   I I
    E C   I H   N
    T     S     G

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/zigzag-conversion
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 0)
            return string("");
        else if(numRows == 1)
            return s;
        int len = s.length();
        if(len <= numRows)
            return s;
        string tmp[numRows];
        string ret;
        int gap = 2 * (numRows - 1);
        for(int i = 0;i < numRows;i++)
        {
            int j = 0;
            while( j + i < len)
            {
                tmp[i].push_back(s[j+i]);
                if(i != 0 && i != numRows - 1 && j-i+gap < len)
                    tmp[i].push_back(s[j-i+gap]);
                j += gap;
            }
        }
        for(int i = 0;i < numRows;i++)
        {
            ret += tmp[i];
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    string s1("leetcodeishiring");
    string s2("PAYPALISHIRING");
    clock_t ti = clock();
//    std::cout << "变换之后的输出：" << sol.convert(s1,3) << std::endl;
//    std::cout << "变换之后的输出：" << sol.convert(s1,4) << std::endl;
//    std::cout << "变换之后的输出：" << sol.convert(s1,5) << std::endl;
    std::cout << "变换之后的输出：" << sol.convert(s2,3) << std::endl;
    std::cout << "变换之后的输出：" << sol.convert(s2,4) << std::endl;
    std::cout << "变换之后的输出：" << sol.convert(s2,5) << std::endl;
    std::cout << "耗时：" << clock() - ti << "微秒" << std::endl;
    return 0;
}