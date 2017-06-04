/*
Description

Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.
Example 1:
Input:
"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
Example 2:
Input:
"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".

Ideas

if (s[left] == s[right]) {
	else p[left][right] = max(p[left + 1][right - 1] + 2, max(p[left + 1][right], p[left][right - 1]));
}
else {
	else p[left][right]= max(p[left + 1][right - 1], max(p[left + 1][right], p[left][right - 1]));
}
循环的依据是截取长度从0到s.length().

Code

*/
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
	int longestPalindromeSubseq(string s) {
		int Size = s.size();  
		if (Size == 0)return 0;
		int ** p = new int *[Size];
		for (int i = 0; i < Size; i++) {
			p[i] = new int[Size];   
			for (int j = 0; j < Size; j++)p[i][j] = 0;
			p[i][i] = 1;
		}
		for (int length = 2; length <= Size; length++) {
			for (int left = 0; left + length <= Size; left++) {
				int right = left + length - 1;
				if (s[left] == s[right]) {
					if (length == 2)p[left][right] = 2;
					else p[left][right] = max(p[left + 1][right - 1] + 2, max(p[left + 1][right], p[left][right - 1]));
				}
				else {
					if(length==2)p[left][right] = 1;
					else p[left][right]= max(p[left + 1][right - 1], max(p[left + 1][right], p[left][right - 1]));
				}
			}
		}
		return p[0][Size - 1];
	}
};
int main() {
	Solution a, b, c, d, e;
	int r = a.longestPalindromeSubseq("a");
	cout << r << endl;
	r = b.longestPalindromeSubseq("abcabcabcabc");
	cout << r << endl;
	r = c.longestPalindromeSubseq("bbbab");
	cout << r << endl;
	r = d.longestPalindromeSubseq("cbbd");
	cout << r << endl;
	r = e.longestPalindromeSubseq("aabaa");
	cout << r << endl;
	system("pause");
	return 0;
}

//Result
//
//Accept
