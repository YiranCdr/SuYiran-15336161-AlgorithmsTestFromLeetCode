/*
Descriptions
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie. Each child i has a greed factor gi, which is the minimum size of a cookie that the child will be content with; and each cookie j has a size sj. If sj >= gi, we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.
Note:
You may assume the greed factor is always positive. 
You cannot assign more than one cookie to one child.
Example 1:
Input: [1,2,3], [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.
Example 2:
Input: [1,2], [1,2,3]
Output: 2
Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2.

Ideas
为了达到最优解，让所有尽可能小的饼干满足需求小的孩子。
首先将两个vector从小到大排序，从需求最小的孩子开始访问，在饼干桶中从当前可用的最小饼干开始看，是否满足这个孩子的需求。
若不行，则换一个大一点点的。

Code
*/
//在一开始本想创建一个Strut来标记饼干是否被访问；但是后来在calculate函数中设置unvisitedS从而控制当前可用的最小饼干，因此不需要单独设立数据结构解决。
//calculate1就是struct解决方案，calculate2为简化方案。最后采用calculate2.
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct MyStruct {
	int num;
	bool visited;
	MyStruct(int n = -1, bool v = false) {
		num = n;
		visited = false;
	}
	void visit() {
		visited = true;
	}
	void setNum(int n) {
		num = n;
	}
};

void convert(const vector<int> & v, vector<MyStruct> & s) {
	for (int i = 0; i < v.size(); i++) {
		MyStruct stc(v[i], false);
		s.push_back(stc);
	}
}

void sort(vector<MyStruct> & v) {
	for (int i = 0; i < v.size() - 1; i++) {
		int index = i;
		for (int j = i + 1; j < v.size(); j++) {
			if (v[j].num < v[index].num) {
				index = j;
			}
		}
		MyStruct temp(v[index].num, false);
		v[index].setNum(v[i].num);
		v[i].setNum(temp.num);
	}
}

int calculate1(vector<MyStruct> & g, vector<MyStruct> & s) {
	int unvisitedS = 0;//since this counter, we don't need MyStruct at all;
	int counter = 0;
	const int maxSize = s.size();
	for (int i = 0; i < g.size(); i++) {
		const int content = g[i].num;
		for (unvisitedS; unvisitedS < maxSize; unvisitedS++) {
			if (s[unvisitedS].num >= content) {
				counter++;
				unvisitedS++;
				break;
			}
		}
	}
	return counter;
}

int calculate2(vector<int> & g, vector<int> & s) {
	int unvisitedS = 0;//since this counter, we don't need MyStruct at all;
	int counter = 0;
	const int maxSize = s.size();
	for (int i = 0; i < g.size(); i++) {
		const int content = g[i];
		for (unvisitedS; unvisitedS < maxSize; unvisitedS++) {
			if (s[unvisitedS] >= content) {
				counter++;
				unvisitedS++;
				break;
			}
		}
	}
	return counter;
}

class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		int result = calculate2(g, s);
		return result;
	}
};

//Result
//Accept
