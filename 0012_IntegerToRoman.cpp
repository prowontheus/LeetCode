/*12. 整数转罗马数字（中等）
    罗马数字包含以下七种字符：I，V，X，L，C，D和M。

    字符          数值
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000
    例如，罗马数字2写做II，即为两个并列的1。12写做XII，即为X+II。27写做XXVII, 即为XX+V+II。
    通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如4不写做IIII，而是IV。数字1在数字5的左边，
    所表示的数等于大数5减小数1得到的数值4。同样地，数字9表示为IX。这个特殊的规则只适用于以下六种情况：
    I可以放在V(5)和X(10)的左边，来表示4和9。
    X可以放在L(50)和C(100)的左边，来表示40和90。
    C可以放在D(500)和M(1000)的左边，来表示400和900。
    给定一个整数，将其转为罗马数字。输入确保在1到3999的范围内。
示例1:
    输入:3
    输出: "III"
示例2:
    输入:4
    输出: "IV"
示例3:
    输入:9
    输出: "IX"
示例4:
    输入:58
    输出: "LVIII"
    解释: L = 50, V = 5, III = 3.
示例5:
    输入:1994
    输出: "MCMXCIV"
    解释: M = 1000, CM = 900, XC = 90, IV = 4.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/integer-to-roman
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>

using std::string;

class Solution {
public:
    string intToRoman(int num) {//暴力解法
        char ret[20] = "";
        if(num < 1 || num > 3999)
            return string(ret);
        int i = 0;
        if(num >= 1000)
        {
            int tmp = num / 1000;
            while(tmp-- > 0)
                ret[i++] = 'M';
            num %= 1000;
        }
        if(num >= 900)
        {
            ret[i++] = 'C';
            ret[i++] = 'M';
            num -= 900;
        }
        if(num >= 500)
        {
            ret[i++] = 'D';
            num -= 500;
        }
        if(num >= 400)
        {
            ret[i++] = 'C';
            ret[i++] = 'D';
            num -= 400;
        }
        if(num >= 100)
        {
            int tmp = num / 100;
            while(tmp-- > 0)
                ret[i++] = 'C';
            num %= 100;
        }
        if(num >= 90)
        {
            ret[i++] = 'X';
            ret[i++] = 'C';
            num -= 90;
        }
        if(num >= 50)
        {
            ret[i++] = 'L';
            num -= 50;
        }
        if(num >= 40)
        {
            ret[i++] = 'X';
            ret[i++] = 'L';
            num -= 40;
        }
        if(num >= 10)
        {
            int tmp = num / 10;
            while(tmp-- > 0)
                ret[i++] = 'X';
            num %= 10;
        }
        if(num >= 9)
        {
            ret[i++] = 'I';
            ret[i++] = 'X';
            num -= 9;
        }
        if(num >= 5)
        {
            ret[i++] = 'V';
            num -= 5;
        }
        if(num >= 4)
        {
            ret[i++] = 'I';
            ret[i++] = 'V';
            num -= 4;
        }
        while(num > 0)
        {
            ret[i++] = 'I';
            num--;
        }
        ret[i] = '\0';
        return string(ret);
    }
    string intToRoman2(int num) {//
        int values[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string reps[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string res;
        for(int i=0; i<13; i++){
            while(num>=values[i]){
                num -= values[i];
                res += reps[i];
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    clock_t ti = clock();
    int s1 = 3;
    int s2 = 4;
    int s3 = 9;
    int s4 = 8;
    int s5 = 1994;
    int s6 = 3994;
    int s7 = 14;
    int s8 = 19;
    int s9 = 194;
    int s10 = 199;
    int s11 = 994;
    int s12 = 1994;
    std::cout << "转数字：" << sol.intToRoman(s1) << std::endl;//III
    std::cout << "转数字：" << sol.intToRoman(s2) << std::endl;//IV
    std::cout << "转数字：" << sol.intToRoman(s3) << std::endl;//IX
    std::cout << "转数字：" << sol.intToRoman(s4) << std::endl;//VIII
    std::cout << "转数字：" << sol.intToRoman(s5) << std::endl;//MCMXCIV
    std::cout << "转数字：" << sol.intToRoman(s6) << std::endl;//MMMCMXCIV
    std::cout << "转数字：" << sol.intToRoman(s7) << std::endl;//XIV
    std::cout << "转数字：" << sol.intToRoman(s8) << std::endl;//XIX
    std::cout << "转数字：" << sol.intToRoman(s9) << std::endl;//CXCIV
    std::cout << "转数字：" << sol.intToRoman(s10) << std::endl;//CXCIX
    std::cout << "转数字：" << sol.intToRoman(s11) << std::endl;//CMXCIV
    std::cout << "转数字：" << sol.intToRoman(s12) << std::endl;//MCMXCIV
    std::cout << "耗时：" << clock() - ti << "微秒" << std::endl;
    return 0;
}