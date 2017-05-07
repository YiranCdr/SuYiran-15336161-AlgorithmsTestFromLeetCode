/*
Description

A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
For example, these are arithmetic sequence:
1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.
1, 1, 2, 5, 7
A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.
A slice (P, Q) of array A is called arithmetic if the sequence:
A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.
The function should return the number of arithmetic slices in the array A.
Example:
A = [1, 2, 3, 4]
return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
Subscribe to see which companies asked this question.

Ideas

设一个和A相同大小的数组X，X[i]的含义是以A中第i个元素结尾的Arithmetic Slices有多少。
若A[i-1]前已经有差值是d的Arithmetic Slices，且A[i]-A[i-1]=d，那么X[i]=X[i-1]+1.因为后一个比前一个多一个可用的元素，因此比前一个多一个组合。

Code

*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		if (A.size() < 3)return 0;
		int size = A.size();
		int * myArray = new int[size];
		for (int i = 0; i < size; i++)myArray[i] = 0;
		if (A[2] - A[1] == A[1] - A[0])myArray[2] = 1;
		int result = myArray[2];
		for (int i = 3; i < size; i++) {
			if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])myArray[i] = 1 + myArray[i - 1];
			result += myArray[i];
		}
		return result;
	}
};

//Result
//
//Accept
