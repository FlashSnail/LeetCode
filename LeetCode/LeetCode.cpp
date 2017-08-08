// LeetCode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
class Solution {
public:
	struct TreeNode {
		TreeNode* left; 
		TreeNode* right;
		int val;
	};
	/*2、Evaluate the value of an arithmetic expression in Reverse Polish Notation.
	Valid operators are+,-,*,/. Each operand may be an integer or another expression.
	Some examples:
	  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
	  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6*/
	int evalRPN(vector<string> &tokens) {
		//逢树压栈，遇到预算符计算取栈中元素计算，然后结果压栈，继续进行
		stack<int> s;
		for (int i = 0; i < tokens.size(); i++) {
			if (isNum(tokens[i])) {
				//结果返回是int，所以就atoi了
				s.push(atoi(tokens[i].c_str()));
			}
			else {
				if (tokens[i] == "+") {
					int b = s.top();	s.pop();
					int a = s.top();	s.pop();
					s.push(a + b);
				}
				else if (tokens[i] == "-") {
					int b = s.top();	s.pop();
					int a = s.top();	s.pop();
					s.push(a - b);
				}
				else if (tokens[i] == "*") {
					int b = s.top();	s.pop();
					int a = s.top();	s.pop();
					s.push(a * b);
				}
				else if (tokens[i] == "/") {
					int b = s.top();	s.pop();					
					int a = s.top();	s.pop();
					s.push(a / b);
				}
				else {
					return -1;	//如果碰到了不是数字和运算符的符号，这个题目没说，我就直接返回-1了
				}
			}
		}
		return s.top();
	}
	bool isNum(string str) {
		for (int i = 0; i < str.length(); i++) {
			if (str[0] == '-' && str.length() > 1) {
				continue;
			}
			if (str[i] < '0' || str[i] > '9') {
				return false;
			}
		}
		return true;
	}
	/*1.Given a binary tree, find its minimum depth.The minimum depth is the number of nodes
	along the shortest path from the root node down to the nearest leaf node.*/
	int run(TreeNode *root) {
		if (root == NULL) {
			return 0;
		}
		int left = run(root->left);
		int right = run(root->right);
		if (left == 0 || right == 0) {
			return 1 + left + right;
		}
		return min(left, right) + 1;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution test;
	vector<string> s{ "4", "13", "5", "/", "+" };
	cout << test.evalRPN(s) << endl;
	system("pause");
	return 0;
}

