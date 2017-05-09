/*
Description

Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.
For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
Note: You may assume that n is not less than 2 and not larger than 58.

Idea

采用动态规划思路解决。
设立一个数组array,array[i]即是n==i时integerBreak的值。
将array[i]看作是两个值(i-j)*j的结果。其中j<i。
认为(i-j)有两种情况，一种是其本身就是其本身，另一种是(i-j)是其他数值相乘的结果，也就是array[i-j].取这两种情况的最大值。
对于每一个i，j都有多种情况可以尝试。都可能更新array[i].上一步新产生的数值和当前可取的最大值，也就是当前array[i]对比。取二者的最大值。

Code

*/
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution {
public:
	int integerBreak(int n) {
		int * myArray = new int[n + 1];
		for (int i = 0; i < n + 1; i++)myArray[i] = 1;
		myArray[2] = 1;
		if (n == 2)return 1;
		for (int i = 3; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				myArray[i] = max(myArray[i], max(j*(i - j), j*myArray[i - j]));
			}
		}
		return myArray[n];
	}
};

//Result
//
//Accept
