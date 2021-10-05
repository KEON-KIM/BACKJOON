#include <vector>
#include <string>
#include <iostream>

using namespace std;

int solution()
{
	cout << "hi";
	return 0;
}

void print_MAT(vector<vector<int>> &mat)
{
	for(vector<int> temp : mat)
	{
		cout << "|";
		for(int size : temp)
		{
			cout << size << "|";
		}
		cout << endl;
	}
}

vector<vector<int>> MakeSharkStat(vector<vector<int>> &sea, int M)
{
	vector<vector<int>> sharkStat;
	int r,c,s,d,z;
	for(int i = 0; i < M; i++)
	{
		vector<int> Stat(5);
		cin >> r >> c >> s >> d >> z;
		Stat[0] = r;
		Stat[1] = c;
		Stat[2] = s;
		Stat[3] = d;
		Stat[4] = z;

		sea[r-1][c-1] = z;
		sharkStat.push_back(Stat);
	}
	return sharkStat;
}

vector<vector<int>> MakeSea(int R, int C)
{
	vector<int> row(C,0);
	vector<vector<int>> col;
	for(int i = 0; i < R; i++)
		col.push_back(row);
	
	return col;
}
void MoveTodest(vector<vector<int>> &Sea)
{
	int r,c,s,d,z;
	for(int i = 0; i < sharkStat.size(); i++)
	{
		r = sharkStat[i][0];
		c = sharkStat[i][1];
		s = sharkStat[i][2];
		d = sharkStat[i][3];
		z = sharkStat[i][4];

		Sea[r-1][c-1] = 0;

		if(d == 1)  
			if(r - s <= 0)
				r = s / Sea.size()-1 
			else 
				r -= s;
		
		else if (d == 2)
		{

		}
		else if (d == 3)
		{

		}
		else if (d == 4)
		{

		}
	}
}
int main()
{
	int R,C,M;
	cin >> R >> C >> M;
	vector<vector<int>> Sea;
	vector<vector<int>> sharkStat;

	int answer = 0;

	Sea = MakeSea(R,C);
	cout <<"hi";
	sharkStat = MakeSharkStat(Sea, M);


	print_MAT(Sea);

	for (int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			if(Sea[i][j] != 0) answer += Sea[i][j];
		}
	}

	cout << answer;
    return 0;
}