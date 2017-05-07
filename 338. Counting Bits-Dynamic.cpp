/*
Description

Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
Example:
For num = 5 you should return [0,1,1,2,1,2].
Follow up:
It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
Credits:
Special thanks to @ syedee for adding this problem and creating all test cases.
Subscribe to see which companies asked this question.

Ideas

设置初始状态。假设设置为空。那么整个算法就是在这个状态以及之后产生的各种状态前
1.加0
2.加1
从而像二叉树一样不断扩展位数。
每一种新的状态都需要使用上一个状态的信息。
把每种状态对应的1的数量记录在数组中。
由于实际操作难度，初始状态设为0和1，分别处理。

Code

*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int storage[1000000];
class Solution {
private:
	void RAddZero(int Origin, int Ones, int TotalBits) {
		int origin = Origin;
		int ones = Ones;
		int totalBits = TotalBits;
		totalBits++;
		int p = pow(2.0, totalBits*1.0);
		if (storage[p] == -2)return;
		RAddZero(origin, ones, totalBits);
		RAddOne(origin, ones, totalBits);
		return;
	}
	void RAddOne(int Origin, int Ones, int TotalBits) {
		int origin = Origin;
		int ones = Ones;
		int totalBits = TotalBits;
		origin += pow(2.0, totalBits*1.0);
		ones++;
		totalBits++;
		if (storage[origin] == -2)return;
		else if (storage[origin] == -1)storage[origin] = ones;
		RAddZero(origin, ones, totalBits);
		RAddOne(origin, ones, totalBits);
		return;
	}
	void counter() {
		storage[0] = 0;
		storage[1] = 1;
		RAddZero(0, 0, 1);
		RAddOne(0, 0, 1);
		RAddZero(1, 1, 1);
		RAddOne(1, 1, 1);
		return;
	}
public:
	vector<int> countBits(int num) {
		vector<int> result;
		//for an special consequence
		if (!num) {
			result.push_back(0);
			return result;
		}
		//initialize
		for (int i = 0; i <= num; i++)storage[i] = -1;
		for (int i = num + 1; i < 1000000; i++)storage[i] = -2;
		counter();
		for (int i = 0; i <= num; i++)result.push_back(storage[i]);
		return result;
	}
};

//Result
//
//Accept
