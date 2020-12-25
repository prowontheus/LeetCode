/*18. 四数之和（中等）：完成
    给定一个包含n个整数的数组nums和一个目标值target，判断nums中是否存在四个元素a，b，c和d，使得a+b+c+d的值与target相等？
    找出所有满足条件且不重复的四元组。
注意：
    答案中不可以包含重复的四元组。
示例：
    给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
    满足要求的四元组集合为：
    [
      [-1,  0, 0, 1],
      [-2, -1, 1, 2],
      [-2,  0, 0, 2]
    ]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/4sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<vector<int>> ret;
        if(len <= 3)
            return ret;
        std::sort(nums.begin(),nums.end());
        int l = 0;
        int tmp = 0;
        for(int i = 0;i < len-3;++i)
        {
            if(nums[i] * 4 > target)
                break;
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            for(int j = i + 1;j < len-2;++j)
            {
                if(nums[i] + nums[j] * 3 > target)
                    break;
                if(j > i + 1 && nums[j] == nums[j-1])
                    continue;
                if(nums[i] + nums[j] + nums[len-1]*2 < target)
                    continue;
                l = len-1;
                for(int k = j + 1;k < len-1;++k)
                {
                    if(nums[i] + nums[j] + nums[k] * 2 > target)
                        break;
                    if(k > j + 1 && nums[k] == nums[k-1])
                        continue;
                    tmp = nums[i] + nums[j] + nums[k];
                    while(k < l && tmp + nums[l] > target)
                        l--;
                    if(k == l)
                        break;
                    if(tmp + nums[l] == target)
                        ret.push_back(vector<int>({nums[i],nums[j],nums[k],target-tmp}));
                }
            }
        }
        return ret;
    }
    void print(vector<vector<int>>& vecvec)
    {
        for(auto a:vecvec)
        {
            for(auto b:a)
            {
                std::cout << b << ",";
            }
            std::cout << std::endl;
        }
        std::cout << "--------------------------------------------------------------------------------" << std::endl;
        std::cout << "vector->size() = " << vecvec.size() << std::endl;
    }
};

int main()
{
    Solution sol;
    vector<int> vec1 = {1, 0, -1, 0, -2, 2};
    vector<int> vec2 = {-1, 0, 1, 2, -1, -4};
    vector<int> vec3 = {-6,-8,-9,4,-14,6,-10,7,12,13,4,9,7,14,-12,7,0,14,-1,-3,2,2,-3,11,-6,-10,-13,-13,1,-9,2,2,-2,8,-9,0,-9,-12,14,10,8,3,4,0,-6,7,14,9,6,-2,13,-15,8,-5,3,-13,-8,5,-11,0,11,6,-13,-14,-9,-15,-7,-11,10,-7,14,4,3,3,11,13,-13,11,-1,0,-6,-10,0,9,0,10,11,0,0,-14,-15,-12,-1,10,12,-2,2,-10,2,-2,-10,2,-13,1,12,5,-1,-15,1,5,-8,3,10,8};
    vector<int> vec4 = {0,0,0};
    vector<int> vec5 = {2,4,1,0,-3,-1};
    vector<int> vec6 = {-4,-3,-3,-2,-2,0,2,6,7,8,8,8,9,};
    int target = 17;
    clock_t ti = clock();
    auto ret1 = sol.fourSum(vec1,0);
    sol.print(ret1);
    std::cout << "vector->size()=" << ret1.size() << std::endl;
    auto ret2 = sol.fourSum(vec2,0);
    sol.print(ret2);
    std::cout << "vector->size()=" << ret2.size() << std::endl;
    auto ret3 = sol.fourSum(vec3,18);
    sol.print(ret3);
    std::cout << "vector->size()=" << ret3.size() << std::endl;
    auto ret4 = sol.fourSum(vec4,0);
    sol.print(ret4);
    std::cout << "vector->size()=" << ret4.size() << std::endl;
    auto ret5 = sol.fourSum(vec5,0);
    sol.print(ret5);
    std::cout << "vector->size()=" << ret5.size() << std::endl;
    auto ret6 = sol.fourSum(vec6,0);
    sol.print(ret6);
    std::cout << "vector->size()=" << ret6.size() << std::endl;
    std::cout << "耗时：" << clock() - ti << "微秒" << std::endl;
    return 0;
}