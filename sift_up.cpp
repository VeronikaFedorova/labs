#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int sift_up(int size, vector<int>& heap) {

    while ((size > 1) && (heap[size / 2] < heap[size])) {
        swap(heap[size], heap[size / 2]);
        size /= 2;
    }
	return size; 
}

int main() {
	int size;
	cin >> size;
	vector<int> heap(size + 1);
    for (int i = 0; i < size; ++i) {
        scanf("%d", &heap[i + 1]);
    }
    int amount;
    cin >> amount;
    for(int i = 0; i < amount; i++){
    	int el;
    	cin >> el;
    	int num;
    	cin >> num;
    	heap[el] += num;
    	cout << sift_up(el, heap) << endl;
	}
	for (int i = 1; i <= size; ++i) {
		if (i > 1) {
			cout << " ";
		}
        cout << heap[i];
    }
    cout << endl;
}
