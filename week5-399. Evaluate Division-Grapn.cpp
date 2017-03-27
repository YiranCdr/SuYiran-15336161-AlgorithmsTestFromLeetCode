/*
Description
Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0. 
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.

Ideas
create a graph to express the relationship of each variables.

Code
*/

#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

struct Node {
	string origin;
	double value;
	Node* next;
	Node* nextH;
	bool visited;
	Node(string o = "0000000000000000000", double v = 1.0, Node* n = NULL, bool visi = false, Node* nh = NULL ) {
		origin = o;
		value = v;
		next = n;
		visited = visi;
		nextH = nh;
	}
};

class Tree {
private:
	Node* head;
	Node* tail;
	stack<Node*> stk;
	stack<double> values;
public:
	Tree(Node * p);
	Node* findNode(string c);
	void add(string c1,string c2,double v);
	double dfs(string c1,string c2);
	void rDfs(Node* p, string c);
	void clearStks();
	void clearVisited();
};

Tree::Tree(Node* p = NULL) {
	head = p;
	tail = head;
}

Node* Tree::findNode(string c) {
	Node* pointer = head;
	while (pointer != NULL) {
		if (pointer->origin == c) {
			return pointer;
		}
		else {
			pointer = pointer->nextH;
		}
	}
	return pointer;
}

void Tree::add(string c1,string c2, double v) {
	Node * p1 = findNode(c1);
	Node* p2 = findNode(c2);
	if (p1 == NULL) {
		Node* n1 = new Node(c1);
		if (tail != NULL) {
			tail->nextH = n1;
			tail = tail->nextH;
		}
		else {
			head = n1;
			tail = n1;
		}
		Node* n2 = new Node(c2, v);
		n1->next = n2;
	}
	else {
		while (p1 != NULL) {
			if (p1->origin == c2) {
				break;
			}
			else {
				p1 = p1->next;
			}
		}
		if (p1 == NULL) {
			Node* n2 = new Node(c2, v);
			p1 = n2;
		}
	}
}

void Tree::rDfs(Node* p, string c) {
	//stk.push(p);
	//value *= p->value;
	//p->visited = true;
	if (p->origin == c) {
		values.push(1.0);
		return;
	}
	//else {
		//if(p->next == NULL) {
		//	value = value / temp;
		//	stk.pop();
		//	rDfs(stk.top(), c, value, temp);
		//	return;
		//}
		else {
			while (p->next != NULL && p->next->visited == true) {
				p = p->next;
			}
			if (p->next == NULL) {
				values.pop();
				stk.pop();
				if (stk.empty())return;
				rDfs(stk.top(), c);
				//delet 2
				return;
			}
			else if (p->next->visited == false) {
				if (p->next->origin == c) {//last step
					values.push(p->next->value);
					return;
				}
				Node* pointer = findNode(p->next->origin);
				while (pointer == NULL) {
					if (p->next->origin == c) {
						values.push(p->next->value);
						return;
					}
					if (p->next->next != NULL) {
						p->next->visited = true;
						p = p->next;
						pointer = findNode(p->next->origin);
					}
					else {
						values.pop();
						stk.pop();
						if (stk.empty())return;
						rDfs(stk.top(), c);
						return;
					}
				}
				values.push(p->next->value);
				p->next->visited = true;
				stk.push(pointer);
				rDfs(pointer, c);
				//p->next->visited = true;
				return;
			}
		}
	//}
	return;
}

double Tree::dfs(string c1, string c2) {
	Node* p1 = findNode(c1);
	double result = 1.0;
	if (p1 == NULL)return -1.0;
	else {
		stk.push(p1);
		rDfs(p1, c2);
		if (values.empty())return -1.0;
		else {
			while (values.empty() == false) {
				result *= values.top();
				values.pop();
			}
		}
	}
	return result;
}

void Tree::clearStks() {
	while (!stk.empty())stk.pop();
	while (!values.empty())values.pop();
}

void Tree::clearVisited() {
	Node* p = head;
	while (p != NULL) {
		Node* q = p;
		while (q != NULL) {
			q->visited = false;
			q = q->next;
		}
		p = p->nextH;
	}
}

void function(vector<pair<string,string>> & equations,vector<double> & vs,vector<pair<string,string>> & queries, vector<double> & results) {
	Tree tree;
	while (!equations.empty()) {
		pair<string, string> eqt = equations.back();
		equations.pop_back();
		double v = vs.back();
		vs.pop_back();
		string parent = eqt.first;
		string child = eqt.second;
		tree.add(parent, child, v);
	}
	for (int i = 0; i < queries.size(); i++) {
		double f = tree.dfs(queries[i].first, queries[i].second);
		tree.clearStks();
		tree.clearVisited();
		double s = tree.dfs(queries[i].second, queries[i].first);
		tree.clearStks();
		tree.clearVisited();
		if (f == -1.0) {
			if (s == -1.0) {
				results.push_back(-1.0);
			}
			else results.push_back(1 / s);
		}
		else results.push_back(f);
		tree.clearStks();
		tree.clearVisited();
	}
}


/*
Result
Accpt
*/
