//#1089
#include <iostream>
#include <cstring>
#include <deque>
#include <cmath>
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;
double result = 0;
int N, count = 0;
string input_window[5];
deque<int> board[10];
char windowSet[10][5][3];
char exampleSet[10][5][3];
string example_str[5] =
{
	{"###...#.###.###.#.#.###.###.###.###.###"},
	{"#.#...#...#...#.#.#.#...#.....#.#.#.#.#"},
	{"#.#...#.###.###.###.###.###...#.###.###"},
	{"#.#...#.#.....#...#...#.#.#...#.#.#...#"},
	{"###...#.###.###...#.###.###...#.###.###"}
};

void Input()
{
	FOR(i, 5)
		cin >> input_window[i];
}

void Init()
{
	int floor = 0, idx = 0;
	while(floor - 1 <= 4 * N - 1){
		FOR(i, 5)
		{
			for(int j = 0; j < 3; j++)
				windowSet[idx][i][j] = input_window[i][j+floor];	
		}

		idx++;
		floor += 4;
	}
	floor = 0, idx = 0;
	while(idx < 10){
		FOR(i, 5)
		{
			for(int j = 0; j < 3; j++)
				exampleSet[idx][i][j] = example_str[i][j+floor];	
		}

		idx++;
		floor += 4;
	}
}
void Recursion(int dep, int sum)
{
	if(dep == N)
	{
		result += sum;
		count++;
		return;
	}
	FOR(idx, board[dep].size())
	{
		sum += board[dep][idx] * pow(10, N - dep -1);
		Recursion(dep + 1, sum);
		sum -= board[dep][idx] * pow(10, N - dep -1);
	}
}
bool Caculate()
{
    int cipher = 1;
	for (int i = N - 1; i >= 0; i--) {    // 평균값 계산
        int sum = 0;
        int size = board[i].size();
        if(!size) return false;
        while (!board[i].empty()) {
            sum += board[i].front();
            board[i].pop_front();
        }
        result += double(sum) / double(size) * double(cipher);   // 각 자리수마다 평균을 구해서 더해줌
        cipher = cipher * 10;
    }
    return true;
}
void Solution()
{
	FOR(idx, N)
	{
		int sum = 0;
		FOR(floor, 10)
		{
			bool flag = true;
			FOR(i, 5)
			{
				FOR(j, 3)
				{
					if(windowSet[idx][i][j] == '.') continue;
					if(windowSet[idx][i][j] != exampleSet[floor][i][j]){
						flag = false;
						break;
					}
				}if(!flag) break;
			}
			if(flag){
				count++;
				board[idx].push_back(floor);
			}

		}
	}
	// Caculate();
	// Recursion(0, 0);
}

void print()
{
	cout << "========EXEAMPE========" << endl;
	FOR(k, 10)
	{
		FOR(i, 5)
		{
			FOR(j, 3)
			{
				cout << exampleSet[k][i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << "=========INPUT=========" << endl;
	FOR(k, N)
	{
		FOR(i, 5)
		{
			FOR(j, 3)
			{
				cout << windowSet[k][i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}
int main()
{
	cin >> N;
	Input();
	Init();
	// print();

	Solution();

	if(!count || !Caculate()) cout << -1 << endl;
	else printf("%.9lf\n", (double)result);

	return 0;
}

// 9
// ###...#.###.###.#.#.###.###.###.###
// #.#...#...#...#.#.#.#...#.....#.#.#
// #.#...#.###.###.###.###.###...#.###
// #.#...#.#.....#...#...#.#.#...#.#.#
// ###...#.###.###...#.###.###...#.###

// ###...#.###.###.#.#.###.###.###.###.###
// #.#...#...#...#.#.#.#...#.....#.#.#.#.#
// #.#...#.###.###.###.###.###...#.###.###
// #.#...#.#.....#...#...#.#.#...#.#.#...#
// ###...#.###.###...#.###.###...#.###.###

// 9
// ..#.###.###.#.#.###.###.###.###.###
// ..#...#...#.#.#.#...#....##.#.#.#.#
// ..#.###.###.###.###.###...#.###.###
// ..#.#.....#...#...#.#.#...#.#.#...#
// ..#.###.###...#.###.###..##.###...#