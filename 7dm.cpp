
#include <iostream>
#include <vector>
#include <Windows.h>
#include <cstdlib>
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	vector<int> path;
	int n = 0;
	int p = 3;
	int j = -1;
	int max;
	vector<vector<int> > arr1 = {
  {0,2,3,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0},
  {1,0,3,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0},
  {1,2,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,5,6,0,0,0,10,0,0,0,0,0,0,0,0},
  {0,0,0,4,0,6,0,0,0,10,0,0,0,0,0,0,0,0},
  {1,0,0,4,5,0,7,0,9,10,0,0,0,0,0,0,0,0},
  {0,0,3,0,0,6,0,8,0,0,11,0,0,0,0,0,0,0},
  {0,2,0,0,0,0,7,0,9,0,11,12,0,0,0,0,0,0},
  {0,0,0,0,0,6,0,8,0,10,11,0,0,0,0,0,0,0},
  {0,0,0,4,5,6,0,0,9,0,0,0,0,0,0,0,17,18},
  {0,0,0,0,0,0,7,8,9,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,8,0,0,0,0,13,14,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,12,13,14,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,12,13,0,15,0,17,18},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,14,0,16,17,18},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,17,18},
  {0,0,0,0,5,0,0,0,0,10,0,0,0,14,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,10,0,0,0,14,15,16,0,0},
	};
	vector<int> arr2 = { 4,7,16 };
	vector<int> arr3(18);
	vector<bool> arr4 = { true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true };
	vector<int> arr5;
	vector<int> arr6(18);
	vector<int> arr7;
	int k = 0;
	for (int i = 0; i < 18; i++)
	{
		n = 0;
		for (int t = 0; t < 18; t++)
		{
			if (arr1[i][t] != 0)
			{
				n++;
			}
		}
		arr6[i] = n;
		arr3[i] = n;
	}
	int t = 0;
	n = arr2.size();
	n = 18 / n;
	max = n;
	while (arr5.size() < 18)
	{
		for (int i = arr7.size(); i >0; i--)
		{
			arr7.pop_back();
		}
		j++;
		arr5.push_back(arr2[j]-1);
		t = arr2[j]-1;
		arr4[t] = false;
		for (int i = 0; i < 18; i++)
		{
			arr4[i] = true;
			arr3[i] = arr6[i];
		}
		for (int i = 0; i < arr5.size(); i++)
		{
			arr4[arr5[i]] = false;
		}
		while (arr5.size() < n)
		{
			k = 100;
			for (int i = 0; i < 18; i++)
			{
				if (arr1[t][i] != 0 && arr4[i] == true)
				{
					arr7.push_back(i);
					arr4[i] = false;

				}
			}
			for (int i = 0; i < arr7.size(); i++)
			{
				for (int it = 0; it < 18; it++)
				{
					if (arr1[arr7[i]][it] == t + 1)
					{
						arr3[arr7[i]]--;
					}
				}
			}
   			for (int i = 0; i < arr7.size(); i++)
			{
				if (arr3[arr7[i]] < k)
				{
					k = arr3[arr7[i]];
					t = arr7[i];
					p = i;
				}
			}
			for (int i = p; i < arr7.size() - 1; i++)
			{
				swap(arr7[i], arr7[i + 1]);
			}
			arr5.push_back(t);
			arr7.pop_back();
		}
		n = n + max;
	}
	p = 0;
	n = 0;
	for (int i = 0; i < arr2.size(); i++)
	{
		n = n+max;
		for (int i = p; i < n; i++)
		{
			cout << arr5[i]+1 << " ";
		}
		cout << endl;
		p = p + max;

	}
}

