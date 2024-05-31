// https://www.naukri.com/code360/problems/k-th-largest-sum-contiguous-subarray_920398
#include <bits/stdc++.h>
using namespace std;
/*
Approach-1
int getKthLargest(vector<int> &arr, int k)
{
	vector<int> sumArr;
	int n = arr.size();
	for(int i = 0; i < n; i++){
		int sum = 0;
		for(int j = i; j < n; j++){
			sum += arr[j];
			sumArr.push_back(sum);
		}
	}
	sort(sumArr.begin(), sumArr.end());
	return sumArr[sumArr.size() - k];
}


TC = O(n^2 logn)
SC = O(n^2)
*/

int getKthLargest(vector<int> &arr, int k)
{
	priority_queue<int, vector<int>, greater<int>> minHeap;
	int n = arr.size();
	for(int i = 0; i < n; i++){
		int sum = 0;
		for(int j = i; j < n; j++){
			sum += arr[j];
			if(minHeap.size() < k)	minHeap.push(sum);
			else{
				if(minHeap.top() < sum){
					minHeap.pop();
					minHeap.push(sum);
				}
			}
		}
	}
	return minHeap.top();
}
// TC = O(n^2 logk)
// SC = O(k)