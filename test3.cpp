#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

void printmat(int** mat, int height, int width)
{
	for(int h = 0; h < height; h++)
	{
		cout << "|";
		for(int w = 0; w < width; w++)
		{
			cout << mat[h][w] << "|";
		}
		cout << endl;
	}
	cout << endl;
}

// int solution(int** mat, vector<int> goal)
// {
// 	int count = 0;
// 	int answer = 0;
// 	vector<int> cursor = {1,1};
// 	queu<vector<int>> history;


// 	return answer;
// }
int** initiated(int N, int M)
{
	int** mat = 0;
	string line;

	mat = new int*[N];
	for(int h = 0; h < N; h++)
	{
		mat[h] = new int[M];
		cin >> line;
		for(int w = 0; w < M; w++)
			mat[h][w] = line[w] - '0';
	}

	return mat;
}

int** init(int N, int M)
{
	int** mat = 0;

	mat = new int*[N];
	for(int h = 0; h < N; h++)
	{
		mat[h] = new int[M];
		for(int w = 0; w < M; w++)
			mat[h][w] = 0;
	}

	// cout << "length : " << sizeof()<< endl;
	return mat;
}

int main()
{
	int N, M;
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};


	cin >> N >>M;

	// int visit[N][M] = {{0,},};
	// int visit[N+1][M+1];
	int** visit = init(N,M);
	int** mat = initiated(N, M);

	queue<pair<int,int>> que;
	que.push(make_pair(0,0));

	visit[0][0] = 1;
	while(!que.empty())
	{
		auto node = que.front();
		que.pop();

		if(node.first == N-1 && node.second == M -1 )
		{
			cout << "fuck" << endl;
			break;
		}
		for(int i = 0; i < 4; i++ )
		{
			int next_x = node.second + dx[i];
			int next_y = node.first + dy[i];
			if(next_x >= 0 && next_x < M && next_y >= 0 && next_y < N)
			{
				// cout << "MAT : "<<mat[next_x][next_y] << endl;
				// cout << "VISIT : " << visit[next_x][next_y] << endl;
				if(mat[next_y][next_x] == 1 && visit[next_y][next_x] == 0)
				{
					// cout << next_x<<"|" <<next_y<< endl;
					que.push(make_pair(next_y, next_x));
					visit[next_y][next_x] = visit[node.first][node.second] + 1;
				}
			}
		}
		cout << "?" << endl;
	}
	
	cout <<"Value : "<< visit[N-1][M-1] << endl;
	// printmat(mat, N,M);
	// for(int i = 0; i < N; i++)
	// {
	// 	for(int j = 0; j < M; j++)
	// 	{
	// 		cin >> mat[N][M];
	// 	}
	// }
	// cout << sizeof mat[0]/ sizeof mat;
	// cout << mat[3][1];
	// printmat(mat,  sizeof mat/sizeof mat[0],  sizeof mat[0]/sizeof mat[0][0]);

	return 0;
}