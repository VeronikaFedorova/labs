#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;


int part(vector<int> &data, int left, int right)
{

    int pivot = data[left];
    int i = left - 1, j = right + 1;

    while (true)
    {

        do
        {
            i++;
        } while (data[i] < pivot);

        do
        {
            j--;
        } while (data[j] > pivot);

        if (i >= j)
        {

            return j;
        }

        swap(data[i], data[j]);
    }
}
int part_random(vector<int> &data, int left, int right)
{

    int random = left + rand() % (right - left);

    swap(data[random], data[left]);

    return part(data, left, right);
}


void quickSort(vector<int> &data, int left, int right)
{
    if (left < right)
    {

        int pivot = part_random(data, left, right);

        quickSort(data, left, pivot);
        quickSort(data, pivot + 1, right);
    }
}
int main(){
	int size;
	cin >> size;

	vector<int> data(size);
	for(int i = 0; i < data.size(); i++){
		cin >> data[i];
	}

	quickSort(data, 0, size - 1);

    for (int i = 0; i < data.size(); i++){
	        printf("%d ", data[i]);
	}

    return 0;
}
