//14719
//@Reference hwan-shell <https://hwan-shell.tistory.com/276> 
#include<iostream>
#include<vector>

#define MAX 501

using namespace std;

int N, M, answer = 0;
int main() {
    cin >> N >> M;
    vector<int> walls(M);

    for (int i = 0; i < M; i++)
        cin >> walls[i];

    for (int i = 1; i < M - 1; i++) {
        int left = 0; int right = 0;
        for (int j = 0; j < i; j++) left = max(left, walls[j]);
        for (int j = M - 1; j > i; j--) right = max(right, walls[j]);
        answer += max(0, min(left, right) - walls[i]);
    }

    cout << answer << endl;
    return 0;
}
 

// int n, m, result = 0;
// int start = -1, endPoint = -1;
// int walls[MAX];
// queue<pair<int, int>> cache;
// // priority_queue<pair<int, int>, vector<pair<int,int>> > cache;
// // vector<pair<int, int>> cache;
// bool desc(pair<int, int> a)
// {
// 	return a.first > a.second;
// }
// void solution()
// {
// 	// cache.push(make_pair(start, 0));
// 	for(int i = start+1; i < m; i++)
// 	{
// 		if(walls[start] > walls[i])
// 		{
// 			endPoint = walls[i] > walls[endPoint] ? i : endPoint;
// 		}
// 		else if (walls[start] <= walls[i] || i == m -1)
// 		{
// 			endPoint = walls[i] > walls[endPoint] ? i : endPoint;
// 			cache.push(make_pair(start, endPoint));
// 			start = i;
// 			endPoint = -1;
// 		}
// 	}

	// for(int i = start+1; i < m; i++)
	// {	
	// 	int back = i;
	// 	if(walls[cache.top().first] > walls[i])
	// 	{
	// 		cache.pop();
	// 		cache.push(make_pair(start, i));
	// 	}
	// 	else{
	// 		cache.pop();
	// 		cache.push(make_pair(start, i));
	// 		cache.push(make_pair(i, 0));
	// 		start = i;
	// 	}
	// }

// 	int s_value, e_value;

// 	while(!cache.empty())
// 	{
// 		s_value = cache.front().first;
// 		e_value = cache.front().second;
// 		cache.pop();

// 		cout << s_value <<" / " << e_value << endl;

// 		if(e_value)
// 		{
// 			int via =  walls[s_value] > walls[e_value]? walls[e_value] : walls[s_value];
// 			for(int i = s_value+1; i < e_value; i++)
// 				result += (via-walls[i]);
// 		}
// 	}
// }
// int main()
// {
// 	cin >> n >> m;

// 	for(int i = 0; i < m; i++){
// 		cin >> walls[i];
// 		if(start < 0 && walls[i]) start = i;
// 	}

// 	solution();

// 	cout << result << endl;
// 	return 0;
// }