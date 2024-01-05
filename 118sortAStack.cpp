// https://www.codingninjas.com/studio/problems/sort-a-stack_985275?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>
using namespace std;

// sorting a stack in decreasing order

void sortedInsert(stack<int> &stack, int num){
	if(stack.empty() || (!stack.empty() && stack.top() < num)){
		stack.push(num);
		return;
	}

	// storing top element and popping it
	int n = stack.top();
	stack.pop();

	// recursive call
	sortedInsert(stack, num);

	// pushing element back
	stack.push(n);
}
void sortStack(stack<int> &stack)
{
	// base case
	if(stack.empty())	return;

	int num = stack.top();
	stack.pop();
	
	// recursive call
	sortStack(stack);

	// sorted insert
	sortedInsert(stack, num);
}