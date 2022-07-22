#include <iostream>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<pair<int, int>>> info)
{
	int score[m] = {0, };
	int result = 0;
	for(vector<pair<int, int>> v : info)
	{
		int minY = v[0].second;
		int maxY = v[1].second;
		for(int y = minY; y <= maxY; y++)
			result = max(result, ++score[y]);
		
	}

	return result;
}
int main()
{
	int m = 10, n = 10;
	vector<vector<pair<int, int>>> info
		= {{{0, 0}, {3, 0}}, {{0, 1}, {1, 3}}, {{3, 3},{5, 5}}, {{1, 5}, {3, 6}}, {{0, 9}, {3, 9}}, {{5, 1}, {5, 8}}};
	cout << solution(m, n, info);
	return 0;
}