/*
Description

Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
For example,
Given n = 3, there are a total of 5 unique BST's.
1         3     3      2      1
\       /     /      / \      \
3     2     1      1   3      2
/     /       \                 \
2     1         2                 3

Idea

当一个新的值、而且是比之前所有值都大的值x被考虑进来时，有三种情况为他添枝加叶。
第一种情况，在其左上方添加。可以添加的数量就是x-1情况下奇异二叉搜索树的数量。
第二种情况，在其左下方添加。可以添加的数量就是x-1情况下奇异二叉搜索树的数量。
第三种情况，同时在其左上方和左下方添加。这涉及将x-1分解为前i位和后x-1-i位。值得注意的是，后x-1-i位对应的组合数数值上等于x-1-i情况下奇异二叉搜索树的值。
得到关系如下。
for (int i = 1; i < n; i++) {
			dp[i] = 2 * dp[i - 1];
			for (int j = 1; j < i; j++) {
				dp[i] += dp[j - 1] * dp[i - j - 1];
			}
		}
    
Code

*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int numTrees(int n) {
		if (n <= 0)return 0;
		int * dp = new int[n];
		dp[0] = 1;
		for (int i = 1; i < n; i++) {
			dp[i] = 0;
		}
		for (int i = 1; i < n; i++) {
			dp[i] = 2 * dp[i - 1];
			for (int j = 1; j < i; j++) {
				dp[i] += dp[j - 1] * dp[i - j - 1];
			}
		}
		return dp[n - 1];
	}
};

//Result

//Accept
