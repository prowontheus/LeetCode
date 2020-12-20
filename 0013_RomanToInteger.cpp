/*13. 罗马数字转整数（简单）
    罗马数字包含以下七种字符:I，V，X，L，C，D和M。
    字符          数值
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000
    例如，罗马数字2写做II，即为两个并列的1。12写做XII,即为X+II。27写做XXVII,即为XX+V+II。通常情况下，罗马数字中小的数字
    在大的数字的右边。但也存在特例，例如4不写做IIII，而是IV。数字1在数字5的左边，所表示的数等于大数5减小数1得到的数值4。同
    样地，数字9表示为IX。这个特殊的规则只适用于以下六种情况：
    I 可以放在V(5)和X(10)的左边，来表示4和9。
    X 可以放在L(50)和C(100)的左边，来表示40和90。
    C 可以放在D(500)和M(1000)的左边，来表示400和900。
    给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
示例 1:
    输入: "III"
    输出: 3
示例 2:
    输入: "IV"
    输出: 4
示例 3:
    输入: "IX"
    输出: 9
示例 4:
    输入: "LVIII"
    输出: 58
解释: L=50,V=5,III=3.
示例 5:
    输入: "MCMXCIV"
    输出: 1994
解释: M=1000,CM=900,XC=90,IV=4.
提示：
    题目所给测试用例皆符合罗马数字书写规则，不会出现跨位等情况。
    IC和IM这样的例子并不符合题目要求,49应该写作XLIX，999应该写作CMXCIX。
    关于罗马数字的详尽书写规则，可以参考罗马数字-Mathematics。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/roman-to-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    int romanToInt(string s) {
        int len = s.length();
        if(len <= 0)
            return 0;
        int ret = 0;
        int i = 0;
        while(i < len)
        {
            if(s[i] == 'M')
            {
                ret += 1000;
                if(i - 1 >= 0 && s[i-1] == 'C')
                    ret -= 200;
            }
            else if(s[i] == 'D')
            {
                ret += 500;
                if(i - 1 >= 0 && s[i-1] == 'C')
                    ret -= 200;
            }
            else if(s[i] == 'C')
            {
                ret += 100;
                if(i - 1 >= 0 && s[i-1] == 'X')
                    ret -= 20;
            }
            else if(s[i] == 'L')
            {
                ret += 50;
                if(i - 1 >= 0 && s[i-1] == 'X')
                    ret -= 20;
            }
            else if(s[i] == 'X')
            {
                ret += 10;
                if(i - 1 >= 0 && s[i-1] == 'I')
                    ret -= 2;
            }
            else if(s[i] == 'V')
            {
                ret += 5;
                if(i - 1 >= 0 && s[i-1] == 'I')
                        ret -= 2;
            }
            else if(s[i] == 'I')
                ret += 1;
            i++;
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    clock_t ti = clock();
    string s1("III");
    string s2("IV");
    string s3("IX");
    string s4("LVIII");
    string s5("MCMXCIV");
    string s6("MMM");
    std::cout << "转数字：" << sol.romanToInt(s1) << std::endl;
    std::cout << "转数字：" << sol.romanToInt(s2) << std::endl;
    std::cout << "转数字：" << sol.romanToInt(s3) << std::endl;
    std::cout << "转数字：" << sol.romanToInt(s4) << std::endl;
    std::cout << "转数字：" << sol.romanToInt(s5) << std::endl;
    std::cout << "转数字：" << sol.romanToInt(s6) << std::endl;
    std::cout << "耗时：" << clock() - ti << "微秒" << std::endl;
    string tmp;
    while(std::cin >> tmp)
    {
        std::cout << "转数字：" << sol.romanToInt(tmp) << std::endl;
    }
    return 0;
}