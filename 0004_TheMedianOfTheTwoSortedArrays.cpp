/*4. 寻找两个正序数组的中位数（困难）：完成
    给定两个大小为m和n的正序（从小到大）数组nums1和nums2。请你找出并返回这两个正序数组的中位数。
    进阶：你能设计一个时间复杂度为O(log(m+n))的算法解决此问题吗？

示例1：
    输入：nums1=[1,3],nums2=[2]
    输出：2.00000
    解释：合并数组=[1,2,3]，中位数2
示例2：
    输入：nums1=[1,2],nums2= [3,4]
    输出：2.50000
    解释：合并数组=[1,2,3,4],中位数(2+3)/2=2.5
示例3：
    输入：nums1=[0,0],nums2=[0,0]
    输出：0.00000
示例4：
    输入：nums1=[],nums2=[1]
    输出：1.00000
示例5：
    输入：nums1=[2],nums2=[]
    输出：2.00000
提示：
    nums1.length==m
    nums2.length==n
    0<=m<=1000
    0<=n<=1000
    1<=m+n<=2000
    -10^6<=nums1[i],nums2[i]<=10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> nums3;
        if(m <= 0 && n <= 0)
            return 0;
        int len = (m+n)/2;
        int i = 0,j = 0;
        while(i < m && j < n)
        {
            if(nums1[i] < nums2[j])
                nums3.push_back(nums1[i++]);
            else
                nums3.push_back(nums2[j++]);
            if(i + j > len)
                return (m+n)%2==0?(nums3[len-1] + nums3[len])/2.0:static_cast<double>(nums3[len]);
        }
        if(i >= m && i + j <= len)
        {
            for(int k = j;k <= (n-m)/2;k++)
                nums3.push_back(nums2[k]);
        }
        if(j >= n && i + j <= len)
        {
            for(int k = i;k <= (m-n)/2;k++)
                nums3.push_back(nums1[k]);
        }
        if((m+n)%2 == 0)
            return (nums3[len-1] + nums3[len])/2.0;
        else return static_cast<double>(nums3[len]);
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1,3,5,7,9,11,13,15};
    vector<int> nums2 = {2,4,6,8,10,12,14,16};
//    vector<int> nums1 = {4,5,6,7,8,9,10,11};
//    vector<int> nums2 = {1,2,3};
//    vector<int> nums1 = {1,2};
//    vector<int> nums2 = {3,4};
    std::cout << "The median of nums1 and nums2 is " << sol.findMedianSortedArrays(nums1,nums2) << std::endl;
    return 0;
}