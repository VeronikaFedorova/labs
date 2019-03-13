#include <iostream>
#include "vector"

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int max, temp;
	for (int i = n - 1; i >= 0; i--)
  {
    max = i;
    for(int j = i; j >= 0; j--)
    {

        if(arr[max] < arr[j])
        {
          max = j;
        }
    }
    swap(arr[i], arr[max]);
  }
	for(int i = 0; i < n; i++)
	{
	    cout << arr[i] << " ";
	}
	return 0;
}
