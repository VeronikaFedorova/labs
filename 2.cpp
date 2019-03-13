#include <iostream>
#include "vector"


using namespace std;

int binary_search(vector<int> &data, int key);

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> data(n);
    vector<int> search(k);

    for (int i = 0; i < data.size(); i++)
    {
        cin >> data[i];
    }
    for (int j = 0; j < search.size(); j++)
    {
        cin >> search[j];
    }

    for (int i = 0; i < search.size(); i++)
    {
        if (binary_search(data, search[i]) != -3) 
		{
            cout << "YES" << endl;
        } else
        {
            cout << "NO" << endl;
        }
        
    }
    

    return 0;
}

int binary_search(vector<int> &data, int key)
{
    int left = 0;            
    int right = data.size() - 1;    
 
    while (left <= right) 
    {
 
        int middle = (left + right) / 2;
 
        if (data[middle] == key) 
        {
        	return middle;
		}
        if (data[middle] < key)
		{
			left = middle + 1;
		} 
        if (data[middle] > key)
        {
        	right = middle - 1;
		}
		
    }
 
  return -3;
}
