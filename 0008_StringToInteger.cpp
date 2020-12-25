/*8. 字符串转换整数 (atoi)（中等）：完成
    请你来实现一个atoi函数，使其能将字符串转换成整数。
    首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。接下来的转化规则如下：

    如果第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字字符组合起来，形成一个有符号整数。
    假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成一个整数。
    该字符串在有效的整数部分之后也可能会存在多余的字符，那么这些字符可以被忽略，它们对函数不应该造成影响。
注意：
    假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换，
    即无法进行有效转换。
    在任何情况下，若函数不能进行有效的转换时，请返回0。

提示：
    本题中的空白字符只包括空格字符' '。
    假设我们的环境只能存储32位大小的有符号整数，那么其数值范围为[−2^31,2^31−1]。如果数值超过这个范围，请返回INT_MAX(2^31−1)
    或INT_MIN(−2^31)。
示例1:
    输入: "42"
    输出: 42
示例2:
    输入: "   -42"
    输出: -42
    解释: 第一个非空白字符为'-', 它是一个负号。
    我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
示例3:
    输入: "4193 with words"
    输出: 4193
    解释: 转换截止于数字'3'，因为它的下一个字符不为数字。
示例4:
    输入: "words and 987"
    输出: 0
    解释: 第一个非空字符是'w', 但它不是数字或正、负号。
    因此无法执行有效的转换。
示例5:
    输入: "-91283472332"
    输出: -2147483648
    解释: 数字"-91283472332"超过32位有符号整数范围。
    因此返回INT_MIN(−231)。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/string-to-integer-atoi
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    int myAtoi(string s) {
        int len = s.length();
        if(len == 0)
            return 0;
        int i = 0;
        while(s[i] == ' ' && i < len-1)
            i++;
        if(s[i] == ' ' || (s[i] != '+' && s[i] != '-' && s[i] < 48 && s[i] > 57))
            return 0;
        if((s[i] == '+' || s[i] == '-') && i == len - 1)
            return 0;
        int coef = 1;
        if(s[i] == '-')
        {
            i++;
            coef = -1;
        }
        else if(s[i] == '+')
            i++;
        int ret = 0;
        while(i < len && s[i] >= 48 && s[i] <= 57)
        {
            if(ret > 214748364)
                return coef==1?INT_MAX:INT_MIN;
            else if(ret == 214748364)
            {
                if(coef == 1 && s[i] - 48 > 6)
                    return INT_MAX;
                if(coef == -1 && s[i] - 48 > 7)
                    return INT_MIN;
            }
            int tmp = s[i++] - 48;
            ret = 10 * ret + tmp;
        }
        ret *= coef;
        return ret;
    }
};

int main()
{
    Solution sol;
    string s1("");
    string s2(" ");
    string s3("     ");
    string s4("    4325sdfef");
    string s5("    4325");
    string s6("    sdfef");
    string s7("sdfef");
    string s8("    sdfef123123");
    string s9("    +123123sdf");
    string s10("    -123123sdf");
    string s11("    +");
    string s12("+");
    string s13("-");
    string s14("    -");
    string s15("+bhj788");
    string s16("   -moklm8789");
    string s17("-91283472332");
    string s18("-2147483648");
    string s19("2147483649");
    string s20("2147483646");
    clock_t ti = clock();
//    std::cout << "转换之后的整数为：" << sol.myAtoi(s1) << std::endl;
//    std::cout << "转换之后的整数为：" << sol.myAtoi(s2) << std::endl;
//    std::cout << "转换之后的整数为：" << sol.myAtoi(s3) << std::endl;
//    std::cout << "转换之后的整数为：" << sol.myAtoi(s4) << std::endl;
//    std::cout << "转换之后的整数为：" << sol.myAtoi(s5) << std::endl;
//    std::cout << "转换之后的整数为：" << sol.myAtoi(s6) << std::endl;
//    std::cout << "转换之后的整数为：" << sol.myAtoi(s7) << std::endl;
//    std::cout << "转换之后的整数为：" << sol.myAtoi(s8) << std::endl;
//    std::cout << "转换之后的整数为：" << sol.myAtoi(s9) << std::endl;
//    std::cout << "转换之后的整数为：" << sol.myAtoi(s10) << std::endl;
//    std::cout << "转换之后的整数为：" << sol.myAtoi(s11) << std::endl;
//    std::cout << "转换之后的整数为：" << sol.myAtoi(s12) << std::endl;
//    std::cout << "转换之后的整数为：" << sol.myAtoi(s13) << std::endl;
//    std::cout << "转换之后的整数为：" << sol.myAtoi(s14) << std::endl;
//    std::cout << "转换之后的整数为：" << sol.myAtoi(s15) << std::endl;
//    std::cout << "转换之后的整数为：" << sol.myAtoi(s16) << std::endl;
//    std::cout << "转换之后的整数为：" << sol.myAtoi(s17) << std::endl;
    std::cout << "转换之后的整数为：" << sol.myAtoi(s18) << std::endl;
    std::cout << "转换之后的整数为：" << sol.myAtoi(s19) << std::endl;
    std::cout << "转换之后的整数为：" << sol.myAtoi(s20) << std::endl;
    std::cout << "耗时：" << clock() - ti << "微秒" << std::endl;
    return 0;
}