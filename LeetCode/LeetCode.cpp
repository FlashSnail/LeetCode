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
	system("pause");
	return 0;
}

