/*
377. Combination Sum IV

Description

Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.
Example:
nums = [1, 2, 3]
target = 4
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
Therefore the output is 7.
Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?

Ideas

myArray[volume + 1][temp + sofar] += myArray[volume][sofar];

Code
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		if (nums.size() == 0)return 0;
		int min = 0;
		int max = nums[0];
		for (int i = 0; i < nums.size(); i++) {
			if (min > nums[i])min = nums[i];
			if (max < nums[i])max = nums[i];
		}
		if (target == 1) {
			if (min == 1)return 1;
			else return 0;
		}
		int **myArray = new int *[target + 1];//volume
		for (int i = 0; i <= target; i++) {
			myArray[i] = new int[target + 1];//sofar
			for (int j = 0; j <= target; j++)myArray[i][j] = 0;
		}
		for (int i = 0; i < nums.size() && i <= target; i++)
			myArray[1][nums[i]] = 1;
		for (int volume = 1; volume < target; volume++) {
			for (int sofar = 1; sofar < target; sofar++) {
				if (myArray[volume][sofar] != 0 && sofar + min <= target) {
					for (int i = 0; i < nums.size(); i++) {
						int temp = nums[i];
						if (temp + sofar <= target)
							myArray[volume + 1][temp + sofar] += myArray[volume][sofar];
					}
				}
			}
		}
		int sum = 0;
		for (int volume = 1; volume <= target; volume++) {
			sum += myArray[volume][target];
		}
		return sum;
	}
};
int main() {
	Solution a;
	vector<int> nums;
	int n;
	cout << "Size: ";
	cin >> n;
	cout << "Elements: ";
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		nums.push_back(x);
	}
	int target;
	cout << "Target: ";
	cin >> target;
	int output = a.combinationSum4(nums, target);
	cout <<"Result: "<< output << endl;
	system("pause");
	return 0;
}
