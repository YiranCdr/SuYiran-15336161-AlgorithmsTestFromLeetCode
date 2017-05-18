/*
Description

You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
Find out how many ways to assign symbols to make sum of integers equal to target S.
Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3.
Output: 5
Explanation:
-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
There are 5 ways to assign symbols to make the sum of nums be target 3.

Ideas
类似0/1背包问题求解。
f[i][v]代表对于vector中的前i个元素，当s值为v时的方案个数。
    f[i][v] = f[i - 1][v - nums[i-1]] + f[i - 1][v + nums[i-1]]
    
Code

*/
/*
2-dimension array
int **p = new int*[m]; //开辟行
for(int i = 0; i < m; i++)
p[i] = new int[n]; //开辟列
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		//initiallize
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)sum += nums[i];

		int ss = S;
		if (S < 0)ss *= -1;
		if (sum < S)return 0;

		int ** f = new int*[nums.size() + 1];
		for (int i = 0; i < nums.size() + 1; i++) f[i] = new int[sum * 2 + 1];
		for (int i = 0; i < nums.size(); i++)for (int j = 0; j < sum * 2 + 1; j++)f[i][j] = 0;
		//base
		if (nums.size() == 1) {
			if (ss == nums[0])return 1;
			else return 0;
		}
		f[1][sum - nums[0]] = 1;
		f[1][sum + nums[0]] = 1;
		if (nums[0] == 0)f[1][sum] = 2;
		//dp
		for (int i = 2; i <= nums.size(); i++) {
			for (int v = 0; v < sum * 2 + 1; v++) {
				if (v - nums[i-1] < 0)f[i][v] = f[i - 1][v + nums[i-1]];
				else if (v + nums[i-1] >= sum * 2 + 1)f[i][v] = f[i - 1][v - nums[i-1]];
				else f[i][v] = f[i - 1][v - nums[i-1]] + f[i - 1][v + nums[i-1]];
			}
		}
		return f[nums.size()][sum + S];
	}
};

//Result
//
//Accept
