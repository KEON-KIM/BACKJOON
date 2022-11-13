// #1092
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define MAX 51

using namespace std;
int N, M, crane[MAX], boxes[MAX], result = -1, key = 0;
bool flag = false;
vector<int> contain[MAX];

int main()
{
	int input;
	queue<int> Que;

	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> crane[i];
	sort(crane, crane+N);

	cin >> M;
	for(int i = 0; i < M; i++)
		cin >> boxes[i];
	sort(boxes,boxes+M);

	if(boxes[M-1] > crane[N-1]) {
		cout << -1 << endl;
		return 0;
	}

	for(int i = 0; i < M; i++){
		
	}
	
	cout << result << endl;
	// while(cnt < N){
	// 		key = key%N;
	// 		if(crane[key] >= obj) {
	// 			cout << "crane weight : " << crane[key] << " OBJECT : " << obj << endl;
	// 			contain[key].push_back(obj);
	// 			int size = contain[key].size();
	// 			result = max(result, size);
	// 			key++;
	// 			break;
	// 		}
	// 		key ++;
	// 		cnt ++;
	// 	}
	// for(int i = 0; i < N; i++)
	// 	cout << crain[i] << " ";
	// cout << endl;
	return 0;
}