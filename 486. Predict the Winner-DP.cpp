/*
Description

Given an array of scores that are non-negative integers. Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on. Each time a player picks a number, that number will not be available for the next player. This continues until all the scores have been chosen. The player with the maximum score wins.
Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score.
Example 1:
Input: [1, 5, 2]
Output: False
Explanation: Initially, player 1 can choose between 1 and 2.
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2).
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5.
Hence, player 1 will never be the winner and you need to return False.
Example 2:
Input: [1, 5, 233, 7]
Output: True
Explanation: Player 1 first chooses 1. Then player 2 have to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.
Note:
1 <= length of the array <= 20.
Any scores in the given array are non-negative integers and will not exceed 10,000,000.
If the scores of both players are equal, then player 1 is still the winner.

Ideas

myArray[i][j]定义为在第i个值到第j个值player1的最优解减player2的最优解的差值。
由于二者都尽可能达到最优解，于是对于myArray[i-1][j]，player1若取nums[i-1],则myArray[i][j]此时将等同于player2的最优解减player1的最优解的差值.对于myArray[i][j+1]，相比于nums[j+1]也是这样。
此时，需要考虑的就是player1对于所选字段的第一个值或者最后一个值的选取是否能够大于player2此时获得的优势。
可知，myArray[j][j + i] = max(nums[j] - myArray[j + 1][j + i], nums[j + i] - myArray[j][j + i - 1]);
若myArray[0][nums.size()]>=0，则说明player1仍有优势。

Code

*/
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		if (nums.size() == 1)return true;
		//initial
		int nSize = nums.size();
		int ** myArray = new int*[nSize];
		for (int i = 0; i < nSize; i++) {
			myArray[i] = new int[nSize];
			for (int j = 0; j < nSize; j++) {
				myArray[i][j] = 0;
				if (j == i) myArray[j][j] = nums[i];
			}
		}
		//DP
		for (int i = 1; i < nSize; i++) {
			for (int j = 0; j + i < nSize; j++) {
				myArray[j][j + i] = max(nums[j] - myArray[j + 1][j + i], nums[j + i] - myArray[j][j + i - 1]);
			}
		}
		if (myArray[0][nSize - 1] >= 0)return true;
		else return false;
	}
};

//Result
//
//Accept
