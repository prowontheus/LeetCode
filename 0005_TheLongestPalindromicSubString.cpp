/*5. 最长回文子串（中等）：完成
    给定一个字符串s，找到s中最长的回文子串。你可以假设s的最大长度为1000。
示例1：
    输入: "babad"
    输出: "bab"
    注意: "aba" 也是一个有效答案。
示例 2：
    输入: "cbbd"
    输出: "bb"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    string longestPalindrome1(string s) {//暴力解法
        int len = s.length();
        if(len <= 1)
            return s;
        string max;
        max = s.at(0);
        for(int i = 0;i < len;i++)
        {
            for(int j = i+1;j < len;j++)
            {
                if(s.at(i) == s.at(j))
                {
                    bool ret = true;
                    for(int k = i+1;k < (i+j+1)/2;k++)
                    {
                        if(s.at(k) != s.at(i+j-k))
                        {
                            ret = false;
                            break;
                        }
                    }
                    if(ret && j-i+1 > max.size())
                    {
                        max = s.substr(i,j-i+1);
                    }
                }
            }
            if(len - i <= max.length())
            {
                return max;
            }
        }
        return max;
    }
    string longestPalindrome2(string s){//中心扩散法
        int len = s.length();
        if(len <= 1)
            return s;
        int low = 0,max_len = 1;
        for(int i = 0;i < len-1;i++)
        {
            int len1 = lenofPalindrom(s,i,i);
            int len2 = lenofPalindrom(s,i,i+1);
            if(max_len < (len1>len2?len1:len2))
            {
                max_len = len1>len2?len1:len2;
                low = i - (max_len - 1) / 2;
            }
        }
        return s.substr(low,max_len);
    }
    int lenofPalindrom(string& s,int left,int right)
    {
        int len = s.length();
        int i = left,j = right;
        while(i >= 0 && j < len)
        {
            if(s[i] == s[j])
            {
                i--;
                j++;
            }
            else break;
        }
        return j - i - 1;
    }
    string longestPalindrome3(string s){//DP解法
        int len = s.length();
        if(len <= 1)
            return s;
        int low = 0,max_len = 1;
        bool dp[len][len];//arr[i][j]=true表示从s的第i个字符到第j个字符是回文字串，0 <= i,j <len
        for(int i = 0;i < len;i++)
            dp[i][i] = true;
        for(int i = 1;i < len;i++)
        {
            for(int j = 0;j < i;j++)
            {
                if(s[j] != s[i])
                    dp[j][i] = false;
                else
                {
                    if(i - j >= 3)
                        dp[j][i] = dp[j+1][i-1];
                    else
                        dp[j][i] = true;
                }
                if(dp[j][i] == true && i - j + 1 > max_len)
                {
                    max_len = i - j + 1;
                    low = j;
                }
            }
        }
        return s.substr(low,max_len);
    }
};

int main()
{
    Solution sol;
    string s1("abracacabra");
    string s2("bb");
    string s3("cbbd");
    string s4("0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    string s5("bacacara");
    string s6("cbaccarab");
    string s7("aaaa");
    string s8("babad");
    string s9("baaaa");
    string s10("aaabaaaa");
    string s11("aaaaaab");
    string s12("\"aaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaaaaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaa\"");
    //"aaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaaaaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaa"
    clock_t time1 = clock();
    std::cout << sol.longestPalindrome3(s1) << std::endl;
    std::cout << sol.longestPalindrome3(s2) << std::endl;
    std::cout << sol.longestPalindrome3(s3) << std::endl;
    std::cout << sol.longestPalindrome3(s4) << std::endl;
    std::cout << sol.longestPalindrome3(s5) << std::endl;
    std::cout << sol.longestPalindrome3(s6) << std::endl;
    std::cout << sol.longestPalindrome3(s7) << std::endl;
    std::cout << sol.longestPalindrome3(s8) << std::endl;
    std::cout << sol.longestPalindrome3(s9) << std::endl;
    std::cout << sol.longestPalindrome3(s10) << std::endl;
    std::cout << sol.longestPalindrome3(s11) << std::endl;
    std::cout << "Time elapsed :" << clock() - time1 << "microseconds" << std::endl;
    return 0;
}
