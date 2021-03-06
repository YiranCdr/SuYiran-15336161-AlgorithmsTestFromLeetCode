/*
Description

Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5
max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0
In this case, no transaction is done, i.e. max profit = 0.

Idea

This problem is somehow easier.
suppose dp[i] is the min value between prices[0] and prices[i].
For each prices, compare it with dp[i] and find the max difference.
dp[i]=max{dp[i-1], prices[i]}.

Code

*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 0 || prices.size() == 1)return 0;
		int result = 0;
		int * dp = new int[prices.size()];
		for (int i = 0; i < prices.size(); i++) {
			dp[i] = 65536;
		}
		dp[0] = prices[0];
		for (int i = 1; i < prices.size(); i++) {
			if (prices[i] - dp[i - 1] > result) {
				result = prices[i] - dp[i - 1];
			}
			if (prices[i] < dp[i - 1]) {
				dp[i] = prices[i];
			}
			else dp[i] = dp[i - 1];
		}
		return result;
	}
};

//Result

//Accept
