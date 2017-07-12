/*
Description

You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Note: Given n will be a positive integer.

Idea

很经典的一道递归求解问题。不过这一次用dp的方法来做。其实是一样的。
dp[i] = dp[i - 1] + dp[i - 2];
dp[i]代表当一共有i级楼梯时爬楼的解决方案
//我好累啊
那么要么是从第i-1台阶走一步跨一个台阶上来，要么是从第i-1台阶走一步跨两个台阶上来。

Code

*/
#include<iostream>
using namespace std;
class Solution {
public:
	int climbStairs(int n) {
		int *dp = new int[n];
		for (int i = 0; i < n; i++) {
			dp[i] = 0;
		}
		dp[0] = 1;
		dp[1] = 2;
		for (int i = 2; i < n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n - 1];
	}
};

//Result

//Accept
