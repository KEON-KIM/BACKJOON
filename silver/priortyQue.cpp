#include <iostream>
#define MAX_SIZE 100001

using namespace std;
int n;


void swap(int &a, int &b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

struct priortyQue
{
	int board[MAX_SIZE] = {'\0', };
	int size = 1;

	void push(int input)
	{
		
		int parent_idx = size/2;
		int cusor = size;
		board[cusor] = input;
		
		while(parent_idx)
		{
			if(board[parent_idx] < board[cusor]){
				swap(board[parent_idx], board[cusor]);
				cusor = parent_idx;
			}
			parent_idx /= 2;
		}
		size++;
	}

	void pop()
	{
		if (size == 1) return;
		int root = 1;
		int cusor = size-1;
		int child_idx = root*2;
		cout << "POP : " << board[root] << endl;
		board[root] = board[cusor];
		board[cusor] = '\0';
		int tmp_index = root;
		//heapify
		while(child_idx < size && board[tmp_index] < board[child_idx])
		{
			if(board[child_idx] > board[child_idx+1]){
				swap(board[tmp_index], board[child_idx]);
				tmp_index = child_idx;
			}
			else if(board[child_idx+1] > board[child_idx]){
				swap(board[tmp_index], board[child_idx+1]);
				tmp_index = child_idx+1;
			}
		
			child_idx *= 2;
		}

		size --;
	}

	void print()
	{
		cout << "SIZE : " << size-1 << endl;
		for(int i = 1; i < size; i++)
			cout << board[i] << " ";
		cout << endl;
	}

};

int main()
{
	// cin >> n;
	priortyQue PQ = priortyQue();
	PQ.push(1);
	PQ.push(2);
	PQ.push(-1);
	PQ.push(33);
	PQ.push(23);
	PQ.push(-21);
	PQ.print();
	PQ.pop();
	PQ.pop();
	PQ.pop();
	PQ.push(0);
	// PQ.print();
	PQ.pop();
	PQ.print();
	PQ.pop();
	PQ.pop();
	PQ.pop();
	return 0;
}