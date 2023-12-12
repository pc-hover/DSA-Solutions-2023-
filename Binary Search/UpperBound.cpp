#include <bits/stdc++.h>
using namespace std;
int upperBound(vector<int> &arr, int x, int n)
{
	int ans = n;
	int low = 0;
	int high = n - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (arr[mid] > x)
		{
			ans = mid;
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return ans;
}
int main()
{
	vector<int> arr = {};
	int x = 3;
	cout << "Upper Bound = " << upperBound(arr, x, arr.size());

	return 0;
}