/*
377. Combination Sum IV
Ideas
a[i]代表当结果为i时的组合数目。
实际上是对上一解决方案的优化，即是把sofar相同的volume合并。
对于nums中的每一个值temp，都有
if (temp <= i)a[i] += a[i - temp];
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		int * a = new int[target + 1];
		for (int i = 1; i < target + 1; i++)a[i] = 0;
		a[0] = 1;
		for (int i = 1; i < target + 1; i++) {
			for (int j = 0; j < nums.size(); j++) {
				int temp = nums[j];
				if (temp <= i)a[i] += a[i - temp];
			}
		}
		return a[target];
	}
};
