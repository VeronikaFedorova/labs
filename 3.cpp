#include <iostream>
#include "vector"

using namespace std;

int binary_search(vector<int> &arr, int key);
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    vector<int> array(k);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int j = 0; j < k; j++)
    {
        cin >> array[j];
    }
    for (int i = 0; i < array.size(); i++)
    {
        binary_search(arr, array[i]);
    }
    return 0;
}

int binary_search(vector<int> &arr, int key)
{
    int left = 0, right = arr.size() - 1;
    int res_l = -1, res_r;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (arr[middle] == key)
        {
            res_l = middle;
            right = middle - 1;
        }
        else if (arr[middle] < key)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }

    if (res_l == -1)
    {
        printf("0\n");
        return 0;
    }

    left = 0;
    right = arr.size() - 1;
    while (left <= right)
    {

        int middle = (left + right) / 2;

        if (arr[middle] == key)
        {

            res_r = middle;
            left = middle + 1;
        }
        else if (arr[middle] < key)
        {

            left = middle + 1;
        }
        else
        {

            right = middle - 1;
        }
    }

    printf("%d %d\n", ++res_l, ++res_r);
    return 0;
}

