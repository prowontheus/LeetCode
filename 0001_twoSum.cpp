/*1. 两数之和（简单）
    给定一个整数数组 nums和一个目标值 target，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。
    你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

示例：
    给定 nums = [2, 7, 11, 15], target = 9
    因为 nums[0] + nums[1] = 2 + 7 = 9
    所以返回 [0, 1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>
#include <vector>
#include <tuple>
#include <chrono>
#include <unordered_map>
#include <__hash_table>

using std::vector;
using std::tuple;
using std::unordered_map;
using std::hash;

class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int target,int low,int high) {
        int len = nums.size();
        vector<vector<int>> ret;
        ret.resize(0);
        if(len <= 1 || low < 0 || high <= 0 || low >= len - 1 || high > len - 1 || low >= high)
            return ret;
        for(int i = 0;i < len;i++)
        {
            if(nums[i]*2 > target)
                break;
            auto iter1 = std::find(nums.cbegin(),nums.cend(),target - nums[i]);
            if(iter1 != nums.cend() && i != std::distance(nums.cbegin(),iter1))
            {
                vector<int> tmp = {i,static_cast<int>(std::distance(nums.cbegin(),iter1))};
                ret.push_back(std::move(tmp));
            }
        }
        return ret;
    };
};

int main()
{
    vector<int> vec = {2,3,4,5,6,7,8,11,15};
    int len = vec.size();
    Solution so;
    clock_t ti = clock();
    auto ret = so.twoSum(vec,9,0,len-1);
    for(auto a:ret)
    {
        for(auto b:a)
            std::cout << b << ",";
        std::cout << std::endl;
    }
    std::cout << "程序耗时" << clock() - ti << "微秒" << std::endl;
    return 0;
}