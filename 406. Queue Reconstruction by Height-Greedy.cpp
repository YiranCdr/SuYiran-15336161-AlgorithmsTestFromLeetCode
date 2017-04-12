//Description
/*
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.
Note:
The number of people is less than 1,100.
Example
Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/

//Ideas
/*
找出最高的几个人，按前方人数从小到大排列；
再找出最高的几个人，插入上一个，可以做到当前前面的人数就是结果需要的人数。
重复以上步骤。每一步都能做到题目要求。
*/

//Code
struct Elem {
	int height;
	int previous;
	bool visited;
	Elem(int h, int p, bool v = false) {
		height = h;
		previous = p;
		visited = v;
	}
	Elem(const Elem & e) {
		height = e.height;
		previous = e.previous;
		visited = e.visited;
	}
	void visit() {
		visited = true;
	}
};
class Solution {
public:
    void sort(vector<Elem>& v) {
		int min;
		for (int i = 0; i < v.size()-1; i++) {
			min = i;
			for (int j = i+1; j < v.size(); j++) {
				if (v[min].previous > v[j].previous)min = j;
			}
			Elem temp = v[i];
			v[i] = v[min];
			v[min] = temp;
		}
	}
	vector<Elem>FindMax(vector<Elem>& v) {
		vector<Elem> result;
		vector<int> index;
		int x = 0;
		while (x < v.size() && v[x].visited == true)x++;
		if (x == v.size()) {
			Elem e(0, 2000, true);
			result.push_back(e);
			return result;
		}
		Elem e = v[x];
		for (int i = 0; i < v.size(); i++) {
			if (e.height < v[i].height && v[i].visited == false)e = v[i];
		}
		int h = e.height;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].height == h) {
				v[i].visited = true;
				result.push_back(v[i]);
			}
		}
		sort(result);
		return result;
	}
	bool insert(vector<Elem>& result,vector<Elem>& v) {
		if (v[0].previous > 1100)return false;
		else {
			for (int i = 0; i < v.size(); i++) {
				int pre = v[i].previous;
				int lastIdx = result.size();
				result.push_back(v[i]);
				for (int j = result.size()-1; j > pre; j--)result[j] = result[j - 1];
				result[pre] = v[i];
			}
			return true;
		}
	}
	vector<Elem>trans1(vector<pair<int, int>> & v) {
		vector<Elem> result;
		for (int i = 0; i < v.size(); i++) {
			Elem e(v[i].first, v[i].second, false);
			result.push_back(e);
		}
		return result;
	}
	vector<pair<int, int>> trans2(vector<Elem>&v) {
		vector<pair<int, int>> result;
		for (int i = 0; i < v.size(); i++) {
			result.push_back(make_pair(v[i].height, v[i].previous));
		}
		return result;
	}
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
		vector<Elem> es = trans1(people);
		vector<Elem> eResult;
		vector<Elem> es1 = FindMax(es);
		while (insert(eResult,es1)) {
			es1 = FindMax(es);
		}
		vector<pair<int, int>> result = trans2(eResult);
		return result;
	}
};

//Result
/*
  Accept
*/
