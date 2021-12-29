// #1405
// @Reference jaimemin <https://jaimemin.tistory.com/724>

#include<iostream>
#include<iomanip>

#define MAX 30
using namespace std;

int N, visited[MAX][MAX];
double result, mok, ans;
int dxdy[4][3] = {{0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};


struct data
{
	int x, y;
	double cost;
	data(int a, int b, double c)
	{
		x = a;
		y = b;
		cost = c;
	}
};
// void bfs(data d)
// {
// 	int x, y, cost;
// 	int dx,dy;
// 	queue<data> Que;
// 	Que.push(data(d.x, d.y, d.cost));
// 	visited[d.x][d.y] = 1;

// 	while(!Que.empty())
// 	{
// 		x = Que.front().x;
// 		y = Que.front().y;
// 		cost = Que.front().cost;
// 		Que.pop();

// 		for(int i = 0; i < 4; i++)
// 		{
// 			if(dxdy[i][2]){
// 				dx = x + dxdy[i][0];
// 				dy = y + dxdy[i][1];
				
// 				if(dx < 0 || dx >= MAX || dy < 0 || dy >= MAX || cost >= N) continue;
// 				if(visited[dx][dy]) ans++;
// 				cout << ">" <<cost << endl;

// 				Que.push(data(dx,dy,cost+1));
// 				visited[dx][dy] = 1;
// 			}
// 		}
// 	}
// }

void dfs(data d)
{

    if (N == 0)
    {
        result += d.cost;
        return;
	}

    visited[d.x][d.y] = true; 
    for (int i = 0; i < 4; i++)
    {
        int dx = d.x + dxdy[i][0];
        int dy = d.y + dxdy[i][1];

        if (!visited[dx][dy])
        {
            N -= 1;
            dfs(data(dx, dy, d.cost * dxdy[i][2] * 0.01));
            N += 1;
            visited[dx][dy] = false; 
        }
    }
}


	// if(visited[d.x][d.y]) ans++;

	// for(int i = 0; i < 4; i++)
	// {
	// 	if(dxdy[i][2])
	// 	{
	// 		dx = d.x + dxdy[i][0];
	// 		dy = d.y + dxdy[i][1];
	// 		cost = d.cost;
	// 		if(dx >= 0 && dx < MAX && dy >= 0 && dy < MAX && cost < N)
	// 		{
	// 			if(visited[dx][dy]) { cout << "DX : " << dx << "DY : " << dy << endl;ans++;}
	// 			dfs(data(dx,dy,cost+1));
	// 		}
	// 	}
	// 


int main()
{
	cin >> N;
	int n = 0;
	for(int i = 0; i < 4; i++){
		cin >> dxdy[i][2];
	}
	dfs(data(15, 15, 1.0));
	// bfs(data(14, 14, 0));

	// result = ans / mok;
	// cout << "ANSWER : " << 1.0 - result << endl; 
	// cout << "ANSWER2 : " << 1.0 - ans/pow(n, N) << endl;
	cout << fixed;
    cout << setprecision(10) << result << "\n";
	// cout << "ANS : " << ans << " MOK : " << pow(n,N) << endl;
	return 0;
}