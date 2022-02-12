#include <iostream>
using namespace std;

#define HEAP_SIZE 256
#define ARRAY_SIZE 10

struct Heap{
	bool isDesc = false;
	int heap[HEAP_SIZE];
	int heap_count = 0;

	void swap(int* a, int* b) {
		int tmp = *a; *a = *b; *b = tmp;
	}

	void init() {
		heap_count = 0;
	}

	int size() {
		return heap_count;
	}

	void push(int data) {
		heap[++heap_count] = data;

		int child = heap_count;
		int parent = child / 2;
		if(isDesc)
		{
			while (child > 1 && heap[parent] < heap[child]) 
			{
				swap(&heap[parent], &heap[child]);
				child = parent;
				parent = child / 2;
			}
		}
		else
		{
			while (child > 1 && heap[parent] > heap[child]) 
			{
				swap(&heap[parent], &heap[child]);
				child = parent;
				parent = child / 2;
			}
		}	
	}

	int pop() {
		int result = heap[1];
		swap(&heap[1], &heap[heap_count]);
		heap_count--;

		int parent = 1;
		int child = parent * 2;
		if(isDesc)
		{
			if (child + 1 <= heap_count) {
				child = (heap[child] > heap[child + 1]) ? child : child + 1;
			}

			while (child <= heap_count && heap[parent] < heap[child]) {
				swap(&heap[parent], &heap[child]);

				parent = child;
				child = child * 2;
				if (child + 1 <= heap_count) {
					child = (heap[child] > heap[child + 1]) ? child : child + 1;
				}
			}
		}
		else
		{
			if (child + 1 <= heap_count) {
				child = (heap[child] < heap[child + 1]) ? child : child + 1;
			}

			while (child <= heap_count && heap[parent] > heap[child]) {
				swap(&heap[parent], &heap[child]);

				parent = child;
				child = child * 2;
				if (child + 1 <= heap_count) {
					child = (heap[child] < heap[child + 1]) ? child : child + 1;
				}
			}
		}
		return result;
	}

	int top()
	{
		return heap[1];
	}

	Heap(bool isdesc)
	{
		isDesc = isdesc;
	}
};

int main() {
	Heap ascHeap = Heap(false);
	Heap descHeap = Heap(true);
	ascHeap.push(1);
	ascHeap.push(2);
	ascHeap.push(3);
	ascHeap.push(4);
	ascHeap.push(5);
	ascHeap.pop();

	descHeap.push(1);
	descHeap.push(2);
	descHeap.push(3);
	descHeap.push(4);
	descHeap.push(5);
	descHeap.pop();
	descHeap.pop();

	cout << ascHeap.top() << endl;
	cout << descHeap.top() << endl;

	return 0;
}