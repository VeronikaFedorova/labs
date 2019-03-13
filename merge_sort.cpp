#include <iostream>
#include "vector"

using namespace std;

void merge_sort(vector<int> &n, int l, int r);
int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	merge_sort(arr, 0, arr.size());
	cout << arr[n] << " ";
	system("pause");
	return 0;
}

void merge_sort(vector<int> &n, int l, int r)
{
	if(l == r)
	{
		return;
	}
	int m = (l + r)/2;
	merge_sort(n, l, m);
	merge_sort(n, m + 1, r);
	int ptr1 = l;
	int ptr2 = m + 1;
	vector<int> result;
	for(int i = 0; i < r - l + 1; ++i)
	{
		if((ptr1 <= m) && (ptr2 > r) || (n[ptr1] < n[ptr2]))
		{
			result.push_back(n[ptr1]);
			ptr1++;
		}
		else
		{
			result.push_back(n[ptr2]);
			ptr2++;
		}
		for(int i = 0; i < result.size(); ++i)
		{
			n[i + l] = result[i];
		}
	}
}










