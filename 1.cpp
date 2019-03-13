
#include <iostream>
using namespace std;


int main()
{
	int amount, number;
	int array[amount];
	cin >> amount;
	int counter = 0;
	

	for (int i = 0; i < amount; i++)
	{
		cin >> array[i];
	}

	cin >> number;

	for (int i = 0; i < amount; i++)
	{
		if (number == array[i])
		{
			counter++;
		}
	}
	cout << counter << endl;
	return 0;
}
