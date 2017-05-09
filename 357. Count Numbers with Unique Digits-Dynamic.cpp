/*
Description

Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.
Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])
Credits:
Special thanks to @memoryless for adding this problem and creating all test cases.
Subscribe to see which companies asked this question.
Show Tags

Ideas

n==0,n==1为特殊情况，单独考虑。
其他情况下，对于第i位，可能产生的数量是i-1位所产生的数量*(10-(i-1)).得到方程。
由此知动态规划可解。

Code

*/

#include<iostream>
using namespace std;

class Solution {
private:
	int addBit(int x) {
		return (10 - (x - 1));
	}
public:
	int countNumbersWithUniqueDigits(int n) {
		if (n == 0)return 1;
		if (n == 1)return 10;
		int result = 10;
		int lastBit = 9;
		for (int i = 2; i <= n; i++) {
			result += lastBit*addBit(i);
			lastBit *= addBit(i);
		}
		return result;
	}
};

//Result
//
//Accept
