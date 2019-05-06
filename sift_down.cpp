#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int siftDown(vector<int>& heap, int m) {
	while (m * 2 < heap.size()) {
		int maxNode = m * 2;
		if ((m * 2 + 1 < heap.size()) && (heap[m * 2 + 1] > heap[m * 2])) {
			maxNode = m * 2 + 1;
		}
		if (heap[maxNode] > heap[m]) {
			swap(heap[m], heap[maxNode]);
			m = maxNode;
		} else {
			break;
		}
	}
	return m;
}

int main(){
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
    	heap[el] -= num;
    	cout << siftDown(heap, el) << endl;
	}
	for (int i = 1; i <= size; ++i) {
		if (i > 1) {
			cout << " ";
		}
        cout << heap[i];
    }
    cout << endl;
	
}
