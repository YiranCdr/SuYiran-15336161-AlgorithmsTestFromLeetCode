53. Maximum Subarray-Something wrong with the .md format

Discription  

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.  
For example, given the array [-2,1,-3,4,-1,2,1,-5,4],  
the contiguous subarray [4,-1,2,1] has the largest sum = 6. 

Ideas  

首先查看容器大小是否为1；     
若不为1，则找到中间元素。  
若中间元素包含在最大子列中，则向左向右扩展子列；  
若中间元素不包含在最大子列中，就把原容器二分为两个子列，重复上述操作。  

Code
    #include<iostream>
    #include<algorithm>
    #include<vector>
    using namespace std;
    class Solution {
    public:
      int maxSubArray(const vector<int>& nums) {
        return maxDC(nums, 0, nums.size() - 1);
      }
      int maxDC(const vector<int>& nums, int left, int right) {
        if (left == right)return nums[left];
        int mElmtIdx = (left + right) / 2;
        int mElmt = nums[mElmtIdx];
        int lftMax = mElmt;
        int rtMax = nums[mElmtIdx + 1];
        int temp = 0;
        for (int i = mElmtIdx; i >= left; i--) {
          temp += nums[i];
          if (temp > lftMax)lftMax = temp;
        }
        temp = 0;
        for (int i = mElmtIdx + 1; i <= right; i++) {
          temp += nums[i];
          if (temp > rtMax)rtMax = temp;
        }
        //divide
        int lftMaxDC = maxDC(nums, left, mElmtIdx);
        int rtMaxDC = maxDC(nums, mElmtIdx + 1, right);
        return max(max(lftMaxDC,rtMaxDC), lftMax + rtMax);
      }
    };
    
Result
Accept
